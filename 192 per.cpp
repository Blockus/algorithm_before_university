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

void per_obr(){

    long long l = 0;

    vector <bool> b;

    for(int i = 0; i <= 13; i++) b.push_back(false);

    for(int i = 1; i <= k; i++){

        int j = 1;
        int s = 0;

        while(j != a[i]){

            if(!b[j]) s++;
            j++;
        }
        s++;

        b[ a[i] ] = true;

        //6cout << "s: " << s << "  C( k-i ; n - i)  " << fact[n - i] / (fact[n - k] * fact[k - i]) << "\n";
        l += (s - 1) * ( fact[n - i] / fact[n - k] );

    }

    cout << l + 1;

return;
}

int main(){

    cin >> n >> k;

    a.push_back(0);
    for(int i = 1; i <= k; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }

    fact.reserve(14);
    fact.push_back(1);
    for(int i = 1; i <= 12; i++){
        fact[i] = fact[i-1] * i;
    }



    per_obr();

return 0;
}
