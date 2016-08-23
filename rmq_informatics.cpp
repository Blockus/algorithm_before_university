#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <cmath>
#include <fstream>
using namespace std;

const int SIZE = 100000;

pair <long, int> a[4 * SIZE];
int n,k,d,m;

int st(){
    int i = 1;
    int s = 0;
    while(i < n){
        i *= 2;
        s++;
    }
    d = s;
    return i;
}

void show(){
    for(int i = 1; i <= 2 * m - 1; i++) cout << a[i].second << " ";
}

pair <long, int> max_otr(int l, int r){

    pair <long, int> res;
    res.first = LONG_MIN;
    res.second = 1;

    while(l <= r){
        if(l % 2 == 1){
            if(a[l].first >= res.first){
                res.first = a[l].first;
                res.second = a[l].second;
            }
            l++;
        }
        if(r % 2 == 0){
            if(a[r].first >= res.first){
                res.first = a[r].first;
                res.second = a[r].second;
            }
            r--;
        }

        r /= 2;
        l /= 2;
    }


    return res;
}

int main(){

    ofstream cout("output.txt");

    cin >> n;

    m = st();

    for(int i = 0; i < 2 * m - 1; i++){
        a[i].first = 0;
        a[i].second = -1;
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        a[m - 1 + i].first = t;
        a[m - 1 + i].second = i;
    }

    for(int i = m - 1; i >= 1; i--){
        if(a[2 * i].first >= a[2 * i + 1].first){
            a[i].first = a[2 * i].first;
            a[i].second = a[2 * i].second;
        }else{
            a[i].first = a[2 * i + 1].first;
            a[i].second = a[2 * i + 1].second;
        }
    }

    int k;
    cin >> k;

    for(int i = 1; i <= k; i++){
        int l,r;

        cin >> l >> r;

        l += m - 1;
        r += m - 1;

        pair <long, int> ans = max_otr(l, r);

        cout << ans.first << " " << ans.second << "\n";
    }

    //show();

return 0;
}
