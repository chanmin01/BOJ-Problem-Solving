#include <bits/stdc++.h>
using namespace std;

int adj[103][103], visited[103], n, me, ret[103][103];


int dfs(int v) {
    for(int nxt = 0; nxt < n; nxt++) {
        if(visited[nxt])continue;
        if(adj[v][nxt]) {
            visited[nxt] = 1;
            dfs(nxt);
        }
    }
    return 0;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        fill(visited, visited + 103, 0);
        dfs(i);
        for(int j = 0; j < n; j++) {
            if (visited[j]) ret[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
    
}
