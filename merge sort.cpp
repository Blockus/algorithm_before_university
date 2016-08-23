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
int ind[SIZE], cnt[12];



void countSort(){
    for(long m = 1; m <= inf; m *= 10){

        for(int i = 0; i <= 9; i++) cnt[i] = 0;

        for(int i = 1; i <= n; i++) cnt[ (a[i] / m) % 10]++;

        ind[0] = 1;

        for(int i = 0; i <= n - 1; i++) ind[i + 1] = ind[i] + cnt[i];

        for(int i = 1; i <= n; i++){
            int t = (a[i] / m) % 10;
            b[ ind[t] ] = a[i];
            ind[t]++;
        }

        for(int i = 1; i <= n; i++) a[i] = b[i];
    }
}

int main(){


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
