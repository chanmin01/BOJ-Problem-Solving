#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m, n, a[1000004];

bool solve(ll x) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += a[i] / x;
    }
    return cnt >= m;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll st = 1;
    ll en = 1e9;
    sort(a, a + n);
    while(st <= en) {
        ll mid = (st + en) / 2;
        if(solve(mid)) st = mid + 1;
        else en = mid - 1;
    }
    cout << en;
}