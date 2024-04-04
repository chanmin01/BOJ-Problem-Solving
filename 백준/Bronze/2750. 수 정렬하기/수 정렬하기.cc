#include <bits/stdc++.h>
using namespace std;
int n;
int board[1004];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    sort(board, board + n);
    for(int i = 0; i < n; i++) {
        cout << board[i] << '\n';
    }
}