#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string a, b;
vector<char> a_l, b_l;

int main() {
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        a_l.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        b_l.push_back(b[i]);
    }

    for (char k : a_l) {
        if (find(b_l.begin(), b_l.end(), k) != b_l.end()) {
            b_l.erase(find(b_l.begin(), b_l.end(), k));
            cnt++;
        }
    }

    cout << a.size() + b.size() - 2 * cnt << '\n';
}
