# Automatically generated file; DO NOT EDIT

project( spirvPacker )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

set( SPIRVPACKER_SRC

   ${CMAKE_CURRENT_SOURCE_DIR}/ShaderModule.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SpirvPacker.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/compiler/CompilerBase.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/CommandLineParser.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/Config.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/ConfigPrinter.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/ConfigVisitor.cpp
)

set( SPIRVPACKER_INC

   ${CMAKE_CURRENT_SOURCE_DIR}/ShaderModule.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SpirvPacker.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/compiler/CompilerBase.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/CommandLineParser.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/StringHash.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/Config.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/ConfigPrinter.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/config/ConfigVisitor.hpp
)


set( SPIRVPACKER_INC ${SPIRVPACKER_INC} ${EXPORT_FILE} )

set( CURRENT_LIB_TARGETS )

if(BUILD_STATIC_LIBS)
  set( CURRENT_LIB_TARGETS spirvPacker spirvPacker_static )
  add_library( spirvPacker_obj    OBJECT ${SPIRVPACKER_SRC} ${SPIRVPACKER_INC} )
  add_library( spirvPacker        SHARED $<TARGET_OBJECTS:spirvPacker_obj> )
  add_library( spirvPacker_static STATIC $<TARGET_OBJECTS:spirvPacker_obj> )
else()
  set( CURRENT_LIB_TARGETS spirvPacker )
  add_library( spirvPacker        SHARED ${SPIRVPACKER_SRC} ${SPIRVPACKER_INC} )
endif()

foreach( I IN LISTS CURRENT_LIB_TARGETS )
  target_link_libraries( ${I}  )
endforeach()

set_target_properties(
  ${CURRENT_LIB_TARGETS}
  PROPERTIES
    VERSION        0.0.1
    SOVERSION      0
    PUBLIC_HEADER  "${SPIRVPACKER_INC}"
    OUTPUT_NAME    "spirvPacker"
)

install(
  TARGETS       ${CURRENT_LIB_TARGETS}
  EXPORT        spirvPackerTargets
  RUNTIME       DESTINATION bin
  LIBRARY       DESTINATION lib/spirvPacker
  ARCHIVE       DESTINATION lib/spirvPacker
  PUBLIC_HEADER DESTINATION include/spirvPacker
)
