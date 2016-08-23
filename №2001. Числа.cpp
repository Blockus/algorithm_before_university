#include <iostream>
#include <cmath>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int c,b,k;

map <int, bool> vis;
map <int, int> from;

queue <int> q;

void print(int a){
    if(from[a] == -1){
        cout << a << "\n";
    }else{
        print(from[a]);
        cout << a << "\n";

    }
}

void c_l(int a){
    int t = a / 1000;
    a = (a % 1000) * 10 + t;

    if(from[a] == 0){
        q.push(a);
        from[a] = k;
    }
}

void c_r(int a){
    int t = a % 10;
    a = (a / 10) + (t * 1000);

    if(from[a] == 0){
        q.push(a);
        from[a] = k;
    }
}

void inc_up(int a){
    if(a / 1000 != 9) a += 1000;

    if(from[a] == 0){
        q.push(a);
        from[a] = k;
    }
}

void inc_down(int a){
    if(a % 10 != 1) a--;

    if(from[a] == 0){
        q.push(a);
        from[a] = k;
    }
}

int main(){
    cin >> c >> b;

    q.push(c);
    from[c] = -1;

    while(!q.empty()){
        k = q.front();
        q.pop();

        //cout << k << "\n\n";
        if(k == b) break;

        c_l(k); c_r(k); inc_up(k); inc_down(k);

    }

    print(b);

return 0;
}












