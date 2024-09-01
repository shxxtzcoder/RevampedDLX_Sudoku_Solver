#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
    int row_ID;
    int column_ID;
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    Node* column;
    Node() : left(this), right(this), up(this), down(this), column(nullptr), row_ID(0), column_ID(0) {}
};
// here we have inherited the Node function into Column_Node
class Column_Node : public Node{
    public:
    string name;
    int size;
    Column_Node(): Node(), size(0){
        column=this;
    }
};