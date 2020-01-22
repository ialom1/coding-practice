#include <iostream>

struct Node{
  int data;
  Node *left, *right;
};
struct BSTara{
  int ara[1000];
  int k = 0;
};
BSTara bstara;
void _preorder(Node *root){
  if(root == NULL){
    return;
  }
  std::cout << root->data << ' ';
  bstara.ara[bstara.k++] = root->data;
  _preorder(root->left);
  _preorder(root->right);
}
Node* newNode(int data){
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
Node* sortedArrayToBST(int ara[], int start, int end){
  if(start > end) return NULL;

  int mid = (start + end)/2;

  Node *root = newNode(ara[mid]);

  root->left = sortedArrayToBST(ara, start, mid-1);
  root->right = sortedArrayToBST(ara, mid+1, end);

  return root;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  /* Convert List to BST */
  Node *root = sortedArrayToBST(arr, 0, n-1);

  std::cout << "Pre order traversl: " << '\n';
  _preorder(root);
  std::cout << "\n\n";

  std::cout << "BST Array" << '\n';
  for(int i=0; i<bstara.k; i++){
    std::cout << bstara.ara[i] << ' ';
  }
  return 0;
}
