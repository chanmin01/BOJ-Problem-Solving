#include <bits/stdc++.h>
using namespace std;

int arr[10], num[10], n, m; 

void solve(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(temp != num[i]) {
            arr[k] = num[i];
            temp = arr[k];
            solve(k + 1);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);
    solve(0);

}