#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
// 변의 길이, 걸어간 거리로 x, y좌표값을 재귀적으로 계산
pair<int,int> philo(int side, int walk) {
  // Base case: 변의 길이가 2^1인 경우
  if (side == 2) {
    switch (walk) {
      case 1:
        return {1, 1};
      case 2:
        return {1, 2};
      case 3:
        return {2, 2};
      case 4:
        return {2, 1};
    }
  }
  int half = side / 2, section = half * half;
  // walk가 속하는 범위에 따라 계산
  if (walk <= section) {
    pair<int,int> rv = philo(half, walk);
    return {rv.Y, rv.X};
  }
  else if (walk <= 2 * section) {
    pair<int,int> rv = philo(half, walk - section);
    return {rv.X, half + rv.Y};
  }
  else if (walk <= 3 * section) {
    pair<int,int> rv = philo(half, walk - 2 * section);
    return {half + rv.X, half + rv.Y};
  }
  else {
    pair<int,int> rv = philo(half, walk - 3 * section);
    return {2 * half - rv.Y + 1, half - rv.X + 1};
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int side, walk;
  cin >> side >> walk;
  pair<int,int> ans = philo(side, walk);
  cout << ans.X << " " << ans.Y;
}
