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

long long n,k;

vector <long long> fact;
vector <int> a;

void per(long long k){

    vector <bool> b;
    for(int i = 0; i <= n + 1; i++) b.push_back(false);

    for(int i = 1; i <= n; i++){
        int t = (k - 1) / fact[n - i] + 1;
        int s = 0, j = 1;
        while(s != t){
            if( !b[j] ) s++;
            j++;
        }
        j--;

        b[j] = true;
        a.push_back(j);
        cout << j << " ";
        k -= fact[n - i] * (t - 1);

    }

return;
}

int main(){

    cin >> n >> k;

    fact.reserve(14);
    fact.push_back(1);
    for(int i = 1; i <= 12; i++){
        fact[i] = fact[i-1] * i;
    }



    per(k);


return 0;
}
