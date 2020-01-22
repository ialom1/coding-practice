#include <iostream>

using namespace std;

void _print(int ara[], int len){
  for(int i=0; i<len; i++)
  std::cout << ara[i] << ' ';
  std::cout << '\n';
}

void merge(int ara[], int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for(i=0; i<n1; i++){
    L[i] = ara[l+i];
  }
  for(j=0; j<n2; j++){
    R[j] = ara[m+j+1];
  }

  i=0, j=0, k=l;
  while (i<n1 && j<n2) {
    if(L[i] <= R[j]){
      ara[k++] = L[i++];
    }
    else {
      ara[k++] = R[j++];
    }
  }
  while(i<n1){
    ara[k++] = L[i++];
  }
  while(j<n2){
    ara[k++] = R[j++];
  }
}

void mergeSort(int ara[], int l, int r){
  if(l < r){
    int m = l+(r-l)/2;
    mergeSort(ara, l, m);
    mergeSort(ara, m+1, r);
    merge(ara, l, m, r);
  }
}

int main(){
  int arr[] = {12, 11, 13, 5, 6, 7};
  int len = sizeof(arr)/sizeof(arr[0]);

  printf("Given array is \n");
  _print(arr, len);

  mergeSort(arr, 0, len-1);

  printf("\nSorted array is \n");
  _print(arr, len);
  return 0;
}
