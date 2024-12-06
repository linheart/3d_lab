cmake_minimum_required(VERSION 3.30)
project(DataStructures)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if (ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

set(SRC_FILES
    src/arr.h
    src/hash_table.h
    src/list.h
    src/queue.h
    src/stack.h
    src/timer.h
    src/tree.h
)

set(TEST_FILES
  tests/test_arr.cpp
  tests/test_hash_table.cpp
  tests/test_list.cpp
  tests/test_queue.cpp
  tests/test_stack.cpp
  tests/test_tree.cpp
)

add_executable(tests
    ${TEST_FILES}
    ${SRC_FILES}
)

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

if (ENABLE_COVERAGE)
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E remove -f coverage.info
        COMMAND lcov --capture --directory . --output-file coverage.info --rc geninfo_unexecuted_blocks=1 --ignore-errors mismatch
        COMMAND genhtml coverage.info --output-directory coverage_html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
add_test(NAME RunTests COMMAND tests)
