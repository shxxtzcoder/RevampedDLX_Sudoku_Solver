#include <bits/stdc++.h>
// #include <vector>
using namespace std;
bool valid_sudoku(vector<vector<int>> &matrix);
vector<vector<int>> ConvertToExactCover(vector<vector<int>> &matrix);
class Node
{
public:
    int row_ID;
    int column_ID;
    Node *up;
    Node *down;
    Node *left;
    Node *right;
    Node *column;
    Node() : left(this), right(this), up(this), down(this), column(nullptr), row_ID(0), column_ID(0) {}
};
// this is how we have inherited node
class Column_Node : public Node
{
public:
    string name;
    int size;
    Column_Node() : Node(), size(0)
    {
        column = this;
    }
};

class DLX
{
public:
    DLX(vector<vector<int>> &exactcover);
    void search();
    vector<vector<int>> final;

private:
    Column_Node *header = new Column_Node();
    vector<int> solution;
    void create_links(vector<vector<int>> &exactcover);
    Column_Node *selectColumn();
    void cover(Column_Node *col);
    void uncover(Column_Node *col);
};

void print_sol(vector<vector<int>> &final);