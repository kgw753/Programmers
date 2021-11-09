#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 12
#define MAX_CNT 22
int N, M;
string input;
int num;
vector<string> orders;
vector<int> course, mx(MAX_LEN);
map<string, int> mp;
vector<string> dp[MAX_LEN][MAX_CNT];
void combi(int now, string o, string str){
    if(str.length() > 1){
        mp[str]++;
        mx[str.length()] = max(mx[str.length()], mp[str]);
        dp[str.length()][mp[str]].push_back(str);
    }
    for(int i = now + 1; i < o.length(); i++){
        str.push_back(o[i]);
        combi(i, o, str);
        str.pop_back();
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
            if(mx[c] > 1){
                ret.push_back(s);
            }
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