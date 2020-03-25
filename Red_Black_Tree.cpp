#include<iostream>

struct Node{
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int data;
    std::string color;
};

struct Node* nil;
struct Node* root;

void LEFT_ROTATE(struct Node* node)
{
    struct Node* y;
    y = node -> right;
    node -> right = y -> left;
    if(y -> left != nil)
    y -> left -> parent = node;
    y -> parent = node -> parent;
    if(node -> parent != nil)
    root = y;
    else if(node == node -> parent -> left)
    node -> parent -> left = y;
    else
    node -> parent -> right = y;

    y -> left = node;
    node -> parent = y;
}

void RIGHT_ROTATE(struct N)

int main()
{
    int nodes;
    std::cin >> nodes;

}