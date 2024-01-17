#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[95][2], ret[95];
int n;

int main() {
    cin >> n;
    dp[1][0] = 0;
    dp[1][1] = 1;
    ret[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        ret[i] = dp[i][0] + dp[i][1];
    }
    cout << ret[n];
}