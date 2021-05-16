#include<bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    string answer = "";
    int cnt[10] = {0, };
    while(n > 0){
        cnt[n % 10]++;
        n /= 10;
    }
    
    for(int i = 9; i > -1; i--){
        for(int j = 0; j < cnt[i]; j++){
            answer += i + '0';
        }
    }
    return stoll(answer);
}