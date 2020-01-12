#include <iostream>

using namespace std;

const int M = 20;
int dp[M][M][M];
int num[M], size = 0;
int ara[M], n = 0;
int d, k, a, b;

int count(int pos, int cnt, int f){
  if(cnt > k) return 0;

  if(pos == size){
    if(cnt <= k) return 1;
    return 0;
  }

  if(dp[pos][cnt][f] != -1) {
    return dp[pos][cnt][f];
  }

  int res = 0;
  int lmt;

  if(f == 0){
    lmt = num[pos];
  } else {
    lmt = 9;
  }

  for(int dgt=0; dgt<=lmt; dgt++){
    int nf = f;
    int ncnt = cnt;
    if(f == 0 && dgt < lmt) nf = 1;
    if(dgt == d) ncnt++;
    if(ncnt <= k) res += count(pos+1, ncnt, nf);
  }
  return dp[pos][cnt][f] = res;
}

int solve(int x) {
  n = 0, size = 0;

  while (x) {
    ara[n++] = x % 10;
    x /= 10;
  }

  while (--n >= 0) {
    num[size++] = ara[n];
  }

  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++){
      for(int k=0; k<M; k++){
        dp[i][j][k] = -1;
      }
    }
  }

  int res = count(0,0,0);
  return res;
}

int main() {
  a = 11, b = 100;
  d = 2, k = 1;
  int ans = solve(b) - solve(a-1);
  std::cout << ans << '\n';
  return 0;
}
