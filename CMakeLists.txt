cmake_minimum_required(VERSION 3.2)

### Setup Project ###
project(sdfw CXX)


### Setup C++ ###
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


### Drawing server output directory ###
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


### Compiler settings ###
if(MSVC)
    if(CMAKE_CXX_FLAGS MATCHES "/w[0-4]")
        string(REGEX REPLACE "/w[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-variable")
endif()


### Create Target "sdfw" ###
include_directories(${PROJECT_SOURCE_DIR}/include/)
file(GLOB SDFW_FILE source/*.cpp source/*.hpp include/*.h*)
set(SDFW_SRC ${SDFW_FILE})
add_library(sdfw STATIC ${SDFW_SRC})
if (WIN32)
    target_link_libraries(sdfw ws2_32)
elseif(UNIX)
    find_package(Threads REQUIRED)
    target_link_libraries(sdfw Threads::Threads)
endif()


### Create Target "SampleLineToCursor" ###
set(SAMPLE_LINE_TO_CURSOR_SRC
    sample/source/Sample_LineToCursor.cpp
)
add_executable(Sample_LineToCursor ${SAMPLE_LINE_TO_CURSOR_SRC})
target_link_libraries(Sample_LineToCursor sdfw)


### Create Target "SampleFlower" ###
set(SAMPLE_PAINT_SRC
    sample/source/Sample_Paint.cpp
)
add_executable(Sample_Paint ${SAMPLE_PAINT_SRC})
target_link_libraries(Sample_Paint sdfw)


### Create Target "SamplePingPong" ###
set(SAMPLE_PINGPONG_SRC
    sample/source/Sample_PingPong.cpp
)
add_executable(Sample_PingPong ${SAMPLE_PINGPONG_SRC})
target_link_libraries(Sample_PingPong sdfw)


### Copy asset to build directory ###
file(GLOB RESOURCE_FILES ${PROJECT_SOURCE_DIR}/sample/Resource/sample_01.mp3)
add_custom_command(
    TARGET Sample_PingPong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${RESOURCE_FILES} ${CMAKE_BINARY_DIR}
)


### Setup startup project ###
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Sample_PingPong)
