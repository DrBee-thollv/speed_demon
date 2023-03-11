add_library( ${PROJECT_NAME}Lib STATIC UI/Text.cpp UI/Button.cpp Enemy.cpp GameInstance.cpp GameState.cpp Player.cpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../include )
target_include_directories( ${PROJECT_NAME}Lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include
                                                      $<INSTALL_INTERFACE:include/speed_demon )
target_link_libraries( ${PROJECT_NAME}Lib sfml-graphics sfml-system )
                                                      
add_executable( ${PROJECT_NAME}App main.cpp )
target_link_libraries( ${PROJECT_NAME}App ${PROJECT_NAME}Lib )