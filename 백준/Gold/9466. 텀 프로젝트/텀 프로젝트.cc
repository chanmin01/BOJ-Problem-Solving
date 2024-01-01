#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> students;
vector<bool> visited, finished;

void dfs(int current) {
    visited[current] = true;
    int next = students[current];

    if(!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        for (int i = next; i != current; i = students[i]) {
            cnt++;
        }
        cnt++;
    }
    finished[current] = true;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        cin >> n;
        students.assign(n + 1, 0);
        visited.assign(n + 1, false);
        finished.assign(n + 1, false);
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            cin >> students[i];
        }
        for (int i = 1; i <= n; i++) {
            if(!visited[i]) dfs(i);
        }

        cout << n - cnt << '\n';
    }
    return 0;
}