#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1003];
int s[1003];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    fill(dp + 1, dp + n + 1, 1);
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
}