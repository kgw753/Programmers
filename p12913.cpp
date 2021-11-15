#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> land){
    for(int i = 0; i < land.size() - 1; i++){
        land[i + 1][0] += max(max(land[i][1], land[i][2]), land[i][3]);
        land[i + 1][1] += max(max(land[i][0], land[i][2]), land[i][3]);
        land[i + 1][2] += max(max(land[i][0], land[i][1]), land[i][3]);
        land[i + 1][3] += max(max(land[i][0], land[i][1]), land[i][2]);
    }
    int size = land.size() - 1;
    int answer = max(max(land[size][0], land[size][1]), max(land[size][2], land[size][3]));
    return answer;
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(4, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            cin >> v[i][j];
        }
    }
    cout << solution(v) << "\n";
}