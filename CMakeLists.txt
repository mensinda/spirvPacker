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
option( USE_LIBCXX           "Use libc++ instead of libstdc++" OFF )
option( ENABLE_CODE_COVERAGE "Enables code coverage tests"     OFF )

if( USE_LIBCXX )
  set( CXX_STDLIB_FLAGS "-stdlib=libc++" ) #  -lc++abi
else()
  set( CXX_STDLIB_FLAGS "" )
endif()

run_git()

################################
# Set up the build environment #
################################

if( ENABLE_CODE_COVERAGE )
  set( COVERAGE_COMPILER_FLAG "--coverage" )
else()
  set( COVERAGE_COMPILER_FLAG "" )
endif()

add_compiler( GNU MIN_VERSION "5.3"
              ALL      "-Wall -Wextra -Wno-comment -Wfloat-equal -Wshadow -Wno-unknown-pragmas -fdiagnostics-color=always"
                       "${COVERAGE_COMPILER_FLAG} ${CXX_STDLIB_FLAGS}"
              DEBUG    "-O0 -Werror"
              SANITIZE "-fsanitize=${SANITIZERS}"
              RELEASE  "-O3" )

add_compiler( Clang
              ALL      "-Weverything -ftemplate-backtrace-limit=0 -fcolor-diagnostics ${CXX_STDLIB_FLAGS}"
                       "-Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-float-equal"
                       "-Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-exit-time-destructors"
                       "-Wno-global-constructors -Wno-switch-enum -Wno-reserved-id-macro"
                       "-Wno-documentation-unknown-command -Wno-unused-macros -Wno-weak-vtables"
                       "-Wno-double-promotion -Wno-undefined-func-template"
              DEBUG    "-Werror"
              SANITIZE "-fsanitize=${SANITIZERS}"
              RELEASE  "-O2" )

##################
# Config Project #
##################

new_project_library(
  PATH         "${PROJECT_SOURCE_DIR}/lib"
  NAME         "${PROJECT_NAME}"
  TEMPLATE     "${TEMPLATES_DIR}/CMakeLists.lib.in"
  DEPENDENCIES
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
  ${PROJECT_SOURCE_DIR}/external/catch
)

# Add all libs and tests directories
foreach( I IN LISTS ${PROJECT_NAME}_SUBDIR_LIST )
  add_subdirectory( "${I}" )
endforeach()

##################
# Generate Files #
##################

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
