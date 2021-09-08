#include<bits/stdc++.h>
using namespace std;
int N, M;
int mx[] = {3, 2, 2, 2};
vector<string> info, query;
string input;
vector<int> cnt[3][2][2][2];
int bfs(vector<int> info){
    int ret = 0;
    queue<vector<int>> q;
    q.push({0});
    while(q.size()){
        vector<int> now = q.front();
        q.pop();
        if(now.size() == 5){
            for(int c : cnt[now[1]][now[2]][now[3]][now[4]]) if(info[4] <= c) ret++;
            continue;
        }
        if(info[now.size() - 1] == -1){
            for(int i = 0; i < mx[now.size() - 1]; i++){
                now.push_back(i);
                q.push(now);
                now.pop_back();
            }
        }
        else{
            now.push_back(info[now.size() - 1]);
            q.push(now);
        }
    }
    return ret;
}
vector<int> parse(string q){
    vector<int> ret(5, -1);
    stringstream ss(q);
    vector<string> v;
    string tmp;
    while(ss >> tmp) {
        if(tmp == "and") continue;
        v.push_back(tmp);
    }
    if(v[0] == "cpp") ret[0] = 0;
    else if(v[0] == "java") ret[0] = 1;
    else if(v[0] == "python") ret[0] = 2;
    
    if(v[1] == "backend") ret[1] = 0;
    else if(v[1] == "frontend") ret[1] = 1;

    if(v[2] == "junior") ret[2] = 0;
    else if(v[2] == "senior") ret[2] = 1;

    if(v[3] == "chicken") ret[3] = 0;
    else if(v[3] == "pizza") ret[3] = 1;

    ret[4] = stoi(v[4]);
    return ret;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(string s : info){
        vector<int> p = parse(s);
        cnt[p[0]][p[1]][p[2]][p[3]].push_back(p[4]);
    }
    for(string q : query){
        vector<int> p = parse(q);
        answer.push_back(bfs(p));
    }
    return answer;
}
int main(){
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; i++){
        getline(cin, input);
        info.push_back(input);
    }
    for(int i = 0; i < M; i++){
        getline(cin, input);
        query.push_back(input);
    }
    cout << "\n";
    vector<int> answer = solution(info, query);
    for(int a : answer) cout << a << "\n";
}