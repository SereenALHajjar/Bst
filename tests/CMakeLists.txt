

CPMAddPackage("gh:doctest/doctest#v2.4.11")


add_executable(bst_tests bst_tests.cpp)
target_link_libraries(bst_tests doctest bst)


# enable_testing()

# doctest_add_test(NAME bst_tests COMMAND bst_tests)