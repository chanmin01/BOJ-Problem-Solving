#include <bits/stdc++.h>
using namespace std;

int visited1[40], visited2[40], visited3[40];

int cnt = 0;
int n;
void func(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited1[i] || visited2[i + cur] || visited3[i - cur + n - 1]) continue;
        visited1[i] = 1;
        visited2[i + cur] = 1;
        visited3[i - cur + n - 1] = 1;
        func(cur + 1);
        visited1[i] = 0;
        visited2[i + cur] = 0;
        visited3[i - cur + n - 1] = 0;
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}