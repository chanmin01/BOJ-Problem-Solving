#include <bits/stdc++.h>
using namespace std;

int k, l, s;
unordered_map<string, int> mp;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> l;
	for(int i = 0; i < l; i++) {
		string student_num;
		cin >> student_num;
		if(mp.find(student_num) != mp.end()) {
			mp.erase(student_num);
			mp[student_num] = i;
		} else {
			mp[student_num] = i;
		}
	}
	vector<pair<string, int>> slist (mp.begin(), mp.end());
	sort(slist.begin(), slist.end(), cmp);
	int en = min(k, (int)slist.size());
	for(int i = 0; i < en; i++) {
		cout << slist[i].first << '\n';
	}
}