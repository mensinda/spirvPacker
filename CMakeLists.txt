cmake_minimum_required(VERSION 3.8)
project(spirvPacker)

message( STATUS "Using CMake version: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}\n" )

include( CMakePackageConfigHelpers )
include( cmake/cmakeBuildTools/cmakeBuildTools.cmake )

######################
# Set some variables #
######################

# Set the binary output directories
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

set( TEMPLATES_DIR ${PROJECT_SOURCE_DIR}/cmake/templates )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

set( CMAKE_CXX_STANDARD               17 )
set( CMAKE_CXX_STANDARD_REQUIRED      ON )
set( CMAKE_C_STANDARD                 11 )
set( CMAKE_C_STANDARD_REQUIRED        ON )
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

option( BUILD_STATIC_LIBS    "Enable building static libs"     OFF )
option( ENABLE_CODE_COVERAGE "Enables code coverage tests"     OFF )

run_git()

################################
# Set up the build environment #
################################

if( ENABLE_CODE_COVERAGE )
  set( COVERAGE_COMPILER_FLAG "--coverage" )
else()
  set( COVERAGE_COMPILER_FLAG "" )
endif()

add_compiler( GNU MIN_VERSION "7.0"
              ALL      "-Wall -Wextra -Wno-comment -Wfloat-equal -Wshadow -Wno-unknown-pragmas -fdiagnostics-color=always"
                       "${COVERAGE_COMPILER_FLAG}"
              DEBUG    "-O0 -Werror"
              SANITIZE "-fsanitize=${SANITIZERS}"
              RELEASE  "-O3" )

add_compiler( Clang MIN_VERSION "5.0"
              ALL      "-Weverything -ftemplate-backtrace-limit=0 -fcolor-diagnostics"
                       "-Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-float-equal"
                       "-Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-exit-time-destructors"
                       "-Wno-global-constructors -Wno-switch-enum -Wno-reserved-id-macro"
                       "-Wno-documentation-unknown-command -Wno-unused-macros -Wno-weak-vtables"
                       "-Wno-double-promotion -Wno-undefined-func-template"
                       "-isystem ${PROJECT_SOURCE_DIR}/external/variant"
              DEBUG    "-Werror"
              SANITIZE "-fsanitize=${SANITIZERS}"
              RELEASE  "-O2" )

find_package( Threads REQUIRED )
find_package( GLSLANG REQUIRED )

##################
# Config Project #
##################

# Generate dummy files
file( WRITE "${PROJECT_SOURCE_DIR}/lib/utils/Enum2Str.hpp" "" )
file( WRITE "${PROJECT_SOURCE_DIR}/lib/utils/Enum2Str.cpp" "" )

new_project_library(
  PATH         "${PROJECT_SOURCE_DIR}/lib"
  NAME         "${PROJECT_NAME}"
  TEMPLATE     "${TEMPLATES_DIR}/CMakeLists.lib.in"
  DEPENDENCIES stdc++fs Threads::Threads ${GLSLANG_LIBRARIES}
)

new_project_executable(
  PATH         "${PROJECT_SOURCE_DIR}/src"
  NAME         "${PROJECT_NAME}Tool"
  TEMPLATE     "${TEMPLATES_DIR}/CMakeLists.exe.in"
  DEPENDENCIES ${PROJECT_NAME}
)

new_project_executable(
  PATH         "${PROJECT_SOURCE_DIR}/test"
  NAME         "tests"
  TEMPLATE     "${TEMPLATES_DIR}/CMakeLists.exe.in"
  DEPENDENCIES ${PROJECT_NAME}
)


include_directories(
  "${PROJECT_BINARY_DIR}"
  ${${PROJECT_NAME}_LIB_INCLUDE_DIRECTORIES}
  ${${PROJECT_NAME}_EXE_INCLUDE_DIRECTORIES}
)

include_directories( SYSTEM
  ${GLSLANG_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/external/catch
  ${PROJECT_SOURCE_DIR}/external/spdlog/include
  ${PROJECT_SOURCE_DIR}/external/spirv
)

# Add all libs and tests directories
foreach( I IN LISTS ${PROJECT_NAME}_SUBDIR_LIST )
  add_subdirectory( "${I}" )
endforeach()

##################
# Generate Files #
##################

set(
  SPIRV_ENUMS
    "SourceLanguage" "ExecutionModel" "AddressingModel" "MemoryModel" "ExecutionMode" "StorageClass" "Dim"
    "SamplerAddressingMode" "SamplerFilterMode" "ImageFormat" "ImageChannelOrder" "ImageChannelDataType"
    "ImageOperandsShift" "ImageOperandsMask" "FPFastMathModeShift" "FPFastMathModeMask" "FPRoundingMode" "LinkageType"
    "AccessQualifier" "FunctionParameterAttribute" "Decoration" "BuiltIn" "SelectionControlShift"
    "SelectionControlMask" "LoopControlShift" "LoopControlMask" "FunctionControlShift" "FunctionControlMask"
    "MemorySemanticsShift" "MemorySemanticsMask" "MemoryAccessShift" "MemoryAccessMask" "Scope" "GroupOperation"
    "KernelEnqueueFlags" "KernelProfilingInfoShift" "KernelProfilingInfoMask" "Capability" "Op"
)

set( SPIRV_ENUMS_NAMESPACE )

foreach( I IN LISTS SPIRV_ENUMS )
  set( SPIRV_ENUMS_NAMESPACE ${SPIRV_ENUMS_NAMESPACE} "spv::${I}" )
endforeach()

enum2str_generate(
  PATH "${PROJECT_SOURCE_DIR}/lib/utils"
  CLASS_NAME      "Enum2Str"
  NAMESPACE       "spirvPacker"
  FUNC_NAME       "toStr"
  INDENT_STR      "  "
  BITFIELD_TYPE   uint32_t
  CONCATINATE_STR " | "
#   ENABLE_BITFIELDS
  INCLUDES
    "spirv.hpp"
    "StageBase.hpp" "ShaderModule.hpp"
  ENUMS
    "StageType" "StageResult" "ShaderType" "SourceFormat"
    ${SPIRV_ENUMS_NAMESPACE}
)

install( EXPORT ${PROJECT_NAME}Targets DESTINATION lib/cmake/${PROJECT_NAME} )

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Version.cmake"
    VERSION       ${CM_VERSION_MAJOR}.${CM_VERSION_MINOR}.${CM_VERSION_SUBMINOR}
    COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Version.cmake
    ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake
  DESTINATION lib/cmake/${PROJECT_NAME}
)

configure_file( "${TEMPLATES_DIR}/spvCfg.in.hpp" "${PROJECT_BINARY_DIR}/spvCfg.hpp" @ONLY )
