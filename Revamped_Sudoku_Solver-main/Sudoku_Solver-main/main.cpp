#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "all_func.h"
using namespace std;

int main()
{
    const int n = 9;
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Please enter the Sudoku puzzle to be solved (use 0 for empty cells):" << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    // now we can first check whether the given sudoku is valid or not
    if (valid_sudoku(matrix))
    {
        vector<vector<int>> exactcover = ConvertToExactCover(matrix);
        DLX dlx(exactcover);
        dlx.search();
        print_sol(dlx.final);
    }
    else
    {
        cout << "The Sudoku you have entered is invalid!" << endl;
    }

    return 0;
}
