#include <vector>
#include <iostream>

using namespace std;
int GetRowIndex(int row, int col, int num)
{
    return (row * 81 + col * 9 + num - 1);
}

int GetCellConstIndex(int row, int col)
{
    return (row * 9 + col);
}

int GetRowConstIndex(int row, int num)
{
    return (81 + row * 9 + num - 1);
}

int GetColumnConstIndex(int col, int num)
{
    return (162 + col * 9 + num - 1);
}

int GetRegionConstIndex(int row, int col, int num)
{
    int box = (row / 3) * 3 + (col / 3);
    return (243 + box * 9 + num - 1);
}

vector<vector<int>> ConvertToExactCover(vector<vector<int>> &matrix)
{
    const int n = 9;
    const int size = 9 * 9 * 9;
    const int constraints = 4 * 9 * 9;
    vector<vector<int>> ExactCover(size, vector<int>(constraints));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            for (int num = 1; num <= 9; num++)
            {
                if (matrix[row][col] == 0 || matrix[row][col] == num)
                {
                    int row_index = GetRowIndex(row, col, num);
                    ExactCover[row_index][GetCellConstIndex(row, col)] = 1;
                    ExactCover[row_index][GetRowConstIndex(row, num)] = 1;
                    ExactCover[row_index][GetColumnConstIndex(col, num)] = 1;
                    ExactCover[row_index][GetRegionConstIndex(row, col, num)] = 1;
                }
            }
        }
    }
    return ExactCover;
}