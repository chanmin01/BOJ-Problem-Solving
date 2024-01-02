#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[103][103], visited[103][103], map_id[103][103], y, x, ny, nx, n, cnt = 1, ret = INF;

void setMapId(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    map_id[y][x] = cnt;
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop(); 
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || map_id[ny][nx] || a[ny][nx] == 0) continue;
                q.push({ny, nx});
                map_id[ny][nx] = cnt;
        }
    }
}

int bfs(int y, int x) {
    fill(&visited[0][0], &visited[0][0] + 103 * 103, 0);
    queue<pair<int, int>> q;
    bool ok = false;
    int ret = INF;
    int here_cnt = map_id[y][x];
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop(); 
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || here_cnt == map_id[ny][nx]) continue;
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                if(here_cnt != map_id[ny][nx] && (map_id[ny][nx] != 0)) {
                    ok = true;
                    ret = visited[ny][nx];
                    break;
                }
        }
        if(ok) break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && !map_id[i][j]) {
                setMapId(i, j);
                cnt++;
            }
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map_id[i][j]) ret = min(ret, bfs(i, j));
        }
    }
    cout << ret - 2;
}