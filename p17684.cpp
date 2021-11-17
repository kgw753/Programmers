#include<bits/stdc++.h>
using namespace std;
vector<int> solution(string msg) {
    if(msg.length() == 1) return vector<int>({msg[0] - 'A' + 1});
    vector<int> ret;
    map<string, int> mp;
    int idx = 1;
    for(char c = 'A'; c <= 'Z'; c++, idx++){
        mp[string(1, c)] = idx;
    }

    int len;
    for(int i = 0; i < msg.length(); i += (len - 1)){
        len = 1;
        while(len < msg.length() && mp[msg.substr(i, len)]){
            len++;
        }
        ret.push_back(mp[msg.substr(i, len - 1)]);
        mp[msg.substr(i, len)] = idx++;
    }
    return ret;
}
int main(){
    string input;
    cin >> input;
    vector<int> res = solution(input);
    for(int i : res) cout << i << "\n";
}