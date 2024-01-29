#include <bits/stdc++.h>
using namespace std;

int test, m;

int main() {
	cin >> test;
	while(test--) {
		int ret = 1;
		unordered_map<string, int> mp;
		cin >> m;
		while(m--) {
			string a, b;
			cin >> a >> b;
			++mp[b];
		}
		for(pair<string, int> i : mp) {
			ret *= i.second + 1;
		}
		cout << ret  - 1 << '\n';
	}
}