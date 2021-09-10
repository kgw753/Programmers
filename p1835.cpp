#include<bits/stdc++.h>
using namespace std;
int Size;
vector<char> v;
vector<char> parsing(string str){
    vector<char> ret(4);
    ret[0] = str[0], ret[1] = str[2];
    ret[2] = str[3], ret[3] = str[4];
    return ret;
}
bool check(vector<char> v, vector<char> info[]){
    for(int i = 0; i < Size; i++){
        char from = info[i][0];
        char to = info[i][1];
        char cond = info[i][2];
        char k = info[i][3];
        int dist = abs(find(v.begin(), v.end(), from) - find(v.begin(), v.end(), to)) - 1;
        if(info[i][2] == '<') if(dist >= (k - '0')) return false;
        if(info[i][2] == '>') if(dist <= (k - '0')) return false;
        if(info[i][2] == '=') if(dist != (k - '0')) return false;
    }
    return true;
}
int solution(int n, vector<string> data) {
    v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    Size = n;
    int answer = 0;
    vector<char> info[n];
    for(int i = 0; i < n; i++) info[i] = parsing(data[i]);
    do{
        if(check(v, info)) answer++;
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}
int main(){
    int n;
    cin >> n;
    vector<string> data(n);
    for(int i = 0; i < n; i++) cin >> data[i];
    cout << solution(n, data) << "\n";
}