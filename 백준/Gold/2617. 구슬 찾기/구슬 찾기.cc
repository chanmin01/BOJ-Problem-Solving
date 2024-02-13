#include <bits/stdc++.h>
using namespace std;

vector<int> adj_bigger[103], adj_smaller[103];
vector<int> bigger, smaller;
int u, v, n, m, visited[103], cnt, ret;

void dfs(int i, vector<int> adj[]) {
    visited[i] = 1;
    cnt++;
    for(auto nxt : adj[i]) {
        if(visited[nxt]) continue;
        dfs(nxt, adj);
    }
}

int main() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj_smaller[u].push_back(v);
        adj_bigger[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 103, 0);
        cnt = 0;
        dfs(i, adj_bigger);
        bigger.push_back(cnt - 1);
    }
    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 103, 0);
        cnt = 0;
        dfs(i, adj_smaller);
        smaller.push_back(cnt - 1);
    }
    for(int i : bigger) {
        if(i >= (n + 1) / 2) {
            ret++;
        }
    }
    for(int i : smaller) {
        if(i >= (n + 1) / 2) {
            ret++;
        }
    }
    cout << ret;
}