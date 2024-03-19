#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    int m[n];
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }
    cin >> k;

    cout << count(m, m + n, k);
}