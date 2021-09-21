#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int parent[MAX];
bool cmp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}
int getParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}
bool findParent(int a, int b){
    int x = getParent(a);
    int y = getParent(b);
    return x != y;
}
void unionParent(int a, int b){
    int x = getParent(a);
    int y = getParent(b);
    if(x < y) parent[b] = a;
    else parent[a] = b;
}
int solution(int n, vector<vector<int>> costs) {
    int ret = 0;
    for(int i = 0; i < MAX; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < costs.size(); i++){
        int from = getParent(costs[i][0]);
        int to = getParent(costs[i][1]);
        int cost = costs[i][2];
        if(from != to){
            parent[to] = from;
            ret += cost;
        }
    }
    return ret;
}
int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(3, 0));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    cout << solution(n, v) << "\n";
}