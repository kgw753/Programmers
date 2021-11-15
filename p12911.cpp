#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int counting(int n){
    int ret = 0;
    while(n > 0){
        if(n & 1) ret++;
        n = n >> 1;
    }
    return ret;
}
int solution(int n) {
    int answer = 0;
    int bitCnt = counting(n);
    for(int i = n + 1; i < MAX; i++){
        if(counting(i) == bitCnt){
            answer = i;
            break;
        }
    }
    return answer;
}
int main(){
    int N;
    cin >> N;
    cout << solution(N) << "\n";
}