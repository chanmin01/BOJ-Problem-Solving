#include <bits/stdc++.h>
using namespace std;

deque<int> d;
int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push_back") {
            int k;
            cin >> k;
            d.push_back(k);
        }
        if(s == "push_front") {
            int k;
            cin >> k;
            d.push_front(k);
        }
        if(s == "pop_front") {
            if(!d.empty()) {
                int k = d.front();
                d.pop_front();
                cout << k << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        if(s == "pop_back") {
            if(!d.empty()) {
                int k = d.back();
                d.pop_back();
                cout << k << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        if(s == "size") {
            cout << d.size() << '\n';
        }
        if(s == "empty") {
            if(d.empty()) {
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
        if(s == "front") {
            if(!d.empty()) {         
                cout << d.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        if(s == "back") {
            if(!d.empty()) {         
                cout << d.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}