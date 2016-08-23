#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

const int MAX_M = 250002;
const int MAX_N = 502;
const int MAX_CUP = 10000000;
const int inf = 100000;
const int GOOD_TIME = 1420;
int n,m;

queue <int> q;
vector <int> v(MAX_N);


int en = 0;
vector <int> dest(MAX_M);
vector <int> next(MAX_M);
vector <int> head(MAX_N);
vector <long> weight(MAX_M);
vector <int> time(MAX_M);

void add_edge(int a, int b, int t, long w){
    en++;
    dest[en] = b;
    next[en] = head[a];
    head[a] = en;

    weight[en] = w;
    time[en] = t;
}

void show_q(){
    queue <int> k;
    k = q;
    cout << "QUEUE: ";
    while(!k.empty()){
        cout << k.front() << " ";
        k.pop();
    }
    cout << "\n";
}


int main(){

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b,t; long w;
        cin >> a >> b >> t >> w;
        w -= 3000000;

        // Add edge:
        add_edge(a,b,t,w);
        add_edge(b,a,t,w);
        // End of add edge
    }

    int l,r;
    bool tr = false;
    l = 1;
    r = MAX_CUP + 1;

    /*
    cout << "DEBUG \n";

    for(int i = 1; i <= n; i++){
        cout << i << " | " ;
        int j = head[i];
        while(j != 0){
            cout << dest[j] << ", ";
            j = next[j];
        }
        cout << "\n";
    }

    cout << "END OF DEBUG \n";
    */

    while(r > l + 1){


        //cout << l << " " << r << " ";
        int m = (r + l) / 2;
        //cout << m << "\n";
        m *= 100;

        for(int i = 1; i <= n; i++){ v[i] = inf; }

        q.push(1);
        v[1] = 0;

        while(!q.empty()){
            int t = q.front();
            int j = head[t];
            q.pop();

            while(j != 0){
                //cout << weight[j] << " " << m << " TIME: " << time[j] << " + " << v[t] << " <= " << v[dest[j]] << " || ";
                if((v[dest[j]] > time[j] + v[t]) && (weight[j] >=  m)){
                    v[dest[j]] = time[j] + v[t];
                    q.push( dest[j] );
                }
                j = next[j];
            }
            //show_q();
        }

        m /= 100;
        if(v[n] <= GOOD_TIME){ l = m; tr = true;}
        else r = m;
    }

    if(!tr) cout << 0;
    else cout << l;

return 0;
}
