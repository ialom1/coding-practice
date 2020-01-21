#include <iostream>

using namespace std;

void recur(int l, int h){
  std::cout << l << " " << h << '\n';
  if(l < h) {
    int mid = (l+h)/2;
    recur(l, mid);
    recur(mid+1, h);
    std::cout << "merge: " << l << h << " " << l+h <<  '\n';
  }
}

int main() {
  recur(1, 10);
  return 0;
}
