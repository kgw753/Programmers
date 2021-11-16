#include<bits/stdc++.h>
using namespace std;
int getIdx(int nIdx, int len){
    if(nIdx < 0) return len + nIdx;
    else if(nIdx >= len) return nIdx - len;
    else return nIdx;
}
int solution(string name) {
    int ret = 0;
    for(char c : name){
        if(c - 'A' < ('Z' + 1) - c) ret += c - 'A';
        else ret += ('Z' + 1) - c;
    }
    string cmp = string(name.size(), 'A');
    int idx = 0, dist;
    while(cmp != name){
        cmp[idx] = name[idx];
        for(int mov = 1; mov <= name.length(); mov++){
            int idx1 = getIdx(idx + mov, name.length());
            int idx2 = getIdx(idx - mov, name.length());
            if(name[idx1] != cmp[idx1]){
                ret += mov;
                idx = idx1;
                break;
            }
            else if(name[idx2] != cmp[idx2]){
                ret += mov;
                idx = idx2;
                break;
            }
        }
    }
    return ret;
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}