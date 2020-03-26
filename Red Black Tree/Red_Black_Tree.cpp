#include<iostream>
#include "insertion.hpp"


struct Node* search(struct Node* x, int item)
{
    if(x == nil || item == x -> data)
    return x;
    if(item < x -> data)
    return search(x -> left, item);
    return search(x -> right, item); 
}

struct Node* TREE_MINIMUM(struct Node* x)
{
    while(x -> left != nil)
    x = x -> left;
    return x;
}

void TRANSPLANT(struct Node* u,struct Node* v)
{
    if(u -> parent == nil)
    root = v;
    else if(u == u -> parent -> left)
    u -> parent -> left = v;
    else
    u -> parent -> right = v;
    v -> parent = u -> parent;
}

void DELETE_FIXUP(struct Node* x)
{
    while(x != root && x -> color == "black")
    {
        if(x == x -> parent -> left)
        {   
            struct Node* w;
            w = x -> parent -> right;
            if(w -> color == "red")
            {
                // This is case 1
                w -> color = "black";
                x -> parent -> color = "red";
                LEFT_ROTATE(x -> parent);
                w = x -> parent -> right;
            }
            if(w -> left -> color == "black" && w -> right -> color == "black")
            {
                // This is case 2
                w -> color = "red";
                x = x -> parent;
            }
            else
            {
                if(w -> right -> color == "black")
                {
                    // This is case 3
                    w -> left -> color = "black";
                    w -> color = "red";
                    RIGHT_ROTATE(w);
                    w = x -> parent -> right;
                }
                // This is case 4
                w -> color = x -> parent -> color;
                x -> parent -> color = "black";
                w -> right -> color = "black";
                LEFT_ROTATE(x -> parent);
                x = root;
            }
        }
        else
        {
            struct Node* w;
            w = x -> parent -> left;
            if(w -> color == "red")
            {
                // This is case 1
                w -> color = "black";
                x -> parent -> color = "red";
                RIGHT_ROTATE(x -> parent);
                w = x -> parent -> left;
            }
            if(w -> left -> color == "black" && w -> right -> color == "black")
            {
                // This is case 2
                w -> color = "red";
                x = x -> parent;
            }
            else
            {
                if(w -> left -> color == "black")
                {
                    // This is case 3
                    w -> right -> color = "black";
                    w -> color = "red";
                    LEFT_ROTATE(w);
                    w = x -> parent -> left;
                }
                // This is case 4
                w -> color = x -> parent -> color;
                x -> parent -> color = "black";
                w -> left -> color = "black";
                RIGHT_ROTATE(x -> parent);
                x = root;
            }
        }
    }
    x -> color = "black";
}

void DELETE(struct Node* z)
{
    struct Node* y;
    struct Node* x;
    y = z;
    std::string y_original_color = y -> color;
    if(z -> left == nil)
    {
        x = z -> right;
        TRANSPLANT(z, z -> right);
    }
    else if(z -> right == nil)
    {
        x = z -> left;
        TRANSPLANT(z, z -> left);
    }
    else
    {
        y = TREE_MINIMUM(z -> right);
        y_original_color = y -> color;
        x = y -> right;
        if(y -> parent == z)
        x -> parent = y;
        else
        {
            TRANSPLANT(y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }
        TRANSPLANT(z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
        y -> color = z -> color;        
    }
    if(y_original_color == "black")
    DELETE_FIXUP(x);
    
}

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
    // int nodes;
    // std::cin >> nodes;
    nil = (struct Node *) malloc(sizeof(struct Node));
    nil -> color = "black";
    nil -> left = NULL;
    nil -> right = NULL;
    nil -> parent = NULL;
    root = nil; 
    // while(nodes--)
    // {
    //     struct Node* node;
    //     int x;
    //     std::cin >> x;
    //     INSERT(x);
    // }
    INSERT(11);
    INSERT(2);
    INSERT(1);
    INSERT(7);
    struct Node* x;
    x = search(root, 2);
    // std::cout << x -> data <<" "<<x -> color << std::endl;
    preorder_traversal(root);
    DELETE(x);
    std::cout << "Delete karne k baad" << std::endl;
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