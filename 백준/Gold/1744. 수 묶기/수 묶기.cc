#include <bits/stdc++.h>
using namespace std;
vector<int> positive, negative;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num > 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    int sum = 0;

    for(int i = 0; i < positive.size(); i++) {
        if(i + 1 < positive.size() && positive[i + 1] > 1) {
            sum += positive[i] * positive[i + 1];
            ++i;
        } else {
            sum += positive[i];
        }
    }

    for(int i = 0; i < negative.size(); i++) {
        if(i + 1 < negative.size()) {
            sum += negative[i] * negative[i + 1];
            ++i;
        } else {
            sum += negative[i];
        }
    }

    cout << sum;
}