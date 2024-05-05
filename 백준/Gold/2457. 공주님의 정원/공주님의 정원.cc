#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n;
vector<pair<int, int>> flower;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sm, sd, em, ed;
    for(int i = 0; i < n; i++) {
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed});
    }
    int t = 301;
    int ret = 0;
    while(t < 1201) {
        int nxt_t = t;
        for(int i = 0; i < n; i++) {
            if(flower[i].X <= t && flower[i].Y > nxt_t) {
                nxt_t = flower[i].Y;
            }
        }

        if(t == nxt_t) {
            ret = 0;
            cout << 0;
            return 0;
        }

        ret++;
        t = nxt_t;
    }
    cout << ret;
}