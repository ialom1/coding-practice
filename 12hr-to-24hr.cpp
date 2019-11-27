#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    // string str = "07:05:45PM";
    string str;
    int ara[6];
    getline(cin, str);

    int h1 = str[0] - '0';
    int h2 = str[1] - '0';
    int hh = h1 * 10 + h2;
    string hrs;

    if(str[8] == 'A'){
      if(hh == 12) std::cout << "00";
      else std::cout << str[0] << str[1];
    }
    else{
      if(hh == 12) std::cout << "12";
      else std::cout << hh + 12;
    }
    for(int i=2; i<8; i++)
      std::cout << str[i];

    return 0;
}
