#include<bits/stdc++.h>
using namespace std;
set<int> dp[10];
int N;
set<int> go(int k){
    set<int> &ret = dp[k];
    if(!ret.empty()) return dp[k];
    int num = 0;
    for(int i = 0; i < k; i++) num = num * 10 + N;
    ret.insert(num);
    for(int i = 1; i < k; i++){
        set<int> s1 = go(i);
        set<int> s2 = go(k - i);
        for(int n1 : s1){
            for(int n2 : s2){
                ret.insert(n1 + n2);
                ret.insert(n1 - n2);
                ret.insert(n1 * n2);
                if(n2 != 0) ret.insert(n1 / n2);
            }
        }
    }
    return ret;
}
int solution(int _N, int number) {
    N = _N;
    for(int i = 1; i <= 8; i++){
        dp[i] = go(i);
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    return -1;
}
int main(){
    int N, number;
    cin >> N >> number;
    cout << solution(N, number) << "\n"; 
}