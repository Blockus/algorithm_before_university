#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

const long inf = 2000000000;
const int SIZE = 100005;
int n;

long a[SIZE], b[SIZE];
int ind[12], cnt[12];

void show(){
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

void countSort(){
    for(long long m = 1; m <= inf; m *= 10){

        for(int i = 0; i <= 9; i++) cnt[i] = 0;


        for(int i = 1; i <= n; i++){
            cnt[ (a[i] / m) % 10 ]++;
            //cout << (a[i] / m) % 10 << " ";
        }

        ind[0] = 1;

        for(int i = 0; i <= 9; i++){
            ind[i + 1] = ind[i] + cnt[i];
            //cout << ind[i+1] << " " << cnt[i+1] << "\n";
        }
        //cout << "\n";

        for(int i = 1; i <= n; i++){
            int t = (a[i] / m) % 10;
            b[ ind[t] ] = a[i];
            //cout << ind[t] << " ";
            ind[t]++;
        }
        //cout << "\n";

        for(int i = 1; i <= n; i++) a[i] = b[i];
        //show();
    }
return;
}

int main(){

    //cout << LONG_MAX;

    cin >> n;

    for(int i = 1; i <= n; i++){
        long k;
        cin >> k;
        a[i] = k;
        b[i] = k;
    }

    countSort();

    for(int i = 1; i <= n; i++) cout << a[i] << " ";

return 0;
}
