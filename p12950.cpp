#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr1[i].size(); j++){
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}

int main()
{
    vector<vector<int> > a{ { 1, 2 }, { 2, 3 } }, b{ { 3, 4 }, { 5, 6 } };
    vector<vector<int> > answer = solution(a, b);

    for (int i = 0; i<answer.size(); i++)
    {
        for (int j = 0; j<answer[0].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}