#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b){
    if(a == 0) return b;
    else return GCD(b % a, a);
}
int LSM(int a, int b){
    return (a * b) / GCD(a, b);
}
int solution(vector<int> arr) {
    int ret = 1;
    for(int n : arr){
        ret = LSM(ret, n);
    }
    return ret;
}