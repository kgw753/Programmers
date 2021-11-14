#include <bits/stdc++.h>

using namespace std;

int sz;
bool sorted(vector<pair<int, int>> numbers){
    for(int i = 1; i < sz; i++){
        if(numbers[i - 1].first > numbers[i].first) return false;
    }
    return true;
}
int countMoves(vector<int> numbers) {
    int ret = 0;
    sz = (int)numbers.size();
    vector<pair<int, int>> v(sz);
    for(int i = 0; i < sz; i++) {
        v[i] = {numbers[i], i};
    }
    for(int i = 0; i < (int)sz - 1; i++){
        if(sorted(v)) break;
        ret++;
        for(int j = i; j < sz - 1; j++){
            if(v[j].first > v[j + 1].first && v[j].second < v[j + 1].second)
                swap(v[j], v[j + 1]);
        }
    }
    return ret;
}
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << countMoves(v) << "\n";
}