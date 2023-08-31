#include <bits/stdc++.h>
using namespace std;

const int max_n = 200000;
long long cnt[max_n + 4];
int n, k, visited[max_n + 4], ret;

int main() {
    cin >> n >> k;
    if(n == k) {
        puts("0"); puts("1");
        return 0;
    }
    queue<int> q;
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while(q.size()) {
        int here = q.front();
        q.pop();
        if(here == k) {
            ret = visited[k];
            break;
        }
        for(int next : {here + 1, here - 1, here * 2}) {
            if(next >= max_n || next < 0) continue;
            if(!visited[next]) {
                q.push(next);
                visited[next] = visited[here] + 1;
                cnt[next] += cnt[here];
            } else if (visited[next] == visited[here] + 1) {
                cnt[next] += cnt[here];
            }
            
        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return 0;
}