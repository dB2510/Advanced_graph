#include<iostream>
#include "insertion.hpp"

void preorder_traversal(struct Node* node)
{
    if(node!=nil)
    {
        std::cout << node -> data << " " << node -> color << std::endl;
        preorder_traversal(node -> left);
        preorder_traversal(node -> right);
    }
}

int main()
{
    int nodes;
    std::cin >> nodes;
    nil = (struct Node *) malloc(sizeof(struct Node));
    nil -> color = "black";
    nil -> left = NULL;
    nil -> right = NULL;
    nil -> parent = NULL;
    root = nil; 
    while(nodes--)
    {
        struct Node* node;
        int x;
        std::cin >> x;
        INSERT(x);
    }
    // INSERT(11);
    // INSERT(2);
    // INSERT(1);
    // INSERT(7);
    // std::cout << root -> color << std::endl;
    preorder_traversal(root);
    return 0;
}

// 8
// 11
// 2
// 1
// 7
// 5
// 8
// 14
// 15