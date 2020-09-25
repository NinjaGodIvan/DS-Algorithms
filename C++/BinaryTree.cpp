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
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    Node *getRoot()
    {return this->root;}
  private:
    Node *root = nullptr;
};

int main(){
  
    BinaryTree *tree = new BinaryTree();
    tree->insertNode(tree->getRoot(), 10);
    tree->insertNode(tree->getRoot(), 20);
    tree->insertNode(tree->getRoot(), 30);
    
    cout <<"List of nodes using In Order method:\n";
    tree->inOrder(tree->getRoot());

    return 0;
}

/* Inserts node into the Binary Tree */
void BinaryTree::insertNode(Node *node, int data){
  if(!root){ //If the tree is empty, add a root
    root = new Node(data);
  } else if(node){ //If the tree contains a root, then traverse
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
void BinaryTree::inOrder(Node *root){
    if(root){
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
