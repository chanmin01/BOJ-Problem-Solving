#include <bits/stdc++.h>
using namespace std;

int a[1000001], t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_num = a[n - 1];
        long long sum = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(max_num < a[i]) max_num = a[i];
            sum += max_num - a[i];
        }

        cout << sum << '\n';
    }

}