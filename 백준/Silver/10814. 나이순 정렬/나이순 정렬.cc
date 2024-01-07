#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string s;
    cin >> n;
    while(n--) {
        cin >> k >> s;
        v.push_back({k, s}); 
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto it : v) {
        cout << it.first << ' ' << it.second << '\n';
    }
}