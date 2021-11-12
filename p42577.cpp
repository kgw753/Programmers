#include<bits/stdc++.h>
using namespace std;
bool solution(vector<string> phone_book) {
    map<string, int> mp;
    for(string phone : phone_book){
        mp[phone]++;
    }
    for(string phone : phone_book){
        string cmp = "";
        for(int i = 0; i < phone.length() - 1; i++){
            cmp += phone[i];
            if(mp[cmp]) return false;
        }
    }
    return true;
}
bool solution2(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++){
        if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) return false;
    }
    return true;
}