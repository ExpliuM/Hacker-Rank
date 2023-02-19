cmake_minimum_required(VERSION 3.25)

# set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 11)
list(APPEND CPP11_PROJECTS
    abstract-classes-polymorphism
    balanced-brackets
    c-tutorial-conditional-if-else
    c-tutorial-for-loop
    c-tutorial-functions
    caesar-cipher-1
    countingsort1
    diagonal-difference
    find-the-meidian
    fliping-matrix
    grid-challenge
    lonely-integer
    merge-two-sorted-linked-lists
    mini-max-sum
    new-year-chaos
    plus-minus
    queue-using-two-stacks
    recursive-digit-sum
    simple-text-editor
    time-conversion
    tower-breakers-1
    zig-zag-sequence
    )
    
foreach(proj ${CPP11_PROJECTS})
    project(${proj})
    message("building project ${proj}")
    add_executable(${proj} ${proj}/${proj}.cpp)
    target_link_libraries(${proj})
endforeach()

set(CMAKE_CXX_STANDARD 17)
list(APPEND CPP17_PROJECTS
    c-tutorial-basic-data-types
    )
foreach(proj ${CPP17_PROJECTS})
    project(${proj})
    message("building project ${proj}")
    add_executable(${proj} ${proj}/${proj}.cpp)
    target_link_libraries(${proj})
endforeach()

# Tests
project(tests)
enable_language(C CXX)

find_package(GTest REQUIRED)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE TEST_FILES "*.cc")
list(FILTER TEST_FILES EXCLUDE REGEX "(build|\.history)")

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(tests ${TEST_FILES})
target_link_libraries(tests GTest::gtest_main)
# include(GoogleTest)
gtest_discover_tests(tests)