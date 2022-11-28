cmake_minimum_required(VERSION 3.23)
project(Forge)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(FORGE_BUILD_DLL)

# Set build configuration specific settings
message("Building in '${CMAKE_BUILD_TYPE}' configuration")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(FORGE_RELEASE)

elseif(CMAKE_BUILD_TYPE STREQUAL "Distribution")
    add_compile_definitions(FORGE_DISTRIBUTION)
endif()

# Set platform specific settings
if(WIN32 OR MSVC OR MSYS OR MINGW)
    add_compile_definitions(FORGE_PLATFORM_WINDOWS)
    set(FORGE_PLATFORM WINDOWS)

elseif(UNIX AND NOT APPLE)
    add_compile_definitions(FORGE_PLATFORM_LINUX)
    set(FORGE_PLATFORM LINUX)

elseif(APPLE)
    add_compile_definitions(FORGE_PLATFORM_APPLE)
    set(FORGE_PLATFORM APPLE)
endif()
message("Set parameters for platform '${FORGE_PLATFORM}'")

# Set sources variable
set(SOURCES
        src/forge.h
        src/Forge/application.cpp
        src/Forge/application.h
        src/Forge/core.h
        src/Forge/entrypoint.h
        src/Forge/event.cpp
        src/Forge/event.h
        src/Forge/input.cpp
        src/Forge/input.h
        src/Forge/logger.cpp
        src/Forge/logger.h
        src/Forge/events/window_events.cpp
        src/Forge/events/window_events.h
)

# Add shared forge library
add_library(Forge SHARED ${SOURCES})

# Add precompiled headers
target_precompile_headers(Forge PUBLIC src/forgepch.h)

# Add subdirectories
add_subdirectory(libraries/glfw)
add_subdirectory(libraries/spdlog)

# Include libraries
include_directories(libraries/glfw/include)
include_directories(libraries/spdlog/include)

# Link libraries
target_link_libraries(Forge glfw ${GLFW_LIBRARIES})
target_link_libraries(Forge spdlog)