#include<bits/stdc++.h>
using namespace std;
#define MAX 504
int Depth;
int dp[MAX][MAX];
vector<vector<int>> triangle;
int go(int idx, int depth){
    int &ret = dp[depth][idx];
    if(depth == 0) return ret = triangle[0][0];
    if(~ret) return ret;
    int r1, r2;
    r1 = r2 = -1;
    if(idx != 0) r1 = go(idx - 1, depth - 1);
    if(idx != depth) r2 = go(idx, depth - 1) ;
    ret = max(r1, r2) + triangle[depth][idx];
    return ret;
}
int solution(vector<vector<int>> _triangle) {
    memset(dp, -1, sizeof(dp));
    triangle = _triangle;
    Depth = triangle.size();
    int answer = 0;
    for(int i = 0; i < Depth; i++){
        answer = max(answer, go(i, Depth - 1));
    }
    return answer;
}
int main(){
    int d;
    cin >> d;
    vector<vector<int>> t(d, vector<int>());
    int input;
    for(int i = 1; i <= d; i++){
        for(int j = 0; j < i; j++){
            cin >> input;
            t[i - 1].push_back(input);
        }
    }
    cout << solution(t) << "\n";
}