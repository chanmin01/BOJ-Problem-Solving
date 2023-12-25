#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int a[103][103][103], visited[103][103][103], y, x, z, ny, nx, nz;

int main() {
    int n, m, h;
    bool flag = true;
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> a[i][j][k];
                if(a[i][j][k] == 1) {
                    q.push({i, j, k});
                    visited[i][j][k] = 1;
                } else if (a[i][j][k] == 0){
                    flag = false;
                }
            }
        }
    }
    if(flag) {
        cout << 0;
        return 0;
    }

    while(q.size()) {
        tie(z, y, x) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            nz = z + dz[i];
            if(ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h || visited[nz][ny][nx] || a[nz][ny][nx] != 0) continue;
            visited[nz][ny][nx] = visited[z][y][x] + 1;
            q.push({nz, ny, nx});
        }
    }
    int ret = -10000000;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(visited[i][j][k] == 0 && a[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                ret = max(ret, visited[i][j][k] - 1);
            }
        }
    }
    cout << ret;
}