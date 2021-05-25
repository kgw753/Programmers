#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    stack<char> st;
    st.push(s[0]);
    int i = 1;
    while(i < s.size()){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
        i++;
    }
    return st.size() == 0 ? 1 : 0;
}

int main(){
    cout << solution("baabaa") << "\n";
    cout << solution("baba") << "\n";
}