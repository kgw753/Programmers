#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> p;
    
    for(string s : completion) p[s]++;
    
    for(string s : participant){
        p[s]--;
        if(p[s] < 0){
            answer = s;
            break;
        }
            
    }

    return answer; 
}