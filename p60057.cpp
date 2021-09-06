#include<bits/stdc++.h>
using namespace std;
string input;
string go(string s, int len){
    string ret = "", prev;
    for(int i = 0; i < s.length(); i += len){
        if(i + len >= s.length()) {
            ret += s.substr(i);
            break;
        }
        else prev = s.substr(i, len);
        int cnt = 1, j = i + len;
        string now = s.substr(j, len);
        while(prev == now && j + len <= s.length()){
            cnt++;
            j += len;
            now = s.substr(j, len);
        }
        if(cnt > 1) ret += (to_string(cnt) + prev);
        else ret += prev;
        i = j - len;
    }
    return ret;
}
int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length() / 2; i++){
        answer = min(answer, (int)go(s, i).length());
    }
    return answer;
}
int main(){
    cin >> input;
    cout << solution(input) << "\n";
}