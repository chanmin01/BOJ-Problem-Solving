#include <bits/stdc++.h>
using namespace std;
int n, num[104];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int count = 0;
    int temp = num[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(num[i] >= temp) {
            while(num[i] >= temp) {
                num[i] -= 1;
                count++;
            }
        }
        temp = num[i];
    }
    
    cout << count;
}