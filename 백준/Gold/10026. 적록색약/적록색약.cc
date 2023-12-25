#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[103][103], color[] = {'R', 'G', 'B'}, color_disable[] = {'R', 'B'};
int visited[103][103], x, y, nx, ny, n, cnt;

void dfs(int y, int x, char k) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || a[ny][nx] != k) continue;
        dfs(ny, nx, k);
    }
}

int main() {
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    int k = 3;
    while(k--) {
        fill(&visited[0][0], &visited[0][0] + 103 * 103, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(a[i][j] == color[k] && !visited[i][j]) {
                    dfs(i, j, color[k]);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'G') {
                a[i][j] = 'R';
            }
        }
    }

    k = 2;
    while(k--) {
        fill(&visited[0][0], &visited[0][0] + 103 * 103, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(a[i][j] == color_disable[k] && !visited[i][j]) {
                    dfs(i, j, color_disable[k]);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}