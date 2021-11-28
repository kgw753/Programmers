#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
int N;
vector<int> v;
vector<bool> che(MAX, false);
int combi(int idx, int tot, int sz){
    if(sz == 3){
        if(!che[tot]) return 1;
        else return 0;
    }
    int ret = 0;
    for(int i = idx + 1; i < N; i++){
        ret += combi(i, tot + v[i], sz + 1);
    }
    return ret;
}
int solution(vector<int> nums) {
    v = nums;
    N = nums.size();
    che[0] = che[1] = true;
    sort(v.begin(), v.end());
    for(int i = 2; i < sqrt(MAX); i++){
        if(che[i]) continue;
        for(int j = i * i; j < MAX; j += i){
            che[j] = true;
        }
    }
    return combi(-1, 0, 0);
}