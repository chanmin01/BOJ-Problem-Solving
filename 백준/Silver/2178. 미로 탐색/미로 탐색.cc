#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1] << '\n';
}