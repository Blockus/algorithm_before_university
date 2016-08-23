#include <iostream>
#include <cmath>
#include <map>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>

#define MAXN 400001

using namespace std;


vector <int> a,b,c;


int main(){
    string as,bs;


    cin >> as >> bs;

    // Start inicilization

    for(int i = as.length() - 1; i >= 0; i--) a.push_back( as[i] - '0' );
    for(int i = bs.length() - 1; i >= 0; i--) b.push_back( bs[i] - '0' );

    /*
    while(b.size() != a.size()){
        if(b.size() > a.size()) a.push_back(0);
        if(a.size() > b.size()) b.push_back(0);
    }
    */

    for(int i = 0; i < 2 + a.size() * b.size(); i++) c.push_back(0);
    //int s = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            c[i+j+1] += a[i] * b[j];
        }
    }

    for(int i = 0; i < c.size(); i++){
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    int s = false;
    if(as == "0" || bs == "0") cout << 0;
    for(int i = c.size() - 1; i > 0; i--){
        if(c[i] == 0 && !s) continue;
        else s = true;
        cout << c[i];
    }


return 0;
}
