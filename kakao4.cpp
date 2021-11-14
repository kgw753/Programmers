#include<bits/stdc++.h>
using namespace std;
#define MAX 11
vector<int> apch(MAX, 0), ryan(MAX, 0);
vector<int> answer(MAX, 0);
int mn;
int gapCalc(){
    int scr1 = 0, scr2 = 0;
    for(int i = 0; i < MAX; i++){
        if(apch[i] == 0 && ryan[i] == 0) continue;
        else if(apch[i] >= ryan[i]) scr1 += (10 - i);
        else scr2 += (10 - i);
    }
    return scr1 - scr2;
}
void dfs(int idx, int rem){
    if(rem == 0){
        int gap = gapCalc();
        if(gap <= mn){
            mn = min(mn, gap);
            answer = ryan;
        }
        return;
    }
    for(int i = idx; i < MAX; i++){
        ryan[i] = min(rem, apch[i] + 1);
        dfs(i + 1, rem - ryan[i]);
        ryan[i] = 0;
    }
}
vector<int> solution(int n, vector<int> info) {
    apch = info;
    dfs(0, n);
    if(mn == 0) return {-1};
    else return answer;
}

int main(){
    int N;
    cin >> N;
    vector<int> v(MAX);
    for(int i = 0; i < MAX; i++) cin >> v[i];
    vector<int> v1 = solution(N, v);
    for(int i : v1) cout << i << " ";
}
