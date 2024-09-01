#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "all_func.h"
using namespace std;

DLX::DLX(vector<vector<int>> &exactcover)
{
    int num_col = exactcover[0].size();
    create_links(exactcover);
}

void DLX::search()
{
    if (header->right == header)
    {
        final.push_back(solution);
        return;
    }
    Column_Node *column = selectColumn();
    cover(column);

    for (Node *i = column->down; i != column; i = i->down)
    {

        solution.push_back(i->row_ID);
        for (Node *j = i->right; j != i; j = j->right)
        {
            cover(static_cast<Column_Node *>(j->column));
        }
        search();
        solution.pop_back();
        for (Node *j = i->left; j != i; j = j->left)
        {
            uncover(static_cast<Column_Node *>(j->column));
        }
    }
    uncover(column);
}

void DLX::create_links(vector<vector<int>> &exactcover)
{
    int num = 324;
    vector<Column_Node *> columnnode(num);
    Column_Node *current_col = header;
    // // now we will make columnnode which act as a header for all columns
    for (int i = 0; i < num; i++)
    {
        Column_Node *column = new Column_Node();
        column->name = "Column " + to_string(i);
        column->size = 0;
        current_col->right = column;
        column->left = current_col;
        columnnode[i] = column;
        current_col = column;
    }
    current_col->right = header;
    header->left = current_col;

    for (int i = 0; i < 729; i++)
    {
        Node *firstnode = NULL;
        for (int j = 0; j < 324; j++)
        {
            if (exactcover[i][j] == 0)
            {
                continue;
            }
            Node *newnode = new Node();
            newnode->column = columnnode[j]; // this will be later useful when we want to decrease the size of a node from a random node in col
            newnode->row_ID = i;
            newnode->column_ID = j;

            newnode->up = columnnode[j]->up; // newnode point to the currest last node of columnnode[j]
            newnode->down = columnnode[j];
            columnnode[j]->up->down = newnode; // basically the last node of the columnnode[j] which is now the second last node points to newnode in downward direction
            columnnode[j]->up = newnode;       // this makes newnode the last node of columnnode[j]
            columnnode[j]->size++;             // increasing the size of columnnode

            if (firstnode == NULL)
            {
                firstnode = newnode;
            }
            else
            {
                newnode->left = firstnode->left;
                newnode->right = firstnode;
                firstnode->left->right = newnode;
                firstnode->left = newnode;
            }
        }
    }
}

Column_Node *DLX::selectColumn()
{
    // here we just want to get the column with min 1s
    Column_Node *col = static_cast<Column_Node *>(header->right);
    // the reason why we have to typecast is becuase in class node, we have declared left and right function as node
    // that is why even when columnnode are declared as Column_Node* we still have to static_cast them
    for (Node *nod = header->right; nod != header; nod = nod->right)
    {
        if (static_cast<Column_Node *>(nod)->size < col->size)
        {
            col = static_cast<Column_Node *>(nod);
        }
    }
    return col;
}

void DLX::cover(Column_Node *col)
{
    // here we basically detach the column first, and then we detach all teh rows present in teh column
    col->right->left = col->left;
    col->left->right = col->right;
    for (Node *nod = col->down; nod != col; nod = nod->down)
    {
        for (Node *r = nod->right; r != nod; r = r->right)
        {
            r->down->up = r->up;
            r->up->down = r->down;
            static_cast<Column_Node *>(r->column)->size--;
        }
    }
}

void DLX::uncover(Column_Node *col)
{
    for (Node *i = col->up; i != col; i = i->up)
    {
        for (Node *j = i->left; j != i; j = j->left)
        {
            static_cast<Column_Node *>(j->column)->size++;
            j->down->up = j;
            j->up->down = j;
        }
    }
    col->right->left = col;
    col->left->right = col;
}
