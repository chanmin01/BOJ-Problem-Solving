#include <bits/stdc++.h>
using namespace std;
int n, m, arr[10], visited[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            arr[k] = i;
            visited[i] = 1;
            func(k + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
}