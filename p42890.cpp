#include<bits/stdc++.h>
using namespace std;
int N, M, visited[10];
vector<vector<string>> r;
vector<vector<int>> key;
bool minCheck(vector<int> candi){
    if(key.empty()) return true;
    for(vector<int> v : key){
        bool isMin = false;
        for(int i = 0; i < v.size(); i++){
            bool alreadyIn = false;
            for(int j = 0; j < candi.size(); j++){
                if(v[i] == candi[j]) alreadyIn = true;
            }
            if(!alreadyIn) isMin = true;
        }
        if(!isMin) return false;
    }
    return true;
}
void combi(int idx, vector<int> candi, int size){
    if(candi.size() == size){
        if(!minCheck(candi)) return;
        map<string, int> mp;
        for(int i = 0; i < N; i++){
            string str = "";
            for(int idx : candi){
                str += r[i][idx];
            }
            mp[str]++;
            if(mp[str] > 1) return;
        }
        key.push_back(candi);
    }
    for(int i = idx + 1; i < M; i++){
        candi.push_back(i);
        combi(i, candi, size);
        candi.pop_back();
    }
}
int solution(vector<vector<string>> relation) {
    r = relation;
    N = relation.size();
    M = relation[0].size();
    for(int i = 0; i < M; i++){
        combi(-1, vector<int>(), i + 1);
    }
    return key.size();
}