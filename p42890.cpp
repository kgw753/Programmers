#include<bits/stdc++.h>
using namespace std;
int row, col;
vector<vector<string>> r;
vector<vector<int>> key;
bool onlyCheck(vector<int> v){
    map<string, int> mp;
    for(int i = 0; i < row; i++){
        string info = "";
        for(int j = 0; j < v.size(); j++){
            info += r[i][v[j]];
        }
        mp[info]++;
        if(mp[info] > 1) return false;
    }
    return true;
}
bool minCheck(vector<int> v){
    for(vector<int> k : key){
        bool isMin = false;
        for(int i = 0; i < k.size(); i++){
            bool alreadyIn = false;
            for(int j = 0; j < v.size(); j++){
                if(v[j] == k[i]) alreadyIn = true;
            }
            if(!alreadyIn) isMin = true;
        }
        if(!isMin) return false;
    }
    return true;
}
void combi(int idx, vector<int> v, int size){
    if(v.size() == size){
        if(minCheck(v) && onlyCheck(v)) key.push_back(v);
        return;
    }
    for(int i = idx + 1; i < col; i++){
        v.push_back(i);
        combi(i, v, size);
        v.pop_back();
    }
}
int solution(vector<vector<string>> relation) {
    r = relation;
    row = relation.size();
    col = relation[0].size();
    for(int i = 1; i <= col; i++){
        combi(-1, vector<int>(), i);
    }
    return key.size();
}