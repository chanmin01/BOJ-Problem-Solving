#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int r, c, visited[24][24], cnt = 1, max_; 
char a[24][24];
vector<char> v;
string s;

void dfs(int y, int x, int cnt) {
    max_ = max(max_, cnt);
    visited[y][x] = 1;
    v.push_back(a[y][x]);
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
        if(find(v.begin(), v.end(), a[ny][nx]) != v.end()) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
        v.pop_back();
    }
    return;
}

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }
    dfs(0, 0, 0);

    cout << max_ + 1 << '\n';
}