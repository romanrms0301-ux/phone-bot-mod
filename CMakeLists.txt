cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    setset(CMAKE_OSX_ARCHITESTURES "arm64;x86_64")
else()
    set(CMAKE_OSX_ARCHITESTURES "arm64;x86_64")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(PhoneBot VERSION 1.0.0)

# Android NDK / Clang can choke on fmt's consteval FMT_STRING implementation
# in some Geode dependency versions. Disable the compile-time format-string mode
# so the transitive fmt dependency builds correctly on Android.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DFMT_USE_CONSTEXPR=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFMT_USE_CONSTEXPR=0")
add_compile_definitions(FMT_USE_CONSTEXPR=0)

# Add all source files inside src (recursively)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Ensure fmt gets the compatibility macro even when Geode vendors it as a target.
if (TARGET fmt)
    target_compile_definitions(fmt PRIVATE FMT_USE_CONSTEXPR=0)
endif()

# Set up dependencies, resources, and link Geode.
setup_geode_mod(${PROJECT_NAME})
