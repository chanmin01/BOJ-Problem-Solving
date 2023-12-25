#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int a[303][303], visited[303][303], y, x, ny, nx, oy, ox;

int main() {
    int n, m;
    cin >> n;

    while(n--) {
        fill(&a[0][0], &a[0][0] + 303 * 303, 0);
        fill(&visited[0][0], &visited[0][0] + 303 * 303, 0);
        cin >> m;
        cin >> y >> x;
        cin >> oy >> ox;
        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = 1;
        while(q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= m || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
        cout << visited[oy][ox] - 1 << '\n';
    }
}