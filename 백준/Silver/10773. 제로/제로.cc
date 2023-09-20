#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
int n, k;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k;
        if(k != 0) {
            stk.push(k);
        }
        else {
            stk.pop();
        }
    }
    int sum = 0;
    while(!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    cout << sum << '\n';
}