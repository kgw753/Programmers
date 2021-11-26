#include<bits/stdc++.h>
using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < arr1.size(); i++){
        string str = "";
        for(int j = 0; j < n; j++){
            int bm = 1 << j;
            if((bm & arr1[i]) || (bm & arr2[i])) str.push_back('#');
            else str.push_back(' ');
        }
        reverse(str.begin(), str.end());
        answer.push_back(str);
    }
    return answer;
}