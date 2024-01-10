#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[103][10003];

void compress(int k[]) {
    vector<int> v(k, k + n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; i++) {
        k[i] = lower_bound(v.begin(), v.end(), k[i]) - v.begin();
    }
}

bool check(int a[], int b[]) {
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        compress(a[i]);
    }
    int cnt = 0; 

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(check(a[i], a[j])) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';

}