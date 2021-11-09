#include<bits/stdc++.h>
using namespace std;
bool charCheck(char c){
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || c == '.' || c == '_' || c == '-') return true;
    return false;
}
void step1(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
void step2(string &str){
    string ret = "";
    for(int i = 0; i < str.length(); i++){
        if(charCheck(str[i])) ret.push_back(str[i]);
    }
    str = ret;
}
void step3(string &str){
    string ret = "";
    bool prevDot = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            if(prevDot){
                
            }
            else{
                ret.push_back(str[i]);
                prevDot = true;
            }
        }
        else{
            prevDot = false;
            ret.push_back(str[i]);
        } 
    }
    str = ret;
}
void step4(string &str){
    if(str[str.length() - 1] == '.') str.erase(str.length() - 1);
    if(str[0] == '.') str.erase(0, 1);
}
void step5(string &str){
    if(str.empty()) str.push_back('a');
}
void step6(string &str){
    int MX = 15;
    if(str.length() > MX){
        str.erase(MX);
        if(str[14] == '.') str.pop_back();
    }
}
void step7(string &str){
    while(str.length() < 3){
        str.push_back(str[str.length() - 1]);
    }
}
string solution(string new_id) {
    string answer = new_id;
    step1(answer);
    step2(answer);
    step3(answer);
    step4(answer);
    step5(answer);
    step6(answer);
    step7(answer);
    return answer;
}
int main(){
    string name;
    cin >> name;
    cout << solution(name) << "\n";
}