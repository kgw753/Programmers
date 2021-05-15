#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int tmp;
    while(b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

long long solution(int w,int h) {
    int g = gcd(w, h);
    long long answer = ((long)w * h) - (((long)w / g) + ((long)h / g) - 1) * g;

    return answer;
}