#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    getchar();

    while(cases--){
        string str;
        int count = 0;
        getline(cin, str);
        for(int i=0; i<str.length()-1; i++){
            if(str.at(i) == str.at(i+1)) ++count;
            // std::cout << str[i] << '\n';
        }
        cout << count << endl;
    }
    return 0;
}
