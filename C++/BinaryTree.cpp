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
    tree->insertNode(tree->root, 10);
    tree->insertNode(tree->root, 20);
    tree->insertNode(tree->root, 30);
    
    cout <<"List of nodes using In Order method:\n";
    tree->InOrder(tree->root);

    return 0;
}

/* Inserts node into the Binary Tree */
void BinaryTree::insertNode(Node *node, int data){
  if(!root){ //If the tree is empty, add a root node
    root = new Node(data);
  } else if(node){ //If the tree contains a root node, then traverse through the tree
    if(data > node->data){
      insertNode(node->right, data);
    } else {
      insertNode(node->left, data);
    }
  } else { //Adds a node
      node = new Node(data);
  }
}

/* Prints nodes using InOrder method */
void BinaryTree::InOrder(Node *root){
    if(root){
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}


/* Prints nodes using PreOrder method */
void BinaryTree::PreOrder(Node *root){
    if(root){
        cout << root->data <<" ";
        inOrder(root->left);
        inOrder(root->right);
    }
}


/* Prints nodes using PostOrder method */
void BinaryTree::PostOrder(Node *root){
    if(root){
        inOrder(root->left);
        inOrder(root->right);
        cout << root->data <<" ";
    }
}
