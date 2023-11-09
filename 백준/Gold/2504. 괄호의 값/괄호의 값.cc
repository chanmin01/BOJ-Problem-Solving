#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin >> s;
    stack<char> st;
    int sum = 0;
    int mul = 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
            mul *= 2;
        }
        else if(s[i] == '[') {
            st.push(s[i]);
            mul *= 3;
        }
        else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') {
                cout << 0 << '\n';
                return 0;
            }
            if(s[i - 1] == '(') sum += mul;
            st.pop();
            mul /= 2;
        }
        else {
            if(st.empty() || st.top() != '[') {
                cout << 0 << '\n';
                return 0;
            }
            if(s[i - 1] == '[') sum += mul;
            st.pop();
            mul /= 3;
        }
    }
    if(st.empty()) cout << sum << '\n';
    else cout << 0 << '\n';
}