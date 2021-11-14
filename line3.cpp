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
priority_queue<Info, vector<Info>, cmp> working;
bool allDone(int k){
    for(int i = 0; i < k; i++) {
        if(!visited[i]) return false;
    }
    return true;
}
vector<int> solution(vector<vector<int>> jobs) {
    vector<int> answer;
    while(!allDone(jobs.size())){
        for(int i = 0; i < jobs.size(); i++){
            if(visited[i]) continue;
            
            int a = jobs[i][0], b = jobs[i][1];
            int c = jobs[i][2], d = jobs[i][3];

            if(a > t) break;
            if(!working.empty() && working.top().type != c) continue;
            
            working.push({b, c, d});
            scoreSum[c] += d;
            visited[i] = true;
        }
        answer.push_back(working.top().type);
        while(working.size()){
            Info now = working.top();

        }
    }
    return answer;
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(4, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            cin >> v[i][j];
        }
    }
    vector<int> res = solution(v);
    for(int r : res) cout << r << "\n";
}