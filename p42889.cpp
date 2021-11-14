#include<bits/stdc++.h>
using namespace std;
#define MAX 504
bool cmp(pair<double, int> p1, pair<double, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(MAX);
    vector<pair<double, int>> v;
    int tot = stages.size();
    for(int i : stages) cnt[i - 1]++;
    for(int i = 0; i < N; i++){
        if(cnt[i] == 0) v.push_back({0, i + 1});
        else{
            v.push_back({(double)cnt[i] / tot, i + 1});
            tot -= cnt[i];
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(pair<double, int> p : v) answer.push_back(p.second);
    return answer;
}