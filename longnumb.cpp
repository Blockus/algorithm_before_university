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


void get_ten(int k){
    if(c[k] > 0) c[k]--;
    else{
        c[k] = 9;
        get_ten(k+1);
    }
    return;
}

int main(){
    string as,bs;
    bool pol = true;

    cin >> as >> bs;

    // Start inicilization

    for(int i = as.length() - 1; i >= 0; i--) a.push_back( as[i] - '0' );
    for(int i = bs.length() - 1; i >= 0; i--) b.push_back( bs[i] - '0' );

    if(a.size() < b.size()){ pol = false; swap(a,b); }
    if(a.size() == b.size()){
        for(int i = a.size() - 1; i >= 0; i--){
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]){ pol = false; swap(a,b); break; }
            else break;
        }
    }

    while(b.size() != a.size()){
        if(b.size() > a.size()) a.push_back(0);
        if(a.size() > b.size()) b.push_back(0);
    }

    for(int i = 0; i < a.size() + 1; i++) c.push_back(0);

    for(int i = a.size() - 1; i > b.size() - 1; i--){
        c[i] = a[i];
    }
    //
    //int s = 0;
    for(int i = b.size() - 1; i >= 0; i--){
        if(a[i] >= b[i]) c[i] = a[i] - b[i];
        else{
            c[i] = a[i] - b[i] + 10;
            get_ten(i+1);
        }
    }

    for(int c.size(); i >= 0; i--){
        cout << c[i];
    }

return 0;
}
