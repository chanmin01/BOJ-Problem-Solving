#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int water_visited[1504][1504], swan_visited[1504][1504], r, c, x, y, swanx, swany;
char a[1504][1504];
string s;
queue<pair<int, int>> swan_q, swan_temp, water_q, water_temp;

void water_melting() {
    while(water_q.size()) {
        tie(y, x) = water_q.front();
        water_q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || water_visited[ny][nx]) continue;
            if(a[ny][nx] == 'X') {
                water_visited[ny][nx] = 1;
                water_temp.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

bool swan_meeting() {
    while(swan_q.size()) {
        tie(y, x) = swan_q.front();
        swan_q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if(a[ny][nx] == '.')swan_q.push({ny, nx});
            else if(a[ny][nx] == 'X') swan_temp.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if(a[i][j] == 'L') {
                swany = i; swanx = j;
            }
            if(a[i][j] == '.' || a[i][j] == 'L') {
                water_q.push({i, j});
                water_visited[i][j] = 1;
            }
        }
    }
    swan_q.push({swany, swanx});
    swan_visited[swany][swanx] = 1;
    int cnt = 0;
    while(true) {
        if(swan_meeting()) break;
        water_melting();
        swan_q = swan_temp;
        water_q = water_temp;
        while(!swan_temp.empty()) {
            swan_temp.pop();
        }
        while(!water_temp.empty()) {
            water_temp.pop();
        }
        cnt++;
    }
    cout << cnt << '\n';

}