#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"
#include "gen_perm.h"
#include <climits>

TEST_CASE("index_of_lowest_prefix_sum_element") {
    SUBCASE("Empty array") {
        int arr[] = {};
        CHECK(index_of_lowest_prefix_sum_element(arr, 0) == -1); 
    }

    SUBCASE("Non-empty arrays") {
        int arr1[] = {1, -1, 1, -1};
        int arr2[] = {1, -1, -1, 1, -1, -1, -1, 1, 1};

        // Index of lowest prefix sum is 0 for arr1
        // Prefix sums: 1, 0, 1, 0
        CHECK(index_of_lowest_prefix_sum_element(arr1, sizeof(arr1) / sizeof(arr1[0])) == 3);

        // Index of lowest prefix sum is 0 for arr2
        // Prefix sums: 1, 0, -1, 0, -1, -2, -3, -2, -1
        CHECK(index_of_lowest_prefix_sum_element(arr2, sizeof(arr2) / sizeof(arr2[0])) == 6);
    }
}
