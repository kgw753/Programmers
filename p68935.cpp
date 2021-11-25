#include<bits/stdc++.h>
using namespace std;
int N;
int solution(int n) {
    int answer = 0;
    string tmp = "";
    while(n > 0){
        tmp.push_back((n % 3) + '0');
        n /= 3;
    }
    for(int i = 0; i < tmp.length(); i++){
        int idx = tmp.length() - i - 1;
        answer += pow(3, idx) * (tmp[i] - '0');
    }
    return answer;
}
int main(){
    cin >> N;
    cout << solution(N) << "\n";
}