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

const int SIZE = 10005;

long a[SIZE];
int n,k;

int main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }


    long l = 0;
    long r = a[n];

    while(r - l > 1){

        int med = (l + r) / 2;

        int succes = 1;

        for(int i = 2, j = 1; i <= n; i++){
            if(a[i] - a[j] >= med){
                succes++;
                j = i;
            }
        }

        if(succes >= k) l = med;
        else r = med;

    }

    cout << l;

return 0;
}
