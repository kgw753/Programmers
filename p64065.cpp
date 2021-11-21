#include<bits/stdc++.h>
using namespace std;
vector<int> solution(string s) {
    vector<int> ret;
    map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    int num = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '}' || s[i] == ','){
            if(num != 0){
                mp[num]++;
                num = 0;
            }
        }
        else{
            num *= 10;
            num += (s[i] - '0');
        }
    }

    for(pair<int, int> p : mp) pq.push({p.second, p.first});
    while(pq.size()){
        ret.push_back(pq.top().second);
        pq.pop();
    }
    return ret;
}
int main(){
    string s;
    cin >> s;
    vector<int> res = solution(s);
    for(int r : res) cout << r << " ";
    cout << "\n";
}