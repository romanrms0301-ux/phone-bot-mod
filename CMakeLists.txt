cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(phone-bot-mod VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED src/main.cpp)

include(FetchContent)
if (NOT DEFINED ENV{GEODE_SDK})
  FetchContent_Declare(
    GeodeSDK
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v4.6.1
  )
  FetchContent_MakeAvailable(GeodeSDK)
  set(GEODE_SDK_PATH ${geodesdk_SOURCE_DIR})
else()
  set(GEODE_SDK_PATH $ENV{GEODE_SDK})
endif()

add_subdirectory(${GEODE_SDK_PATH} ${CMAKE_CURRENT_BINARY_DIR}/geode)
setup_geode_mod(${PROJECT_NAME})
