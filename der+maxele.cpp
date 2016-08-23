#include <iostream>
#include <cmath>
#include <map>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

#define MAXN 200000

using namespace std;

int n,m;

vector < pair<long, int> > t(MAXN);
vector < pair<long, int> > ans;
vector <long> a;

pair <long, int> combine(pair <long, int> a, pair <long, int> b){
    if(a.first > b.first) return a;
    if(b.first > a.first) return b;
    return make_pair(a.first, a.second + b.second);
}


pair <long, int> get_max(int v, int tl, int tr, int l, int r){

    if(l > r) return make_pair(LONG_MIN, 0);

    if(l == tl && r == tr) return t[v];

    int tm = (tl + tr) / 2;

    pair <long, int> a = get_max(v * 2, tl, tm, l, min(r, tm));
    pair <long, int> b = get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

    return combine(a, b);

}


void build(int v, int tl, int tr){
    if(tl > tr) return;
    if(tl == tr) t[v] = make_pair(a[tr], 1);
    else{
        int tm = (tr + tl) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
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
        ans.push_back( get_max(1, 0, n-1, l-1, r-1) );
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }


return 0;
}
