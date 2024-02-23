#include "prefix_sum.h"
#include "fisher_yates.h"
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

void compute_permutation_of_array(int arry[], int length) {
    for (int i = length - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = arry[i];
        arry[i] = arry[j];
        arry[j] = temp;
    }
}

int get_lowest_prefix_sum_value(int arry[], int length) {
    int min_sum = INT_MAX;
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arry[i];
        if (sum < min_sum) {
            min_sum = sum;
        }
    }
    return min_sum;
}

int index_of_lowest_prefix_sum_element(int arry[], int length) {
    int min_sum = INT_MAX;
    int sum = 0;
    int min_index = -1;
    for (int i = 0; i < length; ++i) {
        sum += arry[i];
        if (sum <= min_sum) {
            min_sum = sum;
            min_index = i;
        }
    }
    return min_index;
}

void generate_well_formed_list(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = 1;
    }
    arr[n] = -1;
    for (int i = n + 1; i < 2 * n + 1; ++i) {
        arr[i] = -1;
    }

    compute_permutation_of_array(arr, 2 * n + 1);

    int lowest_depth = get_lowest_prefix_sum_value(arr, 2 * n + 1);

    int index_of_first_lowest_ps = index_of_lowest_prefix_sum_element(arr, 2 * n + 1);

    int index_of_last_positive = index_of_first_lowest_ps;
    while (index_of_last_positive < 2 * n + 1 && arr[index_of_last_positive] != 1) {
        ++index_of_last_positive;
    }

    if (index_of_last_positive > 0) {
        arr[index_of_last_positive - 1] = 0;
    }

    int new_list[2 * n];
    for (int i = 0; i < 2 * n - index_of_last_positive + 1; ++i) {
        new_list[i] = arr[index_of_last_positive + i];
    }
    for (int i = 0; i < index_of_last_positive; ++i) {
        new_list[2 * n - index_of_last_positive + 1 + i] = arr[i];
    }

    cout << "Generated Well-Formed Symbol List: ";
    for (int i = 0; i < 2 * n; ++i) {
        cout << new_list[i] << " ";
    }
    cout << endl;
}

// int main() {
//     const int n = 3;
//     int arr[2 * n + 1];

//     generate_well_formed_list(arr, n);

//     return 0;
// }
