#include<bits/stdc++.h>
using namespace std;
const int exit_time = 23 * 60 + 59;
struct Info{
    string time, id, io;
};
vector<Info> info;
map<string, int> timeSum;
map<string, int> parkedTime;
int timeCalc(string t){
    int ret = 0;
    ret = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
    return ret;
}
void allCarOut(){
    for(auto car : parkedTime){
        if(car.second == -1) continue;
        timeSum[car.first] += (exit_time - car.second);
    }
}
void carInOut(Info car){
    int t = timeCalc(car.time);
    if(car.io == "IN") {
        parkedTime[car.id] = t;
    }
    else if(car.io == "OUT") {
        timeSum[car.id] += (t - parkedTime[car.id]);
        parkedTime[car.id] = -1;
    }
}
vector<Info> parsing(vector<string> records){
    vector<Info> ret;
    for(int i = 0; i < records.size(); i++){
        stringstream ss(records[i]);
        vector<string> v;
        string tmp;
        while(ss >> tmp){
            v.push_back(tmp);
        }
        ret.push_back({v[0], v[1], v[2]});
    }
    return ret;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    info = parsing(records);
    for(Info car : info) carInOut(car);
    allCarOut();
    for(auto car : timeSum){
        int totMin = max(0, car.second - fees[0]);
        while(totMin % fees[2]) totMin++;
        int fee = fees[1] + (totMin / fees[2]) * fees[3];
        answer.push_back(fee);
    }
    return answer;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v1(N);
    vector<string> v2(M);
    for(int i = 0; i < N; i++) cin >> v1[i];
    cin.ignore();
    for(int i = 0; i < M; i++) getline(cin, v2[i]);
    vector<int> v3 = solution(v1, v2);
    for(int i : v3) cout << i << " ";
    cout << "\n";
    
}