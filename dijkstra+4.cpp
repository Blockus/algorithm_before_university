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

const int MAX_TIME = 1440;
const int MINI_SIZE = 505;
const int SIZE = 250005;

int n,k;

int en = 0;
int dest[SIZE];
int w[SIZE];
int nxt[SIZE];
int tm[SIZE];
int head[MINI_SIZE];

int d[MINI_SIZE];
bool vis[MINI_SIZE];

void start_inicilization(){
    for(int i = 0; i <= n; i++){ head[i] = 0;}
}

void add_edge(int u, int v, int t, int m){
    en++;
    dest[en] = v;
    nxt[en] = head[u];
    head[u] = en;

    tm[en] = t;
    w[en] = m;
}

void solve(){

    for(int i = 0; i < k; i++){
        int a,b,t;
        long m;

        cin >> a >> b >> t >> m;

        m -= 3000000;
        m /= 100;

        add_edge(a, b, t, m);
        add_edge(b, a, t, m);
    }

    // Бинпоиск по значениям

    long l = 1;
    long r = 10000001;

    while(r - l > 1){

        //cout << l << " " << r << "\n";

        long med = (r + l) / 2;

        // Dijkstra по времени

        for(int i = 0; i <= n; i++){
            d[i] = 2000;
            vis[i] = false;
        }

        d[1] = 0;

        for(int i = 1; i <= n; i++){

            int t = -1;

            for(int q = 1; q <= n; q++){
                if(!vis[q] && (t == -1 || d[q] < d[t])) t = q;
            }

            if(d[t] == 2000) break;

            vis[t] = true;
            int j = head[t];

            while(j != 0){
                if(d[ dest[j] ] > d[t] + tm[j] && w[j] >= med) d[ dest[j] ] = d[t] + tm[j];
                j = nxt[j];
            }

        }

        if(d[n] <= MAX_TIME) l = med;
        else r = med;

    }

    if(l != 1) cout << l;
    else{
         for(int i = 0; i <= n; i++){
            d[i] = 2000;
            vis[i] = false;
        }

        d[1] = 0;

        for(int i = 1; i <= n; i++){

            int t = -1;

            for(int q = 1; q <= n; q++){
                if(!vis[q] && (t == -1 || d[q] < d[t])) t = q;
            }

            if(d[t] == 2000) break;

            vis[t] = true;
            int j = head[t];

            while(j != 0){
                if(d[ dest[j] ] > d[t] + tm[j] && w[j] >= 1) d[ dest[j] ] = d[t] + tm[j];
                j = nxt[j];
            }

        }

        if(d[n] <= MAX_TIME) cout << 1;
        else cout << 0;

    }

}

int main(){

    cin >> n >> k;

    start_inicilization();

    solve();

return 0;
}
