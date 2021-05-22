#include<bits/stdc++.h>
using namespace std;
string solution(string s) {
    string answer = "";
    if(!(s.length() % 2)) answer += s[s.length() / 2 - 1];
    answer += s[s.length() / 2];
    return answer;
}