#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool valid_sudoku(vector<vector<int>> &matrix)
{
    unordered_map<int, unordered_set<int>> row;
    unordered_map<int, unordered_set<int>> col;
    vector<vector<unordered_set<int>>> squares(3, vector<unordered_set<int>>(3));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                continue;
            }
            // Check for duplicates in the row, column, and 3x3 square
            if (row[i].count(matrix[i][j]) || col[j].count(matrix[i][j]) || squares[i / 3][j / 3].count(matrix[i][j]))
            {
                return false;
            }
            // Insert the number into the corresponding row, column, and 3x3 square
            row[i].insert(matrix[i][j]);
            col[j].insert(matrix[i][j]);
            squares[i / 3][j / 3].insert(matrix[i][j]);
        }
    }

    return true;
}