#include<bits/stdc++.h>
using namespace std;
string s1, s2;
map<string, int> uni, inter;
map<string, int> mp1, mp2;
pair<double, double> calc(){
    for(pair<string, int> p : mp1){
        uni[p.first] = max(mp2[p.first], p.second);
        inter[p.first] = min(mp2[p.first], p.second);
    }
    for(pair<string, int> p : mp2){
        uni[p.first] = max(mp1[p.first], p.second);
        inter[p.first] = min(mp1[p.first], p.second);
    }
    double usize = 0, isize = 0;
    for(pair<string, int> p : uni) usize += p.second;
    for(pair<string, int> p : inter) isize += p.second;
    return {isize, usize};
}
bool wrongChar(char c){
    if(c >= 'a' && c <= 'z') return false;
    if(c >= 'A' && c <= 'Z') return false;
    return true;
}
void go(string str, map<string, int> &mp){
    for(int i = 0; i < str.length() - 1; i++){
        if(wrongChar(str[i]) || wrongChar(str[i + 1])) continue;
        string s = str.substr(i, 2);
        mp[s]++;
    }
}
void parsing(string &s){
    int offset = 'A' - 'a';
    for(int i = 0; i < s.length(); i++){
        if(wrongChar(s[i])) continue;
        if(s[i] >= 'a' && s[i] <= 'z') s[i] += offset;
    }
}
int solution(string str1, string str2) {
    parsing(str1), parsing(str2);
    go(str1, mp1), go(str2, mp2);
    pair<double, double> size = calc();
    if(size.second == 0) return 65536;
    double answer = (size.first / size.second) * 65536;
    return (int)answer;
}
int main(){
    cin >> s1 >> s2;
    cout << solution(s1, s2) << "\n";
}