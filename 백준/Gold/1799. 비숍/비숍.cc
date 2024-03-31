#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> board[2][20]; // 색깔, \방향 
bool used[2][20];
int ans[2];
int N;

void bishop(int idx, int cnt, int color) {
    if(idx == 2 * N) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    for(auto v : board[color][idx]) {
        int x, y;
        tie(x, y) = v;
        if(used[color][x + y]) continue;
        used[color][x + y] = true;
        bishop(idx + 1, cnt + 1, color);
        used[color][x + y] = false;
    }
    bishop(idx + 1, cnt, color);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int d;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> d;
            if(d) {
                board[(i + j + 1) % 2][i - j + N - 1].push_back({i, j});
            }
        }
    }

    bishop(0, 0, 0);
    bishop(0, 0, 1);
    cout << ans[0] + ans[1] << '\n';
}