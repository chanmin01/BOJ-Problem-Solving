#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char a[1004][1004];
int n, m, sx, sy, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, ret, y, x;
int f_check[1004][1004], j_check[1004][1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    queue<pair<int, int>> q;
    cin >> n >> m;
    fill(&f_check[0][0], &f_check[0][0] + 1004 * 1004, INF);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'F') {
                f_check[i][j] = 1; q.push({i, j});
            } else if(a[i][j] == 'J') {
                sy = i; sx = j;
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
            if(f_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            f_check[ny][nx] = f_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    j_check[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        if(x == m - 1 || y == n - 1 || x == 0 || y == 0) {
            ret = j_check[y][x];
            break;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(j_check[ny][nx] || a[ny][nx] == '#') continue;
            if(f_check[ny][nx] <= j_check[y][x] + 1) continue;
            j_check[ny][nx] = j_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE" << '\n';
    return 0;
}