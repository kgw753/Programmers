#include<bits/stdc++.h>
using namespace std;
map<string, string> parent;
map<string, int> profit;
void update(string name, int money){
    if(name == "-") return;
    int nMoney = money * 0.1;
    if(money < 1) return;
    profit[name] += (money - nMoney);
    update(parent[name], nMoney);
    return;
}
vector<int> solution(vector<string> enroll, vector<string> referral, 
                        vector<string> seller, vector<int> amount) {
    vector<int> ret;
    for(int i = 0; i < enroll.size(); i++){
        parent[enroll[i]] = referral[i];
    }
    for(int i = 0; i < seller.size(); i++){
        update(seller[i], amount[i] * 100);
    }
    for(string name : enroll){
        ret.push_back(profit[name]);
    }
    return ret;
}