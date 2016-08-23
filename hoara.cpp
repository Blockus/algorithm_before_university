#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

const int SIZE = 100005;

long a[SIZE];

void hoara(int l, int r){
    if(l >= r) return;

    int x = a[ ( rand() % (r - l + 2) ) + l ];
    int i = l; int j = r;

    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    hoara(l, j);
    hoara(i, r);
}

int main(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        a[i] = t;
    }

    hoara(1, n);

    for(int i = 1; i <= n; i++) cout << a[i] << " ";

return 0;
}
