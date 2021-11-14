#include<bits/stdc++.h>
using namespace std;
int solution(int n) {
    int a = 1, b = 1, c = 1;
    for(int i = 2; i < n; i++){
        c = (a + b) % 1234567;
        a = b;
        b = c;
    }
    return c;
}
int main(){
    int n;
    cin >> n;
    cout << solution(n) << "\n";
}
