#include <bits/stdc++.h>
using namespace std;

int n, ropes[100004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ropes[i];
    }
    sort(ropes, ropes + n);
    int temp = 0;
    int standard = ropes[0] * n;
    for(int i = 1; i < n; i++) {
        temp = ropes[i] * (n - i);
        standard = max(standard, temp);
    }

    cout << standard;

}