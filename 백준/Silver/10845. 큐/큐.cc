#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--) {
        cin >> s;
        if(s == "push") {
            int k;
            cin >> k;
            q.push(k);
        }
        else if(s == "front") {
            if(!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(s == "back") {
            if(!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
        else if(s == "pop") {
            if(!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s == "size") {
            cout << q.size() << '\n';
        }
        else if(s == "empty") {
            if(!q.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}