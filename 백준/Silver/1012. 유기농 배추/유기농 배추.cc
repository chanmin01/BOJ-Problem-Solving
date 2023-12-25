#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[53][53], visited[53][53], x, y, nx, ny, m, n, cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    int case_num;
    cin >> case_num;
    while(case_num--) {
        fill(&a[0][0], &a[0][0] + 53 * 53, 0);
        fill(&visited[0][0], &visited[0][0] + 53 * 53, 0);
        cnt = 0;
        int p;
        cin >> n >> m >> p;
        while(p--) {
            int k, b;
            cin >> k >> b;
            a[b][k] = 1;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}