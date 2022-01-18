#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node* createNode(int key)
{
    Node *node= new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL; 
}

void postorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  if (node!=NULL)
  cout << node->key << "->";
  else
  cout << node->key<<endl;

}

int main()
{
    int key;
    cout<<"Enter the key value:";
    cin>>key;
    Node *root=createNode(key);
    int leftc,rightc;
    cout<<"Enter the left child:";
    cin>>leftc;
    cout<<"Enter the right child:";
    cin>>rightc;
    root->left=createNode(leftc);
    root->right=createNode(rightc);

    postorderTraversal(root);


        return 0;
}
