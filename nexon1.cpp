#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER_ARRAY arr
 *  3. INTEGER_ARRAY query_values
 */

vector<int> solve(int X, vector<int> arr, vector<int> query_values) {
    vector<int> ret;
    int mem[arr.size()];
    memset(mem, -1, sizeof(mem));
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == X) mem[++cnt] = i + 1;
    }
    for(int q : query_values){
        if(q >= arr.size()){
            ret.push_back(-1);
        }
        else{
            ret.push_back(mem[q]);
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string query_values_count_temp;
    getline(cin, query_values_count_temp);

    int query_values_count = stoi(ltrim(rtrim(query_values_count_temp)));

    vector<int> query_values(query_values_count);

    for (int i = 0; i < query_values_count; i++) {
        string query_values_item_temp;
        getline(cin, query_values_item_temp);

        int query_values_item = stoi(ltrim(rtrim(query_values_item_temp)));

        query_values[i] = query_values_item;
    }

    vector<int> result = solve(X, arr, query_values);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
