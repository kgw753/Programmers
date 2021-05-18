#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int i;
    sort(d.begin(), d.end());
    for(i = 0; d[i] <= budget && i < d.size(); i++){
        budget -= d[i];
    }
    return i;
}