#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        string p, arr_str;
        int m;
        cin >> p >> m >> arr_str;
        
        // Process the input string to build the deque directly
        deque<int> DQ;
        for (int i = 0, num = 0; i < arr_str.size(); i++) {
            if (isdigit(arr_str[i])) {
                num = num * 10 + (arr_str[i] - '0');
            }
            else if (num != 0) {
                DQ.push_back(num);
                num = 0;
            }
        }
        
        bool reversed = false;
        int front = 0, back = DQ.size();
        bool error = false;
        
        for (char c : p) {
            if (c == 'R') {
                reversed = !reversed;
            }
            else if (c == 'D') {
                if (front < back) {
                    if (reversed) {
                        back--;
                    } else {
                        front++;
                    }
                } else {
                    error = true;
                    break;
                }
            }
        }
        
        if (error) {
            cout << "error" << '\n';
        } else {
            cout << '[';
            if (reversed) {
                for (int i = back - 1; i >= front; i--) {
                    cout << DQ[i];
                    if (i != front) {
                        cout << ',';
                    }
                }
            } else {
                for (int i = front; i < back; i++) {
                    cout << DQ[i];
                    if (i != back - 1) {
                        cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
    
    return 0;
}
