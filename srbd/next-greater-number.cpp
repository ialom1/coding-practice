#include <iostream>

using namespace std;

void swap(char &a, char &b){
  char temp = a;
  a = b;
  b = temp;
}

void findNextGreater(char nums[], int len){
  int i, j;
  for(i=len-1; i>0; i--){
    if(nums[i] > nums[i-1]) break;
  }
  if(i == 0){
    std::cout << "Not Possible" << '\n';
    return;
  }

  int x = nums[i-1], smallest = i;
  for(j=i+1; j<len; j++){
    if(nums[j] > x && nums[j] < nums[smallest])
      smallest = j;
  }

  swap(nums[smallest], nums[i-1]);

  for(int k=i; k<len-1; k++){
    for(int l=k+1; l<len; l++){
      if(nums[k] > nums[l])
        swap(nums[k], nums[l]);
    }
  }
  std::cout << "Next Greater: " << nums << '\n';
}

int main() {
  char digits[] = "123795811";
  int len = sizeof(digits)/sizeof(digits[0]);
  findNextGreater(digits, len-1);
  return 0;
}
