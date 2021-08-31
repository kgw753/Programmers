#include<bits/stdc++.h>
using namespace std;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> mp;
    mp[words[0]] = 1;
    int len = words[0].length();
    int head = words[0][0];
    int tail = words[0][len - 1];
    int i = 0, mod = 0;
    for(i = 1; i < words.size(); i++){
        if(mp[words[i]] || words[i].length() == 1) break;
        mp[words[i]] = 1;
        len = words[i].length();
        head = words[i][0];
        if(tail != head) break;
        tail = words[i][len - 1];
    }
    if(i == words.size()) i = mod = 0;
    else {
        mod = i % n + 1;
        i = i / n + 1;
    }
    return vector<int>({mod, i});
}
