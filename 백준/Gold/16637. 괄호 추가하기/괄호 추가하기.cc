#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> v_num;
vector<char> v_char;

int oper(char a, int b, int c) {
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}

void go(int idx, int num) {
    if(idx == v_num.size() - 1) {
        ret = max(ret, num);
        return;
    }
    go(idx + 1, oper(v_char[idx], num, v_num[idx + 1]));

    if(idx + 2 <= v_num.size() - 1) {
        int temp = oper(v_char[idx + 1], v_num[idx + 1], v_num[idx + 2]);
        go(idx + 2, oper(v_char[idx], num, temp));
    }
}

int main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) v_num.push_back(s[i] - '0');
        else v_char.push_back(s[i]);
    }

    go(0, v_num[0]);
    cout << ret << '\n';
}