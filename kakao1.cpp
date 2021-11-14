#include<bits/stdc++.h>
using namespace std;
vector<set<int>> info;
vector<string> id_list, report;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    info = vector<set<int>>(id_list.size(), set<int>());
    for(int i = 0; i < report.size(); i++){
        stringstream ss(report[i]);
        string tmp;
        vector<string> v;
        while(ss >> tmp){
            v.push_back(tmp);
        }
        int from = find(id_list.begin(), id_list.end(), v[0]) - id_list.begin();
        int to = find(id_list.begin(), id_list.end(), v[1]) - id_list.begin();
        info[from].insert(to);
    }

    map<int, int> mp;
    for(int i = 0; i < id_list.size(); i++){
        for(int badUser : info[i]) mp[badUser]++;
    }

    vector<int> answer;
    for(int i = 0; i < id_list.size(); i++){
        int cnt = 0;
        for(int badUser : info[i]) {
            if(mp[badUser] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
int main(){
    vector<string> v1 = {"muzi", "frodo", "apeach", "neo"};
    vector<string> v2 = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k;
    cin >> k;
    vector<int> res = solution(v1, v2, k);
    for(int i : res) cout << i << "\n";
}
