#include<bits/stdc++.h>
using namespace std;
#define MAX 10000004
bool checkPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    set<int> st;
    int num;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i = 1; i <= numbers.length(); i++){
            num = stoi(numbers.substr(0, i));
            if(checkPrime(num)) st.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    return st.size();
}
int main(){
    string input;
    cin >> input;
    cout << solution(input) << "\n";
}