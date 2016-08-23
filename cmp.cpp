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

string s,a,b;
int p[50005];

void prefix(){
    s = '#' + b + '#' + a;
    int al = a.length();
    int bl = b.length();
    int sl = s.length();

    p[1] = 0;

    for(int i = 2; i <= sl - 1; i++){
        int t = p[i - 1];

        while(t != 0 && s[i] != s[t + 1]) t = p[t];

        if(s[i] == s[t + 1]) t++;

        p[i] = t;
    }

}

void cmp(){
    int al = a.length();
    int bl = b.length();
    int sl = s.length();

    for(int i = 1; i <= sl - 1; i++){
        if(p[i] == bl) cout << i - 2*bl - 1 << " ";
    }
}

int main(){

  cin >> a >> b;

  prefix();
  cmp();

return 0;
}
