#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int move(int n, int r, int c) {
    if(n == 0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) return move(n - 1, r, c);
    if(r < half && c >= half) return half * half + move(n - 1, r, c - half);
    if(r >= half && c < half) return 2 * half * half + move(n - 1, r - half, c);
    return 3 * half * half + move(n - 1, r - half, c - half);
}


int main() {
    ios::sync_with_stdio;
    cin.tie(0);
    cin >> n >> r >> c;
    cout << move(n, r, c);
}