#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1004][5];
int s[1004][5];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> s[i][j];
        }
    }

    if(n == 1) {
        cout << min(s[1][1], min(s[1][2], s[1][3]));
    }

    dp[1][1] = s[1][1];
    dp[1][2] = s[1][2];
    dp[1][3] = s[1][3];

    for(int i = 2; i <= n; i++) {
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + s[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + s[i][2];
        dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + s[i][3];
    }

    cout << min(dp[n][1], min(dp[n][2], dp[n][3]));
}