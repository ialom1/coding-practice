#include <stdio.h>
#include <iostream>

using namespace std;

#define R 4
#define C 4

void printInSpiral(int arr[R][C]){
  int sR = 0, eR = R;
  int sC = 0, eC = C, i;
  while (sR < eR && sC < eC) {
    for(i = sC; i < eC; i++)
      std::cout << arr[sR][i] << ' ';
    ++sR;
    for(i = sR; i < eR; i++)
      std::cout << arr[i][eC-1] << ' ';
    --eC;

    if(sR < eR){
      for(i = eC - 1; i >= sC; i--)
        std::cout << arr[eR-1][i] << ' ';
      --eR;
    }
    if(sC < eC){
      for(i = eR - 1; i >= sR; i--)
        std::cout << arr[i][sC] << ' ';
      ++sC;
    }
  }
}

int main(){
  int arr[R][C] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
    { 13, 14, 15, 16 }
  };
  printInSpiral(arr);
  return 0;
}
