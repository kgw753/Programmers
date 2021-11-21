#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<string>> clothes) {
    int ret = 1;
    map<string, int> mp;
    for(vector<string> cloth : clothes){
        mp[cloth[1]]++;
    }
    for(pair<string, int> p : mp){
        ret *= (p.second + 1);
    }
    ret -= 1;
    return ret;
}