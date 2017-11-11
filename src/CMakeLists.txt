# Automatically generated file; DO NOT EDIT

project( spirvPackerTool )

set( SPIRVPACKERTOOL_SRC

   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set( SPIRVPACKERTOOL_INC

)

add_executable( spirvPackerTool ${SPIRVPACKERTOOL_SRC} ${} )
target_link_libraries( spirvPackerTool spirvPacker )

set_target_properties(
 spirvPackerTool
 PROPERTIES
  INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib
  INSTALL_RPATH_USE_LINK_PATH TRUE
)

install(
  TARGETS spirvPackerTool
  EXPORT  spirvPackerTargets
  RUNTIME DESTINATION bin
)
