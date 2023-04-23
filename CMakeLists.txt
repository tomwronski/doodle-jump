cmake_minimum_required(VERSION 3.22)

project(DoodleJump)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
        CACHE STRING
            "Choose the type of build (Debug or Release)"
            FORCE
    )
endif()

set(RESOURCE_PATH ${PROJECT_SOURCE_DIR}/assets)

# Generate config.h
configure_file(include/config.h.in config.h)

find_package(SFML 2.5
    COMPONENTS
        system window graphics REQUIRED
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} sfml-graphics)