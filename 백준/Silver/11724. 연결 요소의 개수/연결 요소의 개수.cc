#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
int n, m, visited[1003];

int main() {
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int num = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        num++;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]) {
                if(visited[nxt]) continue;
                q.push(nxt);
                visited[nxt] = 1;
            }
        }
    }
    cout << num;
}