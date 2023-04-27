#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL){
        return;
    }
    traverseInOrder(root->left);
    cout << root->key <<" ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    //if tree is empty create a new node
    if(node == NULL){
        node = new struct node;
        node->key = key;
        node->left = node->right = NULL;
    }
    //if the key is less than or equal to the root key, insert it to the left sub tree
    else if(key<=node->key){
        node->left = insertNode(node->left,key);
    } 
    //if the key is greater than the root key, insert it to the right sub tree
    else {
        node->right = insertNode(node->right,key);
    }
    
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    //if the tree is empty,return NULL
    if(root==NULL){
        return NULL;
    }
    //if the key is less than root key delete from the left sub tree
    if(key < root->key){
        root->left = deleteNode(root->left,key);
    }
    //if the key is grater than root key delete from the right sub tree
    else if(key > root->key){
        root->right = deleteNode(root->right,key);
    }
    //if key is found, delete the node
    else{
        //Case 1: Node has no children
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //Case 2: Node has one child
        else if(root->left == NULL){
            struct node*temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            struct node*temp = root;
            root = root->left;
            delete temp;
        }
        //Case 3: Node has two children
        else{
            struct node*temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }
    return root; 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}