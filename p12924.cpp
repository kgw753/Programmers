#include<bits/stdc++.h>
using namespace std;
int solution(int n) {
    int ret = 0, sum = 0;
    int l = 1;
    for(int r = 1; r <= n; r++){
        sum += r;
        if(sum >= n){
            while(sum > n) sum -= l++;
            if(sum == n) ret++;
        }
    }
    return ret;
}
int main(){
    int N;
    cin >> N;
    cout << solution(N) << "\n";
}