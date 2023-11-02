#include <bits/stdc++.h>
using namespace std;
string s;
char a_past;
int cnt;
stack<char> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(char a : s) {
        if(a == '(') {
            st.push(a);
        }
        else if(a == ')') {
            if(a_past == '(') {
                st.pop();
                cnt += st.size();
            }
            else {
                st.pop();
                cnt += 1;
            }
        }
        a_past = a;
    }
    cout << cnt << '\n';
}