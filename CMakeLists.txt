cmake_minimum_required(VERSION 3.2.0)
project(TRACKING-ITSU C CXX)

include(CheckIncludeFileCXX)

set(TRACKINGITSU_TARGET_DEVICE CPU CACHE STRING "Target device where code must be run. Options are: CPU (default), GPU_CUDA, OPEN_CL")
set_property(CACHE TRACKINGITSU_TARGET_DEVICE PROPERTY STRINGS CPU GPU_CUDA OPEN_CL)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -O0")
set(CMAKE_CXX_FLAGS_PROFILE "-pg" CACHE STRING "Flags used by the C++ compiler during profiling builds.")
set(CMAKE_CXX_FLAGS_MEMORYBENCHMARK "-DMEMORY_BENCHMARK" CACHE STRING "Flags used by the C++ compiler during memory benchmark builds.")
set(CMAKE_CXX_FLAGS_TIMEBENCHMARK "-DTIME_BENCHMARK" CACHE STRING "Flags used by the C++ compiler during time benchmark builds.")

MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_PROFILE)
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_MEMORYBENCHMARK)
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_TIMEBENCHMARK)

message(">> Compiling for OPENCL enabled devices")
add_definitions(-DTRACKINGITSU_OPEN_CL_COMPILE)

find_package( OpenCL REQUIRED )
include_directories( ${OPENCL_INCLUDE_DIRS} ${TRACKING-ITSU_SOURCE_DIR}/include ${TRACKING-ITSU_SOURCE_DIR}/src ${TRACKING-ITSU_SOURCE_DIR}/kernel)

add_subdirectory(src)

add_executable(tracking-itsu-main main.cpp)

target_link_libraries(tracking-itsu-main src ${OpenCL_LIBRARIES})
#target_link_libraries( tracking-itsu-main ${OPENCL_LIBRARIES} )
