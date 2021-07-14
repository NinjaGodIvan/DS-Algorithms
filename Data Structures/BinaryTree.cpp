#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *left = nullptr, *right = nullptr;
  Node(int data){
    this->data = data;
  }
};

class BinaryTree{
  public:
    void insertNode(Node*, int);
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    Node *root = nullptr;
};

int main(){
  
    BinaryTree *tree = new BinaryTree();
    tree->insertNode(tree->root, 20);
    tree->insertNode(tree->root, 10);
    tree->insertNode(tree->root, 40);
    tree->insertNode(tree->root, 30);
    
    cout <<"List of nodes using In Order method:\n";
    tree->InOrder(tree->root);
    cout << endl << endl;
    
    cout <<"List of nodes using Pre Order method:\n";
    tree->PreOrder(tree->root);
    cout << endl << endl;
    
    cout <<"List of nodes using Post Order method:\n";
    tree->PostOrder(tree->root);

    return 0;
}

/* Inserts node into the Binary Tree */
void BinaryTree::insertNode(Node *node, int data){
  if(!root){ //If the tree is empty, add a root node
    root = new Node(data);
  } else { //If the tree contains a root node, then traverse through the tree
        if(data > node->data){
            if(node->right)
                insertNode(node->right, data);
            else
                node->right = new Node(data);
        } else {
            if(node->left)
                insertNode(node->left, data);
            else 
                node->left = new Node(data);
        }
    }
}

/* Prints nodes using InOrder method */
void BinaryTree::InOrder(Node *node){
    if(node){
        InOrder(node->left);
        cout << node->data <<" ";
        InOrder(node->right);
    }
}


/* Prints nodes using PreOrder method */
void BinaryTree::PreOrder(Node *node){
    if(node){
        cout << node->data <<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}


/* Prints nodes using PostOrder method */
void BinaryTree::PostOrder(Node *node){
    if(node){
        PostOrder(node->left);
        PostOrder(node->right);
        cout << node->data <<" ";
    }
}
