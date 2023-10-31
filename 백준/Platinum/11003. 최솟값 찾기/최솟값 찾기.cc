#include <bits/stdc++.h>
using namespace std;
int n, l, k;
deque<pair<int, int>> dq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> k;
        while(!dq.empty() && dq.back().second > k) {
            dq.pop_back();
        }
        dq.push_back({i, k});

        if(dq.front().first <= i - l) {
            dq.pop_front();
        }
        cout << dq.front().second << " ";
    }
}