#include <iostream>

using namespace std;
// Shortest distance from multiple sources

int n, point[100];

int right_cal(int p, int x){
  int dist = 0;
  for(int i=1; i<=x; i++){
    int l=0, r=0, flag=1;

    for(int j=p; j>=1; j--){
      if(point[j] == 0){
        flag = 0;
        l++; break;
      }
      l++;
    }

    if(flag) l=1000; flag = 1;

    for(int j=p; j<=n; j++){
      if(point[j] == 0){
        flag = 0;
        r++; break;
      }
      r++;
    }

    if(flag) r=1000;

    if(l < r){
      dist += l;
      point[p-l+1] = 1;
    } else {
      dist += r;
      point[p+r-1] = 1;
    }
  }
  return dist;
}
int left_cal(int p, int x){
  int dist = 0;
  for(int i=1; i<=x; i++){
    int l=0, r=0, flag=1;

    for(int j=p; j>=1; j--){
      if(point[j] == 0){
        flag = 0;
        l++; break;
      }
      l++;
    }

    if(flag) l=1000; flag = 1;

    for(int j=p; j<=n; j++){
      if(point[j] == 0){
        flag = 0;
        r++; break;
      }
      r++;
    }

    if(flag) r=1000;

    if(l < r){
      dist += l;
      point[p-l+1] = 1;
    } else {
      dist += r;
      point[p+r-1] = 1;
    }
  }
  return dist;
}

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    int pos, pers;
    int gate[10][10];
    int ans = 1000;
    std::cin >> n;

    for(int i=1; i<=3; i++){
      std::cin >> pos >> pers;
      gate[i][1] = pos;
      gate[i][2] = pers;
    }

    for(int i=1; i<=3; i++){
      for(int j=1; j<=3; j++){
        if(i==j) continue;
        for(int k=1; k<=3; k++){
          if(i==k || j==k) continue;
          int dist = 0;

          for(int x=1; x<=n; x++){
            point[x] = 0;
          }
          dist += left_cal(gate[i][1], gate[i][2]);
          dist += left_cal(gate[j][1], gate[j][2]);
          dist += left_cal(gate[k][1], gate[k][2]);
          if(ans > dist) ans = dist;

          // for(int x=1; x<=n; x++){
          //   point[x] = 0;
          // }
          // dist += right_cal(gate[i][1], gate[i][2]);
          // dist += right_cal(gate[j][1], gate[j][2]);
          // dist += right_cal(gate[k][1], gate[k][2]);
          // if(ans > dist) ans = dist;
        }
      }
    }

    std::cout << ans << '\n';
  }
}
