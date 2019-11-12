#include <iostream>
#include <vector>
#include "MyTree.h"
using namespace std;

//constructor
MyTree::MyTree(){

  root = nullptr;
}

//deconstructor
MyTree::~MyTree(){
  


}

/*
//justin
void MyTree::Insert(int userInt, string userString){
  BinaryNode* newNode = new BinaryNode(userInt,userString);
  if(root == nullptr){
    root = newNode;
    root->left = nextLeaf;
    nextLeaf->parent = root;
  }
  else{
    if(nextLeaf->parent->left == nextLeaf){
      nextLeaf->parent->left = newNode;
    }
    else{
      nextLeaf->parent->right = newNode;
    }
    newNode->parent = nextLeaf->parent;
  }
  // Find new position for nextLeaf
  bool isPlaced = false;
  for(BinaryNode* curr = nextLeaf; curr != root && !isPlaced; curr = curr->parent){
    if(curr->parent->left == curr || curr->parent->left == newNode){
      for(BinaryNode* temp = curr->parent->right; temp != nullptr && !isPlaced; temp = temp->left){
        if(temp->left == nullptr){
          temp->left = nextLeaf;
          nextLeaf->parent = temp;
          isPlaced = true;
        }
      }
      if(!isPlaced){
        curr->parent->right = nextLeaf;
        nextLeaf->parent = curr->parent;
        isPlaced = true;
      }
    }
  }
  if(!isPlaced){
    for(BinaryNode* curr = root; curr != nullptr && !isPlaced; curr = curr->left){
      if(curr->left == nullptr){
        curr->left = nextLeaf;
        nextLeaf->parent = curr;
        isPlaced = true;
      }
    }
  }
  ++height;
}



//justin 
void MyTree::PrintPreOrder(BinaryNode* currPtr, int depth){
  if(currPtr != nullptr){
    if(depth != 0){
      cout << endl;
    }
    for(unsigned i = 0; i < depth; ++i){
      cout << "  ";
    }
    cout << currPtr->dataString;
    PrintPreOrder(currPtr->left,depth+1);
    PrintPreOrder(currPtr->right,depth+1);
  }
}*/

//findMax of Binary Node
BinaryNode* MyTree::findMax() const{

  return max(root, root);
}

BinaryNode* MyTree::max(BinaryNode* curr, BinaryNode* largestNode) const{
  if(curr != nullptr){

    if(largestNode->myInt < curr->myInt){

      largestNode = curr;
    }
    max(curr->lchild, largestNode);
    max(curr->rchild,largestNode);
  }

  return largestNode;
}



//make Binary Search Tree
void MyTree::makeBST(){

  vector<BinaryNode*> treeVector = createVector(root);
  int index = 0;

  sort(treeVector.begin(), treeVector.end());

  treeToBST(root, treeVector, index);



}

//return array head
vector<BinaryNode*> MyTree::createVector(BinaryNode *curr){

  vector<BinaryNode*> treeVector;

  if(curr != nullptr){

    createVector(curr->lchild);

    treeVector.push_back(curr);

    createVector(curr->rchild);

  }

  return treeVector;

}

void MyTree::treeToBST(BinaryNode* curr, vector<BinaryNode*> myVector, int index){

  if(curr != nullptr){

    treeToBST(curr->lchild, myVector, index);

    curr->myInt = (myVector.at(index))->myInt;
    curr->myString = (myVector.at(index))->myString;
    ++index;

    treeToBST(curr->rchild, myVector, index);
  } 
}

/*
//justin
void MyTree::PreOrder() const{
  if(root != nullptr){
    PrintPreOrder(root,0);
  }
  else{
    cout << "Tree is currently empty." << endl;
  }
}*/
