#include<bits/stdc++.h>
using namespace std;
int count(int num){
    int ret = 1;
    for(int i = 1; i <= num / 2; i++){
        if(num % i == 0) ret++;
    }
    return ret;
}
int solution(int left, int right) {
    int answer = 0;
    int cnt;
    for(int i = left; i <= right; i++){
        if(count(i) % 2) answer -= i;
        else answer += i;
    }
    return answer;
}
int main(){
    int l, r;
    cin >> l >> r;
    cout << solution(l , r) << "\n";
}