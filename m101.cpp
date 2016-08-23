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

string s;
int p[50005];

void prefix(){
    p[1] = 0;

    for(int i = 2; i <= s.length() - 1; i++){

        int t = p[i - 1];

        while(s[t + 1] != s[i] && t != 0) t = p[t];

        if(s[t + 1] == s[i]) t++;

        p[i] = t;

    }

    //for(int i = 1; i <= s.length() - 1; i++){
    //   cout << "p[" << i << "]" << " = " << p[i] << "\n";
    //}
}

int main(){

    cin >> s;

    s = '0' + s;

    prefix();

    cout << s.length() - 1 - p[s.length() - 1];



return 0;
}
