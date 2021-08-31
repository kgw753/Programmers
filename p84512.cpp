#include<bits/stdc++.h>
using namespace std;
string input;
const int k = 781;
int solution(string word) {
    int answer = word.length();
    map<char, int> mp;
    mp['A'] = 0, mp['E'] = 1, mp['I'] = 2, mp['O'] = 3, mp['U'] = 4;
    for(int i = 0; i < word.length(); i++){
        answer += mp[word[i]] * k / pow(5, i);
    }
    return answer;
}
int main(){
    cin >> input;
    cout << solution(input) << "\n";
}