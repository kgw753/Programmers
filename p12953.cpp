#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}
int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}
int solution(vector<int> arr) {
    int ret = 1;
    for(int num : arr){
        ret = LCM(ret, num);
    }
    return ret;
}
int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << solution(arr) << "\n";
}