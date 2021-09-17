#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N;
vector<vector<int>> w(MAX, vector<int>()), l(MAX, vector<int>());
int bfs(int start, vector<vector<int>> MAP){
    queue<int> q;
    int visited[N + 1];
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    q.push(start);
    visited[start] = 1;
    while(q.size()){
        int here = q.front();
        q.pop();
        for(int there : MAP[here]){
            if(visited[there]) continue;
            visited[there] = 1;
            q.push(there);
            ret++;
        }
    }
    return ret;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    N = n;
    for(vector<int> r : results){
        int winner = r[0];
        int loser = r[1];
        w[winner].push_back(loser);
        l[loser].push_back(winner);
    }
    for(int i = 1; i <= n; i++){
        int winner = bfs(i, w);
        int loser = bfs(i, l);
        if(winner + loser == n - 1) answer++;
    }
    return answer;
}
int main(){
    cin >> N;
    vector<vector<int>> v(N + 1, vector<int>(2, 0));
    for(int i = 0; i < N; i++){
        cin >> v[i][0] >> v[i][1];
    }
    cout << solution(N, v) << "\n";
}