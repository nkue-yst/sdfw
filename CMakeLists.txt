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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()


### Create Target "sdfw" ###
include_directories(${PROJECT_SOURCE_DIR}/include/)
set(SDFW_SRC
    include/sdfw.h
    include/sdfwComponent.hpp
    include/sdfwEngine.hpp
    include/sdfwSocket.hpp
    source/sdfw.cpp
    source/sdfwEngine.cpp
    source/sdfwSocket.cpp
)
add_library(sdfw STATIC ${SDFW_SRC})
if (WIN32)
    target_link_libraries(sdfw ws2_32)
endif()


### Create Target "Sample" ###
set(SAMPLE_SRC
    sample/source/Main.cpp
)
add_executable(Sample ${SAMPLE_SRC})
target_link_libraries(Sample sdfw)


### Setup startup project ###
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Sample)
