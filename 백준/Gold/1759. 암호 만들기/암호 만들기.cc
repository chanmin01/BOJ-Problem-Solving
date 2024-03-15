#include <bits/stdc++.h>
using namespace std;

int l, c, visited[20];
char str[20], arr[20];

bool check(char str[]) {
    int ja = 0;
    int mo = 0;
    for(int i = 0; i < l; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') mo++;
        else ja++;
    }
    if(mo >= 1 && ja >= 2) return true;
    else return false;
}

void solve(int k) {
    if(k == l) {
        if(check(arr)) {
            for(int i = 0; i < l; i++) {
                cout << arr[i];
            }
            cout << '\n';
        }
        return;
    }
    int a = -1;
    if(k != 0) a = arr[k - 1] - 'a';

    for(int i = 0; i < c; i++) {
        if(!visited[i] && a < (str[i] - 'a')) {
            arr[k] = str[i];
            visited[i] = 1;
            solve(k + 1);
            visited[i] = 0;
        }
    }

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;

    //최소 한 개의 모음과 두 개의 자음
    for(int i = 0; i < c; i++) {
        cin >> str[i];
    }

    sort(str, str + c);

    solve(0);
}