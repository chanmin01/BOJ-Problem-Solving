#include <bits/stdc++.h>
using namespace std;

int a[200003], visited[200003], n, k;

int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(q.size()) {
        int current = q.front();
        q.pop();

        int teleport = current * 2;
        if (teleport <= 200000 && !visited[teleport]) {
            visited[teleport] = visited[current];
            q.push(teleport);
        }

        for (int next : {current - 1, current + 1}) {
            if (next >= 0 && next <= 200000 && !visited[next]) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
        
    }
    cout << visited[k] - 1;
}