#include<bits/stdc++.h>
using namespace std;
char parse(char c, bool isFirst){
    if(isFirst && c >= 'a' && c <= 'z') return c + ('A' - 'a');
    else if(!isFirst && c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    else return c;
}
string solution(string s) {
    bool isFirst = true;
    for(char &c : s){
        if(c == ' '){
            isFirst = true;
        }
        else if(isFirst){
            c = parse(c, isFirst);
            isFirst = false;
        }
        else{
            c = parse(c, isFirst);
        }
    }
    return s;
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}