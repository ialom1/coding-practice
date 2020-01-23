#include <iostream>

using namespace std;

#define MAX 100

int isPrime[MAX] = {0};

void sieve(){
  for(int i=2; i<MAX; i++){
    isPrime[i] = 1;
  }
  for(int p=2; p*p<=MAX; p++){
    if(isPrime[p]){
      for(int i=p*p; i<=MAX; i+=p){
        isPrime[i] = 0;
      }
    }
  }
}

int findPrimes(int l, int h){
  int prefix[h+1] = {0};
  for(int i=1; i<=h; i++){
    prefix[i] = prefix[i-1];
    if(isPrime[i]){
      ++prefix[i];
    }
  }
  return prefix[h] - prefix[l-1];
}

int main() {
  sieve();
  int pc = 0;
  for(int i=0; i<50; i++){
    if(isPrime[i]){
      ++pc;
      std::cout << i << ' ';
    }
  }std::cout << '\n';

  std::cout << "Total Primes: " << pc << '\n';

  int a = 5;
  int b = 50;
  std::cout << "Primes in range: " << findPrimes(a, b) << '\n';
  return 0;
}
