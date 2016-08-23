#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

string s;

int dp[105][105];


int main(){

    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            dp[i][j] = 0;
            if(i == j) dp[i][j] = 1;
        }
    }

    cin >> s;

    int n = s.length();

    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            if(s[i - 1] == s[j - 1]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            //cout << "dp[" << i << "][" << j << "] :   " << dp[i][j] << "\n";
        }
    }

    cout << dp[1][n];


}
