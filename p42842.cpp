#include<bits/stdc++.h>
using namespace std;
bool check(int x, int y, int brown, int yellow){
    bool ret = false;
    if(brown + yellow == x * y){
        if(x * 2 + (y - 2) * 2 == brown) ret = true;
    }
    return ret;
}
vector<int> solution(int brown, int yellow) {
    vector<int> ans;
    int x = 0, y = 0, flag = 0;
    while(true){
        x++;
        for(y = 1; y <= x; y++){
            if(check(x, y, brown, yellow)){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
int main(){
    int b, y;
    cin >> b >> y;
    vector<int> v = solution(b, y);
    for(int i : v) cout << i << " ";
    cout << "\n";
}