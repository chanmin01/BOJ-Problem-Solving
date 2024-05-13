#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;                 // 카드의 개수
	int m;                 // 카드 합체를 몇번 하는지

	// 아래 변수들은 값의 범위가 크기 때문에, long long 형 필요
	long long card[1000];  // 카드의 숫자
	long long sum;         // 카드 두 장을 골라 합한 값
	long long min_sum = 0; // 만들 수 있는 가장 작은 점수

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	// 오름차순 정렬
	sort(card, card + n);

	// 카드 합체
	for (int i = 0; i < m; i++) {
		sum = card[0] + card[1];
		card[0] = sum;
		card[1] = sum;
		sort(card, card + n);
	}

	for (int i = 0; i < n; i++) {
		min_sum += card[i];
	}

	cout << min_sum;

	return 0;
}