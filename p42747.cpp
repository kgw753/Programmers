#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations.size(); i++){
        int cnt = citations.size() - i;
        if(citations[i] >= cnt) answer = max(answer, cnt);
    }
    return answer;
}
