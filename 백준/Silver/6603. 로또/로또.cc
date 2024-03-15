#include <bits/stdc++.h>
using namespace std;

int k, arr[15], visited[15], num[15];

void solve(int n) {
    if(n == 6) {
        for(int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    int a = 0;
    if(n != 0) a = arr[n - 1];
    for(int i = 0; i < k; i++) {
        if(!visited[i] && a < num[i]) {
            arr[n] = num[i];
            visited[i] = 1;
            solve(n + 1);
            visited[i] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            cin >> num[i];
        }
        solve(0);
        fill(&num[0], &num[0] + 15, 0);
        cout << '\n';
    }
}