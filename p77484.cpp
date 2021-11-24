#include<bits/stdc++.h>
using namespace std;
pair<int, int> check(vector<int> A, vector<int> B){
    int equalCnt = 0;
    int zeroCnt = 0;
    for(int a : A){
        if(a == 0){
            zeroCnt++;
            continue;
        }
        for(int b : B){
            if(a == b){
                equalCnt++;
                break;
            }
        }
    }
    return {equalCnt, zeroCnt};
}
int getScore(int equalCnt){
    if(equalCnt == 6) return 1;
    else if(equalCnt == 5) return 2;
    else if(equalCnt == 4) return 3;
    else if(equalCnt == 3) return 4;
    else if(equalCnt == 2) return 5;
    else return 6;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    pair<int, int> p = check(lottos, win_nums);
    int equalCnt = p.first;
    int zeroCnt = p.second;
    int mx = getScore(equalCnt + zeroCnt);
    int mn = getScore(equalCnt);
    return {mx, mn};
}