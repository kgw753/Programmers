#include<bits/stdc++.h>
using namespace std;
#define MAX 20004
vector<vector<int>> MAP(MAX, vector<int>());
vector<int> dist(MAX, 1e9);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(vector<int> e : edge){
        int a = e[0];
        int b = e[1];
        MAP[a].push_back(b);
        MAP[b].push_back(a);
    }
    pq.push({0, 1});
    dist[1] = 0;
    int mx = -1;
    while(pq.size()){
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;
        for(int i = 0; i < MAP[here].size(); i++){
            int there = MAP[here][i];
            int there_dist = dist[there];
            if(there_dist <= here_dist + 1) continue;
            dist[there] = here_dist + 1;
            pq.push({dist[there], there});
            mx = max(mx, dist[there]);
        }
    }
    for(int i = 1; i <= n; i++) if(mx == dist[i]) answer++;
    return answer;
}
int main(){
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<int>> v;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << solution(N, v) << "\n";
}