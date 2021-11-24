#include<bits/stdc++.h>
using namespace std;
map<string, int> profit;
map<string, string> parent;
void update(string name, int money){
    if(name == "-") return;
    int nMoney = money * 0.1;
    profit[name] += (money - nMoney);
    if(money < 1) return;
    update(parent[name], nMoney);
}
vector<int> solution(vector<string> enroll, vector<string> referral, 
                        vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i = 0; i < enroll.size(); i++){
        parent[enroll[i]] = referral[i];
    }
    for(int i = 0; i < seller.size(); i++){
        update(seller[i], amount[i] * 100);
    }
    for(string name : enroll){
        answer.push_back(profit[name]);
    }
    return answer;
}