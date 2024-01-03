#include <bits/stdc++.h>
using namespace std;

int v[10003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
    }

    for(int i = 1; i <= 10000; i++) {
        while(v[i]) {
            cout << i << '\n'; v[i]--;
        }
    }


}