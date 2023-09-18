#include <bits/stdc++.h>
using namespace std;

int a;
string s;

list<char> L;
list<char>::iterator it;

void left() {
    if (it != L.begin()) {
        it--;
    }
}

void right() {
    if (it != L.end()) {
        it++;
    }
}

void rem() {
    if (it != L.begin()) {
        it--;
        it = L.erase(it);
    }
}

void ins(char single) {
    L.insert(it, single);
}

int main() {
    cin >> a;

    while (a--) {
        cin >> s;
        L.clear(); // 리스트 초기화
        it = L.begin();

        for (char k : s) {
            if (k == '<') {
                left();
            } else if (k == '>') {
                right();
            } else if (k == '-') {
                rem();
            } else {
                ins(k);
            }
        }

        for (char k : L) {
            cout << k;
        }
        cout << '\n';
    }

    return 0;
}
