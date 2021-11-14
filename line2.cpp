#include<bits/stdc++.h>
using namespace std;
#define MAX 34
const int totChar = 'z' - 'a' + 1;
vector<int> info[MAX], sum[MAX];
struct cmp{
    bool operator()(pair<int, string> p1, pair<int, string> p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};
priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> ret;
void check(int day, int n, int k){
    for(int i = 0; i < totChar; i++){
        char c = (char)(i + 'a');
        for(int j = 0; j + n <= day; j++){
            bool flag = true;
            if(sum[j + n][i] - sum[j][i] >= 2 * n * k){
                for(int d = j + 1; d < j + 1 + n; d++){
                    if(info[d][i] < k) flag = false;
                }
                if(flag) ret.push({sum[j + k][i] - sum[j][i], string(1, c)});
            }
        }
    }
}
void parsing(vector<string> research){
    for(int i = 1; i <= research.size(); i++){
        string str = research[i - 1];
        for(int j = 0; j < research[i - 1].size(); j++){
            info[i][str[j] - 'a']++;
        }
        for(int j = 0; j < research[i - 1].size(); j++){
            sum[i][str[j] - 'a'] = sum[i - 1][str[j] - 'a'] + info[i][str[j] - 'a'];
        }
    }
}
string solution(vector<string> research, int n, int k) {
    for(int i = 0; i < MAX; i++) {
        info[i] = vector<int>(totChar, 0);
        sum[i] = vector<int>(totChar, 0);
    }
    parsing(research);
    check(research.size(), n, k);
    string answer = (ret.empty()) ? "None" : ret.top().second;
    return answer;
}
int main(){
    int N, n, k;
    cin >> N >> n >> k;
    vector<string> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cout << solution(v, n, k) << "\n";
}