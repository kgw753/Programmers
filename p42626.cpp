#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int n = 0;

    while(pq.size() >= 2 && pq.top() < K){
        n = pq.top();
        pq.pop();
        n += pq.top() * 2;
        pq.pop();
        pq.push(n);
        answer++;
    }

    return n >= K ? answer : -1;
}