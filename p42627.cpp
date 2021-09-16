#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int answer = 0;
    int now = 0, idx = 0;
    while(pq.size() || idx < jobs.size()){
        if(idx < (int)jobs.size() && now >= jobs[idx][0]){
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        if(pq.size()){
            now += pq.top().first;
            answer += now - pq.top().second;
            pq.pop();
        }
        else{
            now = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(2));
    for(int i = 0; i < N; i++){
        cin >> v[i][0] >> v[i][1];
    }
    cout << solution(v) << "\n";
}