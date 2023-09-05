#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[1004][1004], visited[1004][1004], x, y, m, n;
int main() {
    cin >> m >> n;
    int flag = 1;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == -1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && a[i][j] == 0) {
                flag = 0;
                break;
            }
            cnt = max(cnt, visited[i][j]);
        }
    }
    if(flag) cout << cnt - 1 << '\n';
    else cout << -1 << '\n';
}