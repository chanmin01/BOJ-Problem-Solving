#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt;
deque<int> dq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }
    for(int i = 0; i < m; i++) {
        cin >> k;
        int idx = find(dq.begin(), dq.end(), k) - dq.begin();
        while (dq.front() != k) {
            if(idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        }
        dq.pop_front();
    }
    cout << cnt << '\n';
}