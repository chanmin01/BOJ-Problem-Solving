#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }


}