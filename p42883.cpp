#include<bits/stdc++.h>
using namespace std;
string solution(string number, int k) {
    
    int len = number.length();
    
    int max_num = 0;
    int i;
    int cnt = 0;
    for(i = 0; i < len - k; i++){
        max_num = max(max_num, number[i] - '0');
    }

    for(i = 0; number[i] - '0' < max_num; i++){
        number.erase(i--, 1);
        cnt++;
    }

    while(cnt < k){
        if(number[i] - '0' < number[i + 1] - '0'){
            number.erase(i, 1);
            cnt++;
        }
        i++;
    }
    
    return number;
}

int main(){
    cout << solution("1924", 2) << "\n";
    cout << solution("1231234", 3) << "\n";
    cout << solution("4177252841", 4) << "\n";
}