#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    long long col, row, i, j;
    std::cin >> col >> row;

    long long ara[row][col];

    for (i = 0; i < col; i++) {
      /* code */
      cin >> ara[0][i];
    }

    for (i = 1; i < row; i++) {
      /* code */
      for (j = 0; j < col; j++) {
        /* code */
        if(j == col-1)
          ara[i][j] = ara[i-1][j] ^ ara[i-1][0];
        else
          ara[i][j] = ara[i-1][j] ^ ara[i-1][j+1];
      }
    }

    for (i = 0; i < col; i++) {
      /* code */
      cout << ara[row-1][i] << " ";
    }
}
