#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[303][303], visited[303][303], a_copy[303][303], n, m, y, x, ny, nx, ret;
bool flag = false;

bool allMapZero() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 0) return false;
        }
    }
    return true;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}

bool check() {
    fill(&visited[0][0], &visited[0][0] + 303 * 303, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 0 && !visited[i][j]) {
                dfs(i, j); cnt++;
            }
        }
    }
    return cnt >= 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while(true) {
        if(check()) {
            flag = true; break;
        }else if(allMapZero()) break;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a_copy[i][j] = a[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a_copy[i][j]) {
                    int cnt = 0; 
                    for(int d = 0; d < 4; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a_copy[ny][nx]) continue;
                        cnt++;
                    }
                    a[i][j] = max(a_copy[i][j] - cnt, 0);
                } 
            }
        }
        
        ret++;
    }
    if(flag) cout << ret << '\n';
    else cout << 0 << '\n';
}