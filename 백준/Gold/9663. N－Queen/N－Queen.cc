#include <bits/stdc++.h>
using namespace std;

int cnt, a[17][17], visited1[40], visited2[40], visited3[40], n;

void func(int m) {
    if(m == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(visited1[i] || visited2[i + m] || visited3[i - m + n - 1]) continue;
        visited1[i] = 1;
        visited2[i + m] = 1;
        visited3[i - m + n - 1] = 1;
        func(m + 1);
        visited1[i] = 0;
        visited2[i + m] = 0;
        visited3[i - m + n - 1] = 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    func(0);
    cout << cnt << '\n';
}