#include<bits/stdc++.h>
using namespace std;
int getIdx(int n, int len){
    if(n >= len){
        return n - len;
    }
    else if(n < 0){
        return n + len;
    }
    return n;
}
int solution(string name) {
    int answer = 0, here = 0;
    string tmp(name.length(), 'A');
    while(true){
        if(name[here] - 'A' < ('Z' + 1) - name[here]){
            answer += name[here] - 'A';
        }
        else{
            answer += ('Z' + 1) - name[here];
        }
        tmp[here] = name[here];
        if(tmp == name) break;

        for(int move = 1; move < name.length(); move++){
            int idx1 = getIdx(here + move, name.length());
            int idx2 = getIdx(here - move, name.length());
            if(name[idx1] != tmp[idx1]){
                here = idx1;
                answer += move;
                break;
            }
            else if(name[idx2] != tmp[idx2]){
                here = idx2;
                answer += move;
                break;
            }
        }
    }
    return answer;
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}