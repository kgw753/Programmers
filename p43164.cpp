#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
vector<vector<string>> info;
bool found = false;
void dfs(string here, vector<string> &answer, vector<bool> usedTicket, int rem){
    answer.push_back(here);
    if(rem == 0) {
        found = true;
        return;
    }
    for(int i = 0; i < info.size(); i++){
        if(info[i][0] == here && usedTicket[i] == false){
            usedTicket[i] = true;
            dfs(info[i][1], answer, usedTicket, rem - 1);
            usedTicket[i] = false;
            if(found) return;
        }
    }
    answer.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> usedTicket(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    info = tickets;
    dfs("ICN", answer, usedTicket, tickets.size());
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