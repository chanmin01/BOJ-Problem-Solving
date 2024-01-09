#include <bits/stdc++.h>
using namespace std;

vector<int> v, ret;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        v.push_back(m);
        ret.push_back(m);
    }
    sort(v.begin(), v.end());
    
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; i++) {
        cout << lower_bound(v.begin(), v.end(), ret[i]) - v.begin() << ' ';
    }

}