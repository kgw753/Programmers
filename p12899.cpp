#include<bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    int nums[] = {4, 1, 2};
    while(n > 0){
        answer = to_string(nums[n % 3]) + answer;
        n = (n - 1) / 3;
    }
    return answer;
}