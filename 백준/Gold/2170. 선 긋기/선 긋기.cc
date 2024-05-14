#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> lines;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll st, ed;
    for(int i = 0; i < n; i++) {
        cin >> st >> ed;
        lines.push_back({st, ed});
    }

    sort(lines.begin(), lines.end());
    
    ll sum = 0;
    int start = lines[0].first;
    int end = lines[0].second;

    for(int i = 1; i < n; i++) {
        if(lines[i].first <= end) {
            end = max(end, lines[i].second);
        } else {
            sum += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }

    sum += end - start;

    cout << sum << '\n';

}