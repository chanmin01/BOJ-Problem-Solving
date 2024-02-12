#include <bits/stdc++.h>
using namespace std;

vector<int> adj[103];
int n, node, u, v, visited[103], num;

int main() {
    cin >> n;
    cin >> node;
    while(node--) {
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
            if(visited[nxt]) continue;
            visited[nxt] = 1;
            num++;
            q.push(nxt);
        }
    }
    cout << num;
}