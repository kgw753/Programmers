#include<bits/stdc++.h>
using namespace std;

string solution(string number, int k){
    string answer = number.substr(k);

    for(int i = k - 1; i > -1; i--){
        for(int j = 0; j < answer.length(); j++){
            if(number[i] < answer[j]){
                break;
            }
            else{
                char tmp = number[i];
                number[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }

    return answer;
}