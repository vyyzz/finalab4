#ifndef _GEN_PERM_H_
#define _GEN_PERM_H_

#include "fisher_yates.h"
#include <cstdlib>

void compute_permutation_of_array(int arry[], int length);

int get_lowest_prefix_sum_value(int arry[], int length);

int index_of_lowest_prefix_sum_element(int arry[], int length);

void generate_well_formed_list(int arr[], int n); 

#endif // _GEN_PERM_H_
