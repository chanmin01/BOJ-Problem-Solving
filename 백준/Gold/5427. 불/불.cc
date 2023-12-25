#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[1003][1003];
int visited_f[1003][1003], visited_s[1003][1003], m, n, y, x, ny, nx;

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> m >> n;
        string s;
        bool flag = false;
        fill(&a[0][0], &a[0][0] + 1003 * 1003, 0);
        fill(&visited_f[0][0], &visited_f[0][0] + 1003 * 1003, 0);
        fill(&visited_s[0][0], &visited_s[0][0] + 1003 * 1003, 0);
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < m; j++) {
                a[i][j] = s[j];
                if(a[i][j] == '*') {
                    q1.push({i, j});
                    visited_f[i][j] = 1;
                } 
                else if(a[i][j] == '@') {
                    q2.push({i, j});
                    visited_s[i][j] = 1;
                }
            }
        }
        while(q1.size()) {
            tie(y, x) = q1.front();
            q1.pop();
            for(int i = 0; i < 4; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited_f[ny][nx]) continue;
                if(a[ny][nx] == '#') continue;
                visited_f[ny][nx] = visited_f[y][x] + 1;
                q1.push({ny, nx});
            }
        }

        while(q2.size() && (!flag)) {
            tie(y, x) = q2.front();
            q2.pop();
            for(int i = 0; i < 4; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    cout << visited_s[y][x] << '\n';
                    flag = true;
                    break;
                }
                if(a[ny][nx] == '#' || a[ny][nx] == '*' || visited_s[ny][nx]) continue;
                if(visited_f[ny][nx] != 0 && visited_f[ny][nx] <= visited_s[y][x] + 1) continue;
                visited_s[ny][nx] = visited_s[y][x] + 1;
                q2.push({ny, nx});
            }
        }
        if(!flag) {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    
}