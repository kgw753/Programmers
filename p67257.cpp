#include<bits/stdc++.h>
using namespace std;
vector<char> op;
long long val;
string input;
long long result(long long  a, long long  b, char o){
    if(o == '+') return a + b;
    if(o == '-') return a - b;
    if(o == '*') return a * b;
    return -1;
}
long long calc(vector<pair<long long, char>> v){
    for(int i = 0; i < op.size(); i++){
        for(int j = 0; j < v.size() - 1; j++){
            if(v[j].second == op[i]){
                v[j + 1].first = result(v[j].first, v[j + 1].first, v[j].second);
                v.erase(v.begin() + j);
                j--;
            }
        }
    }
    return abs(v[0].first);
}
vector<pair<long long, char>> parse(string exp){
    vector<pair<long long, char>> ret;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
            if(find(op.begin(), op.end(), exp[i]) == op.end()) op.push_back(exp[i]);
            ret.push_back({val, exp[i]});
            val = 0;
        }
        else val = (val * 10) + (exp[i] - '0');
    }
    ret.push_back({val, '.'});
    sort(op.begin(), op.end());
    return ret;
}
long long solution(string expression) {
    long long answer = 0;
    vector<pair<long long, char>> v = parse(expression);
    do{
        answer = max(answer, calc(v));
    }while(next_permutation(op.begin(), op.end()));
    return answer;
}
int main(){
    cin >> input;
    cout << solution(input) << "\n";
}