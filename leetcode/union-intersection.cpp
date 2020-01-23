#include <iostream>

using namespace std;

// (Use Sorting and Searching)
// Union:
// 1) Initialize union U as empty.
// 2) Find smaller of m and n and sort the smaller array.
// 3) Copy the smaller array to U.
// 4) For every element x of larger array, do following
// …….b) Binary Search x in smaller array. If x is not present, then copy it to U.
// 5) Return U.
//
// Intersection:
// 1) Initialize intersection I as empty.
// 2) Find smaller of m and n and sort the smaller array.
// 3) For every element x of larger array, do following
// …….b) Binary Search x in smaller array. If x is present, then copy it to I.
// 4) Return I.
