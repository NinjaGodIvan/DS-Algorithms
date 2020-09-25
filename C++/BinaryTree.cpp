#include <iostream>
using nsamespace std;

struct Node{
  int data;
  Node *left = nullptr, *right = *nullptr;
  Node(int data){
    this->data = data;
  }
};

class BinaryTree{
  public:
    void insertNode(int);
    void preOrder();
    void inOrder();
    void postOrder();
    Node *getRoot()
    {return this.root};
  private:
    Node *root = nullptr;
}

int main(){
  
 BinaryTree tree = new BinaryTree();
 tree->insertNode(tree->getRoot(), 10);

  return 0;
}

void BinaryTree::insertNode(Node *root, int data){
  if(!root){
    root = new Node(data);
  } else {
    if(data > root->data){
      insertNode(root->right)
    } else {
      insertNode(root->left)
    }
  }
}
