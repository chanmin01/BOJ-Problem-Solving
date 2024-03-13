#include <bits/stdc++.h>
using namespace std;

int arr[10], visited[10], num[10], n, m; 

void solve(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    int a = 0;
    if(k != 0) a = arr[k - 1];
    for(int i = 0; i < n; i++) {
        if(!visited[i] && temp != num[i] && num[i] >= a) {
            arr[k] = num[i];
            visited[i] = 1;
            temp = arr[k];
            solve(k + 1);
            visited[i] = 0;
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