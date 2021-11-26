#include<bits/stdc++.h>
using namespace std;
vector<int> scores;
bool isPrize(char c){
    return (c == '*' || c == '#');
}
bool isNum(char c){
    return (c >= '0' && c <= '9');
}
int getScore(int scr, char c){
    int n;
    if(c == 'S') n = 1;
    else if(c == 'D') n = 2;
    else n = 3;
    return (int)pow(scr, n);
}
void goPrize(char c, int idx){
    int mult = (c == '*') ? 2 : -1;
    scores[idx] *= mult;
    if(idx == 0 || mult == -1) return;
    scores[idx - 1] *= mult;
    return;
}
int solution(string dartResult) {
    int answer = 0;
    int now = 0, prev = 0;
    while(true){
        int scr = 0;
        int idx;
        for(idx = 0; isNum(dartResult[idx]); idx++){
            scr = scr * 10 + (dartResult[idx] - '0');
        }
        scores.push_back(getScore(scr, dartResult[idx++]));
        if(dartResult.size() > idx && !isNum(dartResult[idx])){
            goPrize(dartResult[idx], scores.size() - 1);
            idx++;
        }
        if(dartResult.size() == idx) break;
        dartResult = dartResult.substr(idx);
    }
    for(int scr : scores) answer += scr;
    return answer;
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}