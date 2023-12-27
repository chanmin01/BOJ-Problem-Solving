#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[1003][1003], visited[1003][1003][2], y, x, ny, nx, m, n, crashed, ret;

int main() {
    cin >> n >> m;
    bool flag = false;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while(q.size()) {
        tie(y, x, crashed) = q.front();
        q.pop();
        if(y == n - 1 && x == m - 1) {
            flag = true;
            ret = visited[n - 1][m - 1][crashed];
            break;
        }
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx][crashed]) continue;
            if(a[ny][nx] == 0) {
                visited[ny][nx][crashed] = visited[y][x][crashed] + 1;
                q.push({ny, nx, crashed});
            }else if(a[ny][nx] == 1) {
                if(crashed == 1) continue;
                visited[ny][nx][crashed + 1] = visited[y][x][crashed] + 1;
                q.push({ny, nx, crashed + 1});
            }
        }
    }
    if(flag) {
        cout << ret + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }

}