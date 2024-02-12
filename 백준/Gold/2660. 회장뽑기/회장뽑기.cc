#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int visited[55], u, v, n;
vector<pair<int, int>> ret;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    cin >> n;
    while(true) {
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 53, 0);
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]) {
                if(visited[nxt]) continue;
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }
        }
        int m = *max_element(visited, visited + 55);
        ret.push_back({i, m - 1});
    }
    sort(ret.begin(), ret.end(), cmp);
    int point = ret.front().second;
    int cnt = 0;
    for(auto i : ret) {
        if(i.second == point) {
            cnt++;
        }
    }
    cout << point << ' ' << cnt << '\n';
    for(auto i : ret) {
        if(i.second == point) {
            cout << i.first << ' ';
        }
    }
}