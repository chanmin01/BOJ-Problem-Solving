#include <bits/stdc++.h>
using namespace std;

long long dp[1500003], t[1500003], p[1500003];
int n;

int main() {
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> t[i] >> p[i];

	for(int i=n-1; i>=0; i--) {
		int pos=i+t[i]; 
		if(pos<=n)
			dp[i]=max(dp[pos]+p[i], dp[i+1]); 
		else
			dp[i]=dp[i+1]; 
	}
	cout << dp[0];
}