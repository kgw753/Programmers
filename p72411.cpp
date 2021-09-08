#include<bits/stdc++.h>
using namespace std;
int N, M, num;
vector<string> dp[14][24];
map<string, int> mp;
vector<int> course, mx(12);
vector<string> orders;
string input;
void combi(int idx, string str, string res){
    if(res.length() > 1){
        mp[res]++;
        mx[res.length()] = max(mx[res.length()], mp[res]);
        dp[res.length()][mp[res]].push_back(res);
    }
    for(int i = idx + 1; i < str.length(); i++){
        res.push_back(str[i]);
        combi(i, str, res);
        res.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ret;
    for(string &str : orders){
        sort(str.begin(), str.end());
        combi(-1, str, "");
    }
    for(int c : course){
        for(string s : dp[c][mx[c]]){
            if(mx[c] > 1) ret.push_back(s);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        orders.push_back(input);
    }
    for(int i = 0; i < M; i++){
        cin >> num;
        course.push_back(num);
    }
    vector<string> res = solution(orders, course);
    for(string s : res) cout << s << "\n";
}