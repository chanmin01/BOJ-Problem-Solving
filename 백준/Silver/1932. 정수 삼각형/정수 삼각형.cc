#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int s[505][505];
int n, ret;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> s[i][j];
        }
    }
    dp[1][1] = s[1][1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j == 1) {
                dp[i][j] = dp[i - 1][j] + s[i][j];
                continue;
            }
            else if(j == i) {
                dp[i][j] = dp[i - 1][j - 1] + s[i][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + s[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        ret = max(ret, dp[n][i]);
    }
    cout << ret;
}