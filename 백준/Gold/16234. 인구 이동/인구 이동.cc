#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, l, r, visited[54][54], a[54][54], ret;
vector<pair<int, int>> a_list;
vector<int> vin;
vector<vector<int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r) {
            vin.push_back(a[ny][nx]);
            a_list.push_back({ny, nx});
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    a_list.clear();
                    vin.clear();
                    vin.push_back(a[i][j]);
                    a_list.push_back({i, j});
                    dfs(i, j);
                    v.push_back(vin);
                }
                if(vin.size() != 1) {
                    int num = accumulate(vin.begin(), vin.end(), 0) / vin.size();
                    for(pair<int, int> p : a_list) {
                        a[p.first][p.second] = num;
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        ret++;
    }
    cout << ret << '\n';
}