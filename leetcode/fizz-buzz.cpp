#include <iostream>

using namespace std;

int main(){
  int num;
  std::cin >> num;

  for(int n=1; n<=num; n++){
    if(n%3 == 0 && n%5 == 0){
      std::cout << "FizzBuzz" << '\n';
    } else if(n%3 == 0){
      std::cout << "Fizz" << '\n';
    } else if(n%5 == 0){
      std::cout << "Buzz" << '\n';
    } else {
      std::cout << n << '\n';
    }
  }
  return 0;
}
