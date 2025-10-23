# CS-210-8-1-journal

This project provides a very simple simulation of interest earned on certificates of deposit. A user is able to run as many simulations as they desire.

# Strengths
Separation of concerns (input vs. calculation vs. data), input validation, and the use of modern C++ features for clean output.

Naming throughout seems to be done well.

The design makes it easily extensible.

# Improvements
Adding range validation for inputs (currently there is no logical check on what numbers are input, e.g. negative numbers which lead to nonsensical results).

The program currently calculates results every time they are displayed; this made sense for an initial iteration that only displays a given set of inputs one time, but it is not a good longer term solution.

Monetary values shouldn't be stored as `double` due to precision errors; only upon displaying the final result should a calculation be done to convert a large integer representation to the customary floating point representation.

# Requirements
**C++23**

**CMake >= 4.1**

# Getting Started
```shell
mkdir build
cd build/

cmake ..
cmake --build .

./deposit_simulator
