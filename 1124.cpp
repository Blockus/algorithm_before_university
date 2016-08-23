#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

string s;

int dp[105][105];
string str[105][105];

int main(){

    cin >> s;

    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            dp[i][j] = 0;
            str[i][j] = "";
            if(i == j){
                dp[i][j] = 1;
                str[i][j] = s[i - 1];
            }
        }
    }



    int n = s.length();

    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            if(s[i - 1] == s[j - 1]){
                dp[i][j] = 2 + dp[i+1][j-1];
                str[i][j] += s[i-1];
                str[i][j] += str[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if(str[i+1][j].length() >= str[i][j-1].length()) str[i][j] += str[i+1][j];
                else str[i][j] = str[i][j-1];
            }
        }
    }

    int ans = dp[1][n];
    string t = str[1][n];

    if(ans % 2){
        for(int v = t.length(), i = v - 2; i >= 0; i--) t += t[i];
    }else{
        for(int v = t.length(), i = v - 1; i >= 0; i--) t += t[i];
    }

    cout << ans << "\n";
    cout << t;
}
