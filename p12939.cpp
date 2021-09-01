#include<bits/stdc++.h>
using namespace std;
string solution(string s) {
    string tmp = "";
    vector<int> v;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            v.push_back(stoi(tmp));
            tmp.clear();
        }
        else{
            tmp += s[i];
        }
    }
    v.push_back(stoi(tmp));
    sort(v.begin(), v.end());
    return to_string(v[0]) + " " + to_string(v[v.size() - 1]);
}