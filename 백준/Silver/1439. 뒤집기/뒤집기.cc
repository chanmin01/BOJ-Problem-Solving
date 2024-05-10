#include <bits/stdc++.h>
using namespace std;

string s;
int num_count[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int sequence = s[0] - '0';
    num_count[sequence]++;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] - '0' == sequence) {
            continue;
        } else {
            sequence = s[i] - '0';
            num_count[sequence]++;
        }
    }
    cout << min(num_count[0], num_count[1]);

}