// Решение задачи https://www.e-olymp.com/ru/problems/2307
// Решение задачи https://www.e-olymp.com/ru/problems/2307
// Решение задачи https://www.e-olymp.com/ru/problems/2307
// Решение задачи https://www.e-olymp.com/ru/problems/2307
// Решение задачи https://www.e-olymp.com/ru/problems/2307

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <cmath>
#include <fstream>
#include <map>
using namespace std;

const int SIZE = 100000;

int n,n_new,high_tree,k;

long a[4 * SIZE];
long b[4 * SIZE];
long c[4 * SIZE];

vector <long> ans;

map <int, bool> m;

void do_grade_of_two(){

    for(int i = 1; i <= 1024*1024*1024; i *= 2) m[i] = true;

return;
}

void build_tree(){

    if(n != 1) n_new = (1 << ((int)log2(n - 1) + 1));
    else n_new = 1;

    if(n != 1) high_tree = (int)log2(n - 1) + 1;
    else high_tree = 0;

    for(int i = 0; i < n_new * 2 + 1; i++){
        a[i] = b[i] = c[i] = 0;
        c[i]--;
    }

    /* BUILD TREE:
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        a[n_new - 1 + i] = m;
    }


    for(int i = n_new - 1; i > 0; i--){
        a[i] = a[2 * i] + a[2 * i + 1];
    }
    */
return;
}

void show_a(){
    for(int i = 1; i <= n_new * 2 - 1; i++){
        if(m[i] == true) cout << "\n";
        cout << a[i] << " ";
    }
    cout << "\n\n\n";
return;
}

void show_b(){
    for(int i = 1; i <= n_new * 2; i++){
        if(m[i] == true) cout << "\n";
        cout << b[i] << " ";
    }
return;
}

void show_c(){
    for(int i = 1; i <= n_new * 2 - 1; i++){
        if(m[i] == true) cout << "\n";
        cout << c[i] << " ";
    }
    cout << "\n\n\n";
return;
}

void update(int ver, int u, int v, int d, int x){

    int l = (ver << d);
    int r = l | ((1 << d) - 1);

    if(v < l || u > r) return;

    if(v >= r && u <= l){
        b[ver] += x;
    }else{

        update(2 * ver, u, v, d - 1, x);
        update(2 * ver + 1, u, v, d - 1, x);
    }

return;
}

int get(int ver, int u, int v, int d){

    int l = ver << d;
    int r = l | ((1 << d) - 1);

    if(u > r || v < l) return 0;

    if(l >= u && r <= v){
        return a[ver] + b[ver] * (r - l + 1);
    }

    u = max(l ,u);
    v = min(r, v);

    return get(2 * ver, u, v, d - 1) + get(2 * ver + 1, u, v, d - 1) + (b[ver] * (v - u + 1));

}

void sift_down(int v){
    if(c[v] != -1){
        c[2 * v] = c[2 * v + 1] = c[v];
        c[v] = -1;
    }
return;
}

void refresh_value(int v, int d){
    v /= 2;
    d++;
    while(v != 0){
        long long sm = 0;

        if(c[2 * v] == -1) sm += a[2 * v];
        else sm += c[2 * v] * (1 << (d -  1));

        if(c[2 * v + 1] == -1) sm += a[2 * v + 1];
        else sm += c[2 * v + 1] * (1 << (d -  1));

        a[v] = sm;

        d++;
        v /= 2;
    }
return;
}

void new_value(int ver, int u, int v, int d, int val){

    int l = (ver << d);
    int r = l | ((1 << d) - 1);

    if(u > r || v < l) return;

    if(r <= v && l >= u){
        c[ver] = val;
        // Обновляем значения в RMQ дереве A[]
        refresh_value(ver, d);

    }else{
        sift_down(ver);
        new_value(2 * ver, u, v, d - 1, val);
        new_value(2 * ver + 1, u, v, d - 1, val);
    }

return;
}

long long get_with_new_value(int ver, int u, int v, int d){

    int l = (ver << d);
    int r = l | ((1 << d) - 1);

    if(u > r || v < l) return 0;

    if(l >= u && r <= v){
        if(c[ver] == -1) return a[ver];
        else return c[ver] * (r - l + 1);
    }else{
        u = max(l, u);
        v = min(r, v);

        if(c[ver] != -1) return c[ver] * (v - u + 1);
        else  return get_with_new_value(2 * ver, u, v, d - 1) + get_with_new_value(2 * ver + 1, u, v, d - 1);
    }

return 0;
}

void solve(){
    for(int i = 1; i <= k; i++){
        char ch;
        cin >> ch;
        if(ch == 'A'){
            int l,r,x;
            cin >> l >> r >> x;
            new_value(1, l + n_new - 1, r + n_new - 1, high_tree, x);
        }else{
            int l,r;
            cin >> l >> r;
            long long t = get_with_new_value(1, l + n_new - 1, r + n_new - 1, high_tree);
            ans.push_back(t);
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

return;
}

int main(){

    do_grade_of_two();

    cin >> n >> k;;

    build_tree();

    solve();

return 0;
}
