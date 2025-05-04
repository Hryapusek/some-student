cmake_minimum_required(VERSION 3.11)
project(connect_json_lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(nlohmann_json)
add_executable(${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_sources(${CMAKE_PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/json/program_level_parcer_json.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}
  PRIVATE
    nlohmann_json::nlohmann_json
)
