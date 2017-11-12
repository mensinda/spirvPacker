# Automatically generated file; DO NOT EDIT

project( tests )

set( TESTS_SRC

   ${CMAKE_CURRENT_SOURCE_DIR}/config/config.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set( TESTS_INC

)

add_executable( tests ${TESTS_SRC} ${} )
target_link_libraries( tests spirvPacker )

set_target_properties(
 tests
 PROPERTIES
  INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib
  INSTALL_RPATH_USE_LINK_PATH TRUE
)

install(
  TARGETS tests
  EXPORT  spirvPackerTargets
  RUNTIME DESTINATION bin
)
