cmake_minimum_required(VERSION 3.26)
project(The_tower_of_pain)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_COMPILER "C:/mingw64/bin/g++.exe")

set(SFML_DIR "./libraries/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("The build is in debug. A terminal will be shown to print information")
    add_executable(The_tower_of_pain
        src/main.cpp
        src/core/Game.cpp
    )
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message("The build is in Release. Only the GUI window will appears")
    add_executable(The_tower_of_pain 
        WIN32
        src/main.cpp
        src/core/Game.cpp
    )
else()
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

target_include_directories(The_tower_of_pain PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ./libraries/SFML-2.6.1/include/SFML
)

link_directories(./libraries/SFML-2.6.1/include/lib)

target_link_libraries(The_tower_of_pain PRIVATE
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network
    sfml-system
)

set_target_properties(The_tower_of_pain PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)