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

const int SIZE = 200005;

queue <long long> q;

int head[SIZE];
int dest[SIZE];
int nxt[SIZE];
long w[SIZE];
long long fire[SIZE];
int en = 0;

int n,m,k;

void add_edge(int u, int v, int wt){
    en++;
    dest[en] = v;
    nxt[en] = head[u];
    head[u] = en;
    w[en] = wt;
}

void count_fire(){
    while(!q.empyty()){
        int u = q.front();
        q.pop();

        int j = head[u];
        while(j != -1){



            j = next[j];
        }

    }
}

void solve(){

    for(int i = 1; i <= SIZE; i++){
        head[i] = -1;
        fire[i] = -1;
    }

    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++){
        int a;
        cin >> a;
        fire[a] = 0;
        q.push(a);
    }

    for(int i = 0; i < m; i++){
        int a,b,wt;
        cin >> a >> b >> wt;

        add_edge(a, b, wt);
        add_edge(b, a, wt);
    }

}

int main(){



return 0;
}
