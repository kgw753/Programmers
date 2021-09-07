#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> Info;
map<string, string> idMp;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(string r : record){
        vector<string> info;
        stringstream ss(r);
        string tmp;
        while(ss >> tmp){
            info.push_back(tmp);
        }
        if(info[0] == "Enter" || info[0] == "Change") idMp[info[1]] = info[2];
        Info.push_back(info);
    }
    for(vector<string> i : Info){
        string ans = idMp[i[1]];
        if(i[0] == "Change") continue;
        if(i[0] == "Enter") ans += "님이 들어왔습니다.";
        else if(i[0] == "Leave") ans += "님이 나갔습니다.";
        answer.push_back(ans);
    }
    return answer;
}