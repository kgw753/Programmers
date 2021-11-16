#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> people, int limit) {
    int ret = 0;
    int lo = 0;
    int hi = people.size() - 1;
    sort(people.begin(), people.end());
    while(lo <= hi){
        if(people[lo] + people[hi] <= limit){
            lo++, hi--;
        }
        else{
            hi--;
        }
        ret++;
    }
    return ret;
}
int main(){
    int N, l;
    cin >> N >> l;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cout << solution(v, l) << "\n";
}