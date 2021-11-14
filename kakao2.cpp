#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_NUM 100000
vector<bool> che(MAX_NUM, false);
void makeChe(){
    che[0] = true, che[1] = true;
    for(ll i = 2; i <= MAX_NUM; i++){
        if(che[i]) continue;
        for(ll j = i * 2; j <= MAX_NUM; j += i){
            che[j] = true;
        }
    }
}
bool edgeCheck(ll number){
    for(int i = 2; i < che.size(); i++){
        if(number % i == 0) return false;
    }
    return true;
}
string changeNum(ll n, ll k){
    ll ret = 0;
    n *= k;
    for(ll i = 1; n /= k; i *= 10) {
        ret += (n % k) * i;
    }
    return to_string(ret);
}
int solution(int n, int k) {
    int answer = 0;
    string changed = changeNum(n, k);
    cout << changed << "\n";
    ll num = 0;
    makeChe();
    for(int i = 0; i < changed.size(); i++){
        if(changed[i] == '0'){
            if(num > MAX_NUM && edgeCheck(num)) answer++;
            else if(num < MAX_NUM && !che[num]) answer++;
            num = 0;
        }
        else{
            num = num * 10 + (changed[i] - '0');
        }
    }
    if(changed[changed.size() - 1] != '0'){
        if(num > MAX_NUM && edgeCheck(num)) answer++;
        else if(num < MAX_NUM && !che[num]) answer++;
    }
    return answer;
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << solution(N, K) << "\n";
}