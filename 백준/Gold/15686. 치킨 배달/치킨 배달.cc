#include <bits/stdc++.h>
using namespace std;

int a[54][54], n, m, result = 987654321;
vector<vector<int>> selected_chicken;
vector<pair<int,int>> chicken, house;

void combi(int start, vector<int> v) {
    if(v.size() == m) {
        selected_chicken.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) house.push_back({i, j});
            if(a[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combi(-1, v);
    for(vector<int> select : selected_chicken) {
        int ret = 0;
        for(pair<int, int> home : house) {
            int _min = 987654321;
            for(int idx : select) {
                int dist = abs(home.first - chicken[idx].first) + abs(home.second - chicken[idx].second);
                _min = min(_min, dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }

    cout << result << '\n';
    return 0;

}