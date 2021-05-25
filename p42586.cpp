#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i = 0;
    int day = 0;
    while(i < progresses.size()){
        int cnt = 0;
        while (day * speeds[i] + progresses[i] < 100)
            day++;
        while (day * speeds[i] + progresses[i] >= 100){
            cnt++;
            i++;
        }
        answer.push_back(cnt);
    }

    return answer;
}