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

struct Node* newNode(int item)
{
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    temp -> data = item;
    temp -> left = nil;
    temp -> right = nil;
    temp -> parent = nil;
    temp -> color = "red";
    return temp;
}

void LEFT_ROTATE(struct Node* node)
{
    struct Node* y;
    y = node -> right;
    node -> right = y -> left;
    if(y -> left != nil)
    y -> left -> parent = node;
    y -> parent = node -> parent;
    if(node -> parent == nil)
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
    // std::cout << y -> data;
    node -> left = y -> right;
    if(y -> right != nil)
    y -> right -> parent = node;
    y -> parent = node -> parent;
    // std::cout << node -> data << std::endl;
    if(node -> parent == nil)
    {
        // std::cout << "aagyabhaiidhar" << std::endl;
        root = y;
    }
    else if(node == node -> parent -> left)
    node -> parent -> left = y;
    else
    node -> parent -> right = y;

    y -> right = node;
    node -> parent = y;
}

void INSERT_FIXUP(struct Node* node)
{
    while(node -> parent -> color == "red")
    {
        if(node -> parent == node -> parent -> parent -> left)
        {
            // std::cout << "idharhai" << std::endl;
            struct Node* y;
            y = node -> parent -> parent -> right;
            if(y!=nil && y -> color == "red")
            {
                // std::cout << "idharbhi" << std::endl;
                // This is case 1
                node -> parent -> color = "black";
                y -> color = "black";
                node -> parent -> parent -> color = "red";
                node = node -> parent -> parent;
            }
            else 
            {
                if(node == node -> parent -> right)
                {
                    // std::cout << "auridharhai" << std::endl;
                    // This is case 2
                    node = node -> parent;
                    LEFT_ROTATE(node);
                }
                // std::cout << "yahabhi" << std::endl;
                // This is case 3
                node -> parent -> color = "black";
                node -> parent -> parent -> color = "red";
                // std::cout << node -> parent -> parent -> data << std::endl;
                RIGHT_ROTATE(node -> parent -> parent);    
            }
            
        }
        else
        {
            // std::cout << "idharhai" << std::endl;
            struct Node* y;
            y = node -> parent -> parent -> left;
            if(y -> color == "red")
            {
                // std::cout << "idharbhi" << std::endl;
                // This is case 1
                node -> parent -> color = "black";
                y -> color = "black";
                node -> parent -> parent -> color = "red";
                node = node -> parent -> parent;
            }
            else 
            {
                if(node == node -> parent -> left)
                {
                    node = node -> parent;
                    RIGHT_ROTATE(node);
                }
                node -> parent -> color = "black";
                node -> parent -> parent -> color = "red";
                LEFT_ROTATE(node -> parent -> parent);    
            }   
        }
    }
    if(node == root && node -> color == "red")
    node -> color = "black";
}


void INSERT(int item)
{
    struct Node* node = newNode(item);
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
    if(root!=node)
    INSERT_FIXUP(node);
    else
    {
        root -> color = "black";
        // root -> parent = nil;
    }
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