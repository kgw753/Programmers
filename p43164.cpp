#include<bits/stdc++.h>
using namespace std;
bool found = false;
void dfs(string here, vector<bool> visited, vector<string> &answer, vector<vector<string>> tickets, int rem){
    answer.push_back(here);
    if(rem == 0){
        found = true;
        return;
    }
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == here && visited[i] == false){
            visited[i] = true;
            dfs(tickets[i][1], visited, answer, tickets, rem - 1);
            if(found) return;
            visited[i] = false;
        }
    }
    answer.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", visited, answer, tickets, tickets.size());
    return answer;
}
int main(){
    int N;
    cin >> N;
    vector<vector<string>> MAP(N, vector<string>(2));
    string a, b;
    for(int i = 0; i < N; i++){
        cin >> MAP[i][0] >> MAP[i][1];
    }
    vector<string> ans = solution(MAP);
    for(string s : ans) cout << s << "\n";
}