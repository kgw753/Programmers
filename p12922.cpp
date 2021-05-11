#include<bits/stdc++.h>
using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0; i < n; i++){
        answer.append((i % 2 == 0) ? "¼ö" : "¹Ú");
    }
    return answer;
}

int main(){
    cout << solution(2) << "\n";
    cout << solution(3) << "\n";
}