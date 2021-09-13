#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> t;
bool check(ll k){
    long long cnt = 0;
    for(int i = 0; i < t.size(); i++){
        cnt += k / t[i];
    }
    return cnt >= N;
}
ll solution(int n, vector<int> times) {
    ll lo, hi, mid, answer = 1e18;
    N = n, t = times;
    lo = 0, hi = 1e18;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            answer = min(answer, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return answer;
}
int main(){
    int N, M;
    cin >> N, M;
    vector<int> v(M);
    for(int i = 0; i < M; i++) cin >> v[i];
    cout << solution(N, v) << "\n";
}