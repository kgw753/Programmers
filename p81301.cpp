#include<bits/stdc++.h>
using namespace std;
string numbers[] = {
    "zero", "one", "two", "three", "four", "five", 
    "six", "seven", "eight", "nine", "ten"
};
bool isNum(char c){
    return (c >= '0' && c <= '9');
}
int solution(string s) {
    string answer = "";
    int idx = 0;
    while(idx < s.length()){
        if(isNum(s[idx])){
            answer.push_back(s[idx]);
            idx++;
            continue;
        }
        for(int i = 0; i < 10; i++){
            if(s.substr(idx, numbers[i].length()) == numbers[i]){
                idx += numbers[i].length();
                answer.push_back(i + '0');
                break;
            }
        }
    }
    return stoi(answer);
}
int main(){
    string str;
    cin >> str;
    cout << solution(str) << "\n";
}