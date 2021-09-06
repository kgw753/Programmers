#include<bits/stdc++.h>
using namespace std;
string input;
string solution(string p) {
    if(p.empty()) return "";
    int l = 0, r = 0, i = 0;
    bool isCorrect = true;
    do{
        (p[i++] == '(') ? l++ : r++;
        if(l < r) isCorrect = false;
    }while(l != r);
    string u, v;
    u = p.substr(0, i);
    v = p.substr(i);
    if(isCorrect) return u + solution(v);
    string tmp = "";
    for(int i = 1; i < u.length() - 1; i++){
        tmp += (u[i] == '(' ? ")" : "(");
    }
    string ret = "(" + solution(v) + ")" + tmp;
    return ret;
}