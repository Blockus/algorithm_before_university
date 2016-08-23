#include <iostream>
#include <cmath>
#include <map>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 200000

using namespace std;

int n,m;

vector <long> t(MAXN);
vector <long> a;
vector <long> ans;

long gcd(long a, long b){
    if(b == 0) return a;
    else gcd(b, a%b);
}

long gcd_tree(int v, int tl, int tr, int l, int r){

    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];

    int tm = (tl + tr) / 2;

    return gcd( gcd_tree(v * 2, tl, tm, l, min(r, tm)) ,
                gcd_tree(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
              );
}


void build(int v, int tl, int tr){
    if(tl > tr) return;
    if(tl == tr) t[v] = a[tr];
    else{
        int tm = (tr + tl) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = gcd(t[2 * v], t[2 * v + 1]);
    }
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        long t;
        cin >> t;
        a.push_back(t);
    }

    build(1, 0, n-1);

    cin >> m;

    for(int i = 0; i < m; i++){
        int l,r;
        cin >> l >> r;
        ans.push_back( gcd_tree(1, 0, n-1, l-1, r-1) );
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

return 0;
}












