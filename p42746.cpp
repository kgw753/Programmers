#include<bits/stdc++.h>
using namespace std;

bool cmp(int n1, int n2){
    int t1 = stoi(to_string(n1) + to_string(n2));
    int t2 = stoi(to_string(n2) + to_string(n1));
    return t1 > t2 ? true : false;
}

string solution(vector<int> numbers){
    sort(numbers.begin(), numbers.end(), cmp);
    string answer = "";
    for(int n : numbers) answer += to_string(n);
    return answer[0] == '0' ? "0" : answer;
}