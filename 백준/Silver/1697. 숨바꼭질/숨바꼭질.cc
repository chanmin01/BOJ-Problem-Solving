#include <bits/stdc++.h>
using namespace std;

int a[100002], n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fill(a, a + 100001, -1);
    a[n] = 0;
    queue<int> q;
    q.push(n);
    while(a[k] == -1) {
        int x = q.front();
        q.pop();
        for(int j : {x + 1, x - 1, x * 2}) {
            int nx = j;
            if(nx < 0 || nx > 100000) continue;
            if(a[nx] != -1) continue;
            a[nx] = a[x] + 1;
            q.push(nx);
        }
    }
    cout << a[k];
    
}