#include <bits/stdc++.h>
using namespace std;
int a;
string s;
list<char> l;
list<char>::iterator it;

void left() {
    if(it != l.begin()) {
        it--;
    }
}

void right() {
    if(it != l.end()) {
        it++;
    }
}

void rem() {
    if(it != l.begin()) {
        it--;
        it = l.erase(it);
    }
    
}

void ins(char k) {
    l.insert(it, k);
}


int main() {
    cin >> s;
    for(char a : s) {
        l.push_back(a);
    }
    cin >> a;
    it = l.end();
    while(a--) {
        char single;
        cin >> single;
        if(single == 'L') {
            left();
        }
        else if(single == 'D') {
            right();
        }
        else if(single == 'B') {
            rem();
        }
        else {
            char add;
            cin >> add;
            ins(add);
        }
    }
    for(char k : l) {
        cout << k;
    }
}