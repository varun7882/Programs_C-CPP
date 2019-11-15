#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
bool isSafe(vector<string> &chess, int row, int col)
{
    //check in that column
    int n = chess.size();
    int i, j;
    for (i = row; i >= 0; i--)
    {
        if (chess[i][col] == 'Q')
        {
            return false;
        }
    }
    //diagonally left;
    i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (chess[i][j] == 'Q')
        {
            return false;
        }
        i--;j--;
    }

    //diagonally right;
    i = row, j = col;
    while (i >= 0 && j<n)
    {
        if (chess[i][j] == 'Q')
        {
            return false;
        }
        i--;j++;
    }
    return true;
}
void solveIt(vector<string> &chess, int row, vector<vector<string>> &ans)
{
    int n = chess.size();
    if (row == n)
    {
       // cout<<"found solution";
        ans.push_back(chess);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(chess, row, i))
        {
            chess[row][i] = 'Q';
            solveIt(chess, row + 1, ans);
            chess[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> chess;
    string row(n, '.');
    for (int i = 0; i < n; i++)
    {
        chess.push_back(row);
    }
    solveIt(chess, 0, ans);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> ans = solveNQueens(n);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << i + 1 << ".\n";
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << "\n";
            }
            cout << "\n\n";
        }
    }
}
