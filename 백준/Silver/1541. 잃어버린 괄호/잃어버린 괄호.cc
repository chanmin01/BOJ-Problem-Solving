#include <bits/stdc++.h>
using namespace std;

int ret, temp;
int sign = 1;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    
    for(char a : s) {
        if(a == '+' || a == '-') {
            ret += temp * sign;
            temp = 0;
            if(a == '-') {
                sign = -1;
            }
        } else {
            temp = temp * 10 + (a - '0');
        }

    }

    ret += temp * sign;
    cout << ret;
    
}