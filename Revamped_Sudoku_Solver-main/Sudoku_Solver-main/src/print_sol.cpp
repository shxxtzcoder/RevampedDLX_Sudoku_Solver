#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_sol(vector<vector<int>> &final)
{
    cout << "The no. of solutions for the above sudoku are: " << final.size() << endl;
    for (int i = 0; i < final.size(); i++)
    {
        cout << "Solution :" << i + 1 << endl;
        vector<vector<int>> sudoku(9, vector<int>(9));
        for (auto num : final[i])
        {
            int row = num / 81;
            int col = (num - (num / 81) * 81) / 9;
            int number = num - (row * 81) - (col * 9) + 1;
            sudoku[row][col] = number;
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    }
}