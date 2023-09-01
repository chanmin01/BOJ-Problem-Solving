#include <bits/stdc++.h>
using namespace std;

const int _max = 200000;
int n, k, visited[_max + 4], trace[_max + 4], ret;
vector<int> v;

int main() {
    cin >> n >> k;

    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(q.size()) {
        int here = q.front();
        q.pop();
        if(here == k) {
            ret = visited[here];
            break;
        }
        for(int there : {here + 1, here - 1, here * 2}) { 
            if(there < 0 || there >= _max || visited[there]) continue;
            visited[there] = visited[here] + 1;
            trace[there] = here;
            q.push(there);
        }
    }

    for(int i = k; i != n; i = trace[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << ret - 1 << '\n';
    for(int a : v) {
        cout << a << ' ';
    } 
    return 0;
}