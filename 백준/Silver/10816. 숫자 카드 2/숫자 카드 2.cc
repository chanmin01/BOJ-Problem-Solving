#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0, m = 0;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        cout << upper_bound(a.begin(), a.end(), k) - lower_bound(a.begin(), a.end(), k) << ' ';
    }
}