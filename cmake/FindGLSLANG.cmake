# Try to find the Vulkan
# GLSLANG_PREFIX       - The install location of the engine
# GLSLANG_FOUND        - system has GLSLANG lib
# GLSLANG_INCLUDE_DIRS - the GLSLANG include directory
# GLSLANG_LIBRARIES    - Libraries needed to use GLSLANG

if (GLSLANG_INCLUDE_DIR AND GLSLANG_LIBRARIES)
                # Already in cache, be silent
                set(GLSLANG_FIND_QUIETLY TRUE)
endif (GLSLANG_INCLUDE_DIR AND GLSLANG_LIBRARIES)

find_path(
 GLSLANG_INCLUDE_DIR
 NAMES ShaderLang.h
 PATH_SUFFIXES
  glslang
  glslang/Public
 PATHS
  ${GLSLANG_PREFIX}/include
  ${CMAKE_INSTALL_PREFIX}/include
  /usr/include
  /usr/local/include
)

find_path(
 TO_SPIRV_INCLUDE_DIR
 NAMES SPIRV/GlslangToSpv.h
 PATHS
  ${GLSLANG_PREFIX}/include
  ${CMAKE_INSTALL_PREFIX}/include
  /usr/include
  /usr/local/include
)

foreach( I IN ITEMS HLSL OGLCompiler OSDependent SPIRV SPVRemapper glslang )
  find_library(
  ${I}_LIBRARY
    NAMES ${I}
    PATHS
      ${GLSLANG_PREFIX}/lib
      ${CMAKE_INSTALL_PREFIX}/lib
      /usr/lib
      /usr/local/lib
  )

  set( GLSLANG_LIBRARIES ${GLSLANG_LIBRARIES} ${${I}_LIBRARY} )
  set( LIB_VARS ${LIB_VARS} ${I}_LIBRARY )
endforeach()

set( GLSLANG_INCLUDE_DIRS ${GLSLANG_INCLUDE_DIR} ${TO_SPIRV_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLSLANG DEFAULT_MSG
  GLSLANG_INCLUDE_DIR TO_SPIRV_INCLUDE_DIR
  ${LIB_VARS})

mark_as_advanced(GLSLANG_INCLUDE_DIR TO_SPIRV_INCLUDE_DIR ${LIB_VARS})
