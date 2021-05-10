#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n, 1);
    for(int l : lost) students[l - 1]--;
    for(int r : reserve) students[r - 1]++;
    for(int i = 0; i < n; i++){
        if(students[i] == 0){
            if(i - 1 >= 0 && students[i - 1] == 2){
                students[i]++;
                students[i - 1]--;
            }
            else if(i + 1 < n && students[i + 1] == 2){
                students[i]++;
                students[i + 1]--;
            }
        }
    }
    int answer = 0;
    for(int s : students){
        answer += (s > 0 ? 1 : 0);
    }
    return answer;
}

int main(){
    cout << solution(5, vector<int>{2, 4}, vector<int>{1, 3, 5}) << "\n";
    cout << solution(5, vector<int>{2, 4}, vector<int>{3}) << "\n";
    cout << solution(3, vector<int>{3}, vector<int>{1}) << "\n";
}