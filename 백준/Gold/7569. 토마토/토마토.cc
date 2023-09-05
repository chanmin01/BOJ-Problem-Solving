#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int m, n, h, a[104][104][104], visited[104][104][104], x, y, z;

int main() {
    cin >> m >> n >> h;
    int flag = 1;
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> a[i][j][k];
                if(a[i][j][k] == 1) {
                    q.push({i, j, k});
                    visited[i][j][k] = 1;
                }
            }
        }
    }

    while(q.size()) {
        tie(z, y, x) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h) continue;
            if(visited[nz][ny][nx] || a[nz][ny][nx] == -1) continue;
            visited[nz][ny][nx] = visited[z][y][x] + 1;
            q.push({nz, ny, nx});
        }
        
    }
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(!visited[i][j][k] && a[i][j][k] == 0) {
                    flag = 0;
                    break;
                }
                cnt = max(cnt, visited[i][j][k]);
            }
            if(!flag) break;
        }
        if(!flag) break;
    }
    if(flag) cout << cnt - 1 << '\n';
    else cout << -1 << '\n';
}