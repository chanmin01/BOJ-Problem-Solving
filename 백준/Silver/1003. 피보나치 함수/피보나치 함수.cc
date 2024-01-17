#include <bits/stdc++.h>
using namespace std;

int dp_one[44];
int dp_zero[44];
int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        dp_one[0] = 0;
        dp_one[1] = 1;
        dp_zero[0] = 1;
        dp_zero[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
            dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
        }
        cout << dp_zero[n] << ' ' << dp_one[n] << '\n';
    }
}