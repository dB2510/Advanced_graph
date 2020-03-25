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

void RIGHT_ROTATE(struct Node* node)
{
    struct Node* y;
    y = node -> left;
    node -> left = y -> right;
    if(y -> right != nil)
    y -> right -> parent = node;
    y -> parent = node -> parent;
    if(node -> parent != nil)
    root = y;
    else if(node == node -> parent -> left)
    node -> parent -> left = y;
    else
    node -> parent -> right = y;

    y -> right = node;
    node -> parent = y;
}

void INSERT_FIXUP(struct Node* node)
{
    
}


void INSERT(struct Node* node)
{
    struct Node* y;
    struct Node* x;
    y = nil;
    x = root;
    while(x != nil)
    {
        y = x;
        if(node -> data < x -> data)
        x = x -> left;
        else
        x = x -> right;
    }
    node -> parent = y;
    if(y == nil)
    root = node;
    else if(node -> data < y -> data)
    y -> left = node;
    else
    y -> right = node;
    node -> left = nil;
    node -> right = nil;
    node -> color = "red";
    INSERT_FIXUP(node);
}

int main()
{
    int nodes;
    std::cin >> nodes;

}