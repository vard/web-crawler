# set projcet name
set(PROJECT_NAME_STR web_crawler)
project(${PROJECT_NAME_STR})
cmake_minimum_required(VERSION 2.8)

# collect all sources form directory
aux_source_directory(. SRC_LIST)

# set main project source list
# set(SRC_LIST concurrent_set.cpp main.cpp)

# set build type
set( CMAKE_BUILD_TYPE DEBUG )

# add produced executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# append compilation flags
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -Wall -ftest-coverage")

find_package(Boost COMPONENTS program_options-mt REQUIRED)
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find boost::program_options-mt.")
    return()
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

target_link_libraries(${PROJECT_NAME_STR}
                                ${Boost_LIBRARIES})

#
#
# LIBRARY FOR TESTING
#
#

set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_lib)
set(LIB_SRC_LIST ${SRC_LIST})
list(REMOVE_ITEM LIB_SRC_LIST "./main.cpp")
add_library(${PROJECT_LIB_NAME} SHARED ${LIB_SRC_LIST})

#
#
#    TEST
#
#

# gtest
set(GTEST_INCLUDE_DIR /Users/vard/lib/gtest/gtest-1.7.0/include)
set(GTEST_LIBS_DIR /Users/vard/lib/gtest/gtest-1.7.0/build)
include_directories(${GTEST_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR})


set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)

# generate list of files and store it in variable
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp ${PROJECT_SOURCE_DIR}/test/*.h)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME}
                      ${PROJECT_LIB_NAME}
                      #web_crawler_lib.a
                      ${GTEST_LIBS_DIR}/libgtest.a
                      ${GTEST_LIBS_DIR}/libgtest_main.a
)

# execute by 'make test'
enable_testing()
add_test(test1 ${PROJECT_TEST_NAME})

