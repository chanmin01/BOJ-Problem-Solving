#include <bits/stdc++.h>
using namespace std;

int k, u, v, num, nodes, visited[20003];

int main() {
    cin >> k;
    while(k--) {
        cin >> num >> nodes;
        fill(&visited[0], &visited[0] + 20003, -1);
        vector<int> adj[20003];
        while(nodes--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool check = true;
        for(int i = 1; i <= num; i++) {
            if(visited[i] != -1) continue;
            queue<int> q;
            q.push(i);
            visited[i] = 0;
            while(q.size()) {
                int cur = q.front();
                q.pop();
                for(auto nxt : adj[cur]) {
                    if(visited[nxt] != -1) {
                        if(visited[nxt] == visited[cur]) {
                            check = false;
                            break;
                        }
                        else continue;
                    }
                    visited[nxt] = (visited[cur] + 1) % 2;
                    q.push(nxt);
                }
                if(!check) break;
            }
        }
        
        
        if(check) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}