#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, m, t;
    cin>>h>>m>>t;
    
    h += t / 60;
    m += t % 60;
    
    if(m >= 60){
        h += 1;
        m -= 60;
    }
    if(h >= 24){
        h -= 24;
    }
    
    cout<<h<<" "<<m;
    return 0;
}