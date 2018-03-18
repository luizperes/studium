#################################################################
#  Copyright (c) 2018 Lucas Vieira <lucasvieira@protonmail.com> #
#                                                               #
#  This file is distributed under the MIT License. See LICENSE  #
#  for more information.                                        #
#################################################################

cmake_minimum_required(VERSION 2.8)

project(StudiumEngine)

# Determine version string
set(ENGINE_VERSION_MAJOR    0)
set(ENGINE_VERSION_MINOR    1)
set(ENGINE_VERSION_REVISION 0)
string(TIMESTAMP ENGINE_VERSION
  "${ENGINE_VERSION_MAJOR}.${ENGINE_VERSION_MINOR}.${ENGINE_VERSION_REVISION}")

# Default project definitions
add_definitions(-DSTUDIUM_VERSION_STRING=${ENGINE_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")


# Project dependencies
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(GLM REQUIRED glm>=0.9.8)
PKG_SEARCH_MODULE(EPOXY REQUIRED epoxy>=1.4.3)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

# Optional dependencies
find_package(Chicken 4.12 OPTIONAL_COMPONENTS)


# Default engine lib definitions
set(ENGINE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(ENGINE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

aux_source_directory(${ENGINE_SOURCE_DIR} ENGINE_SOURCES)


# Test executable definitions
set(TEST_SOURCE_DIR "${CMAKE_SOURCE_DIR}/test/src")
set(TEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/test/include")

aux_source_directory(${TEST_SOURCE_DIR} TEST_SOURCES)


# Final targets
add_library(studium ${ENGINE_SOURCES})
add_executable(engine_test ${TEST_SOURCES})


# Final linking and including
target_include_directories(studium PUBLIC
  ${ENGINE_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR})

target_include_directories(engine_test PUBLIC
  ${TEST_INCLUDE_DIR}
  ${ENGINE_INCLUDE_DIR})

target_link_libraries(engine_test
  ${OPENGL_gl_LIBRARY}
  ${EPOXY_LIBRARIES}
  glfw
  studium)

# Link Chicken Scheme
IF(CHICKEN_INCLUDE_DIRS)
  add_definitions(-DSTUDIUM_SCRIPTING)
  target_link_libraries(engine_test chicken)
  target_include_directories(studium PUBLIC ${CHICKEN_INCLUDE_DIRS})
ENDIF()





# Installation

# Header files
INSTALL(DIRECTORY ${ENGINE_INCLUDE_DIR}
  DESTINATION include
  FILES_MATCHING PATTERN "*.hpp")

# Library files
INSTALL(TARGETS studium
  ARCHIVE DESTINATION lib)

# Binaries
#INSTALL(TARGETS engine_test
#  RUNTIME DESTINATION bin)
