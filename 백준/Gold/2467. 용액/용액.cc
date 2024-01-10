#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> solutions(n);

    for (int i = 0; i < n; i++) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    int left = 0, right = n - 1;
    int min_diff = INT_MAX;
    pair<int, int> result;

    while (left < right) {
        int sum = solutions[left] + solutions[right];

        //차이가 더 작은 쌍을 찾으면 결과를 갱신
        if (abs(sum) < min_diff) {
            min_diff = abs(sum);
            result = {solutions[left], solutions[right]};
        }

        //합을 조정
        if (sum < 0) left++;
        else right--;
    }

    cout << result.first << ' ' << result.second << '\n';
    return 0;

}