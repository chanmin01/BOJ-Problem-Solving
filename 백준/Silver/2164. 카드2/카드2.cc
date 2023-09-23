#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(q.size() != 1) {
        q.pop();
        int m = q.front();
        q.pop();
        q.push(m);
    }
    cout << q.front() << '\n';
    return 0;
}