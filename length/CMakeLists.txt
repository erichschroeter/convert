cmake_minimum_required(VERSION 2.6)
project(convert-length)

# The version number
set (convert-length_VERSION_MAJOR_1)
set (convert-length_VERSION_MINOR_0)

find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories("${PROJECT_SOURCE_DIR}/units")
link_directories("${PROJECT_SOURCE_DIR}/units")
# add all direct subdirectories
add_subdirectory(units)

# add the executable
add_executable(convert-length convert-length.cpp)

#target_link_libraries(convert-length ${Boost_LIBRARIES} Meter Inch)
target_link_libraries(convert-length ${Boost_LIBRARIES} Length)
