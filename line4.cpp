#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int t, scoreSum[MAX];
bool visited[10004];
struct Info{
    int sec, type, score;
};
struct cmp{
    bool operator()(Info i1, Info i2){
        return i1.type < i2.type;
    }
};
priority_queue<Info, vector<Info>, cmp> pq;
bool allDone(int k){
    for(int i = 0; i < k; i++) {
        if(!visited[i]) return false;
    }
    return true;
}
void work(vector<int> &answer){
    Info now = pq.top();
    pq.pop();
    t += now.sec;
    scoreSum[now.type] -= now.score;
    if(answer.empty() || answer[answer.size() - 1] != now.type){
        answer.push_back(now.type);
    }
}
void addWork(vector<vector<int>> jobs){
    for(int i = 0; i < jobs.size(); i++){
        if(visited[i]) continue;
        
        int a = jobs[i][0], b = jobs[i][1];
        int c = jobs[i][2], d = jobs[i][3];

        if(a > t) return;
        if(!pq.empty() && pq.top().type != c) continue;
        pq.push({b, c, d});
        visited[i] = true;
    }
}
vector<int> solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    vector<int> answer;
    while(!allDone(jobs.size())){
        work(answer);
        addWork(jobs);
    }
    return answer;
}