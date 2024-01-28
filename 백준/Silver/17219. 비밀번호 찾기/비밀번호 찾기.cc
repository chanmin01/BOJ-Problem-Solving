#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, string> p_list;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(n--) {
		string cite, password;
		cin >> cite >> password;
		p_list[cite] = password;
	}
	for(int i = 0; i < m; i++) {
		string k;
		cin >> k;
		cout << p_list[k] << '\n';
	}
}