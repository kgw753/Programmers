#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int count(int lo, int hi){
    int ret = 0;
    for(int i = lo; i <= hi; i++) {
        ret += s[i];
    }
    return ret;
}
int solution(vector<int> student, int k) {
    s = student;
    int lo = 0, hi = 0;
    int answer = 0;
    while(lo != s.size() && hi != s.size()){
        if(count(lo, hi) == k) {
            answer++;
            if(hi + 1 == s.size()){
                lo++;
                hi = lo;
            }
            else if(s[hi + 1]) lo++;
            else hi++;
        }
        else if(s.size() == hi) lo++;
        else hi++;
    }
    return answer;
}
int main(){
    int N, k;
    cin >> N >> k;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cout << solution(v, k) << "\n";
}