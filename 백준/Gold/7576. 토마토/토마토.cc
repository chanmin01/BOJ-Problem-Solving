#include <bits/stdc++.h>
using namespace std;

int m, n, board[1004][1004], visited[1004][1004], x, y;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
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
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || board[ny][nx] == -1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    bool is_all = true;
    int mx = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] > mx) mx = max(mx, visited[i][j]);
            if(board[i][j] == 0 && !visited[i][j]) is_all = false;
        }
    }

    if(is_all)  {
        cout << mx - 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
    
}