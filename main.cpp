#include <bits/stdc++.h>
using namespace std;
struct treeNode{
  int data;
  int level;
  string data1="";
  treeNode* parent = nullptr;
  treeNode* right = nullptr;
  treeNode* left = nullptr;
};
class binarytree{
  public:
    treeNode* root = nullptr; 
    void preOrder(treeNode* current);
    void inOrder(treeNode* current);
    void postOrder(treeNode* current);
    void levelOrder();
    void levelOrderConstruct(string input);

};
void binarytree::preOrder(treeNode* current){
  if(current){
    cout<<current->data1<<" ";
    preOrder(current->left);
    preOrder(current->right);
  }
}
void binarytree::inOrder(treeNode *current){
  if(current){
    inOrder(current->left);
    cout<<current->data1<<" ";
    inOrder(current->right);
  }
}
void binarytree::postOrder(treeNode *current){
  if(current){
    postOrder(current->left);
    postOrder(current->right);
    cout<<current->data1<<" ";
  }
}
void binarytree::levelOrder(){
  queue<treeNode*> que;
  que.push(this->root);
  while(!que.empty()){
    treeNode* current;
    current=que.front();
    que.pop();
    cout<<current->data1<<" ";
    if (current->left){
      que.push(current->left);
    }
    if (current->right){
      que.push(current->right);
    }
  }

}
void binarytree::levelOrderConstruct(string input){
  stringstream ss;
  ss<<input;
  queue<treeNode**> q;
  char currentData;
  while(ss>>currentData){
    treeNode* currentNode =new treeNode();
    //The 'new' operator is very important!! If not type that,the compiler will not allocate the memory to new struct.
    currentNode->data1=currentData;
    if(!this->root){
      this->root=currentNode;
      q.push(&root-> left);
      q.push(&root->right);
    }
    else if(currentData=='x'){
      q.pop();
    }
    else{
      *q.front()=currentNode;
      q.push(&((*q.front())->left));
      q.push(&((*q.front())->right));
//The operators Precedence '->' > '*' = '&', so we need to separate operators with quote. 
      q.pop();
    }
  }
}
int main(){
  binarytree test;
  test.levelOrderConstruct("a b c d e f g x h x i x j k x l");
  test.preOrder(test.root);
  test.postOrder(test.root);
  test.inOrder(test.root);
  test.levelOrder();
}