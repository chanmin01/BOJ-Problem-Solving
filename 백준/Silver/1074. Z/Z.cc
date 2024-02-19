#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int func(int n, int a, int b) {
    if(n == 0) return 0;
    int half = 1<<(n - 1);
    if(a < half && b < half) return func(n - 1, a, b);
    if(a < half && b >= half) return half * half + func(n - 1, a, b - half);
    if(a >= half && b < half) return half * half * 2 + func(n - 1, a - half, b);
    return half * half * 3 + func(n - 1, a - half, b - half);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    cout << func(n, a, b);
}
