cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

project(luxoft-race)

FILE(GLOB HEADER_FILES RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
  )

FILE(GLOB SOURCE_FILES RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
  )

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

if (WIN32 AND NOT APPLE)
  target_link_libraries(${PROJECT_NAME} -static)
elseif(UNIX AND NOT APPLE)
  target_link_libraries(${PROJECT_NAME} pthread)
endif ()
