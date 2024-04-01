
#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int board[505][505], visited[505][505], cnt, mx;
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                int curArea = 0;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    curArea++;
                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || !board[ny][nx]) continue;
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
                cnt++;
                mx = max(mx, curArea);
            }
        }
    }
    cout << cnt << '\n' << mx;
    return 0;
}
