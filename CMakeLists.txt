cmake_minimum_required( VERSION 3.23.2 )

project( SpeedDemon )

list( APPEND CMAKE_PREFIX_PATH "P:\\coding_install" )

find_package( SFML COMPONENTS graphics system REQUIRED )

add_subdirectory( src )

install(TARGETS ${PROJECT_NAME}App DESTINATION bin/)