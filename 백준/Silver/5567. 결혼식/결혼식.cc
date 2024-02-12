#include <bits/stdc++.h>
using namespace std;

vector<int> adj[504];
int n, m, visited[504], u, v, num;

int main() {
    cin >> n;
    cin >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
            if(visited[nxt])continue;
            visited[nxt] = visited[cur] + 1;
            q.push(nxt);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] && visited[i] <= 3) num++;
    }

    cout << num - 1;
}