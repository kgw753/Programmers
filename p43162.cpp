#include<bits/stdc++.h>
using namespace std;
#define MAX 204
vector<vector<int>> MAP;
int N;
int visited[MAX];
void dfs(int here){
    for(int there = 0; there < N; there++){
        if(visited[there] || MAP[here][there] == 0) continue;
        visited[there] = 1;
        dfs(there);
    }
}
int solution(int n, vector<vector<int>> computers) {
    MAP = computers;
    N = n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        answer++;
        dfs(i);
    }
    return answer;
}