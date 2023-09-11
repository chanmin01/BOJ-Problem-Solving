#include <bits/stdc++.h>
using namespace std;

int n, s, a[25], cnt;

void func(int cur, int sum) {
    if(cur == n) {
        if(sum == s) cnt++;
        return;
    }
    func(cur + 1, sum);
    func(cur + 1, sum + a[cur]);
} 

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    func(0, 0);
    if(s == 0) cnt--;
    cout << cnt << '\n';
}