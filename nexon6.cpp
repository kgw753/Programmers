#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const string v4 = "IPv4";
const string v6 = "IPv6";
const string nothing = "Neither";


string isV4(string str){
    string tmp = "";
    for(char c : str){
        if(c == ':') return nothing;
        if(c == '.'){
            
        }
    }
    return "";
}
string isV6(string str){
    string tmp = "";
    for(char c : str){
        if(c == '.') return nothing;
    }
    return "";
}
string parsing(string str){
    int i = 0;
    int len = min((int)str.length(), 5);
    for(i = 0; i < len; i++){
        if(str[i] == '.' || str[i] == ':') break;
    }
    if(i == str.length()) return nothing;
    else if(str[i] == '.') return isV4(str);
    else return isV6(str);
}

vector<string> validateAddresses(vector<string> addresses) {
    vector<string> ret;
    for(string str : addresses){
        ret.push_back(parsing(str));
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    vector<string> ans = validateAddresses(v);
    for(string s : ans) cout << s << "\n";
}
