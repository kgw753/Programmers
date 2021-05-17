#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> nums) {
    unordered_map<int, int> map;
    for(auto i : nums){
        map[i]++;
    }

    return min(map.size(), nums.size() / 2);
}