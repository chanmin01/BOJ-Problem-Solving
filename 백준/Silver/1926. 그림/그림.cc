#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[504][504], visited[504][504], n, m, x, y;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int mx = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 || visited[i][j]) continue;
            int area = 0;
            cnt++;
            visited[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(q.size()) {
                area++;
                tie(y, x) = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if(visited[ny][nx] || a[ny][nx] == 0) continue;
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << cnt << '\n' << mx;
}