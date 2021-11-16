#include<bits/stdc++.h>
using namespace std;
bool solution(string s){
    stack<int> st;
    for(char c : s){
        if(c == '(') st.push(1);
        else{
            if(st.empty()) return false;
            else st.pop();
        }
    }
    return st.empty();
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}