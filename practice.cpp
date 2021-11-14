#include<bits/stdc++.h>
using namespace std;
#define MAX 10000004
bool check(int num){
    if(num == 1 || num == 0) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    set<int> st;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i = 1; i <= numbers.length(); i++){
            int num = stoi(numbers.substr(0, i));
            if(check(num)){
                st.insert(num);
            }
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    for(int i : st) cout << i << "\n";
    return st.size();
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}