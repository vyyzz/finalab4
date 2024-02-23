# README

This repository contains three C++ source files:
1. `gen_perm.cpp`: Implements functions for generating permutations.
2. `unit_tests.cpp`: Contains unit tests for the functions implemented in `gen_perm.cpp` and `fisher_yates.cpp`.
3. `fisher_yates.cpp`: Implements the Fisher-Yates shuffle algorithm.

## Prerequisites

To compile and run the code, you need:
- A C++ compiler (e.g., g++)
- C++ Standard Library

## Compilation

You can compile the source files using the `g++` compiler.

```bash
g++ -std=c++11 gen_perm.cpp unit_tests.cpp fisher_yates.cpp -o test_executable
