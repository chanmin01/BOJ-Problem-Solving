#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
char a[301][301];
int n, m, x_f, y_f, x_s, y_s, y, x;
int visited[301][301];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret;
queue<pair<int, int>> q;
int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y_f, &x_f, &y_s, &x_s);
    y_f--, x_f--, y_s--, x_s--;
    for(int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    q.push({y_f, x_f});
    visited[y_f][x_f] = 1;
    int cnt = 0;
    while(a[y_s][x_s] != '0') {
        cnt++;
        queue<pair<int, int>> temp;
        while(q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                }
                else q.push({ny, nx});
            }

        }
        q = temp;
    }
    printf("%d\n", visited[y_s][x_s]);

}



