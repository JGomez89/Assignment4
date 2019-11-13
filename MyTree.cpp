#include <iostream>
#include <vector>
#include <stack>
#include "MyTree.h"
using namespace std;

//constructor
MyTree::MyTree(){
  nextLeaf = new BinaryNode;
  root = nextLeaf;
}

//deconstructor
MyTree::~MyTree(){

  deleteTree(root);
}

void MyTree::deleteTree(BinaryNode* curr){
  if(curr != nullptr){

    deleteTree(curr->lchild);
    deleteTree(curr->rchild);
    delete curr;
  }

}


//justin
void MyTree::insert(int userInt, string userString){
  BinaryNode* newNode = new BinaryNode(userString,userInt);
  bool isPlaced = false;
  if(root == nextLeaf){
    root = newNode;
    root->lchild = nextLeaf;
    nextLeaf->parent = root;
    isPlaced = true;
  }
  else{
    if(nextLeaf->parent->lchild == nextLeaf){
      nextLeaf->parent->lchild = newNode;
    }
    else{
      nextLeaf->parent->rchild = newNode;
    }
    newNode->parent = nextLeaf->parent;
  }
  // Find new position for nextLeaf
  for(BinaryNode* curr = nextLeaf; curr != root && !isPlaced; curr = curr->parent){
    if(curr->parent->lchild == curr || curr->parent->lchild == newNode){
      for(BinaryNode* temp = curr->parent->rchild; temp != nullptr && !isPlaced; temp = temp->lchild){
        if(temp->lchild == nullptr){
          temp->lchild = nextLeaf;
          nextLeaf->parent = temp;
          isPlaced = true;
        }
      }
      if(!isPlaced){
        curr->parent->rchild = nextLeaf;
        nextLeaf->parent = curr->parent;
        isPlaced = true;
      }
    }
  }
  if(!isPlaced){
    for(BinaryNode* curr = root; curr != nullptr && !isPlaced; curr = curr->lchild){
      if(curr->lchild == nullptr){
        curr->lchild = nextLeaf;
        nextLeaf->parent = curr;
        isPlaced = true;
      }
    }
  }
}

//justin
void MyTree::preorder() const{
  if(root != nextLeaf){
    PrintPreOrder(root);
  }
  else{
    cout << "Tree is currently empty." << endl;
  }
}

//justin
void MyTree::PrintPreOrder(BinaryNode* currPtr) const{
  if(currPtr != nullptr && currPtr != nextLeaf){
    // if(depth != 0){
    //   cout << endl;
    // }
    // for(unsigned i = 0; i < depth; ++i){
    //   cout << "  ";
    // }
    if(currPtr != root){
      cout << " " << currPtr->myString;
    }
    else{
      cout << currPtr->myString;
    }
    // PrintPreOrder(currPtr->lchild,depth+1);
    // PrintPreOrder(currPtr->rchild,depth+1);
    PrintPreOrder(currPtr->lchild);
    PrintPreOrder(currPtr->rchild);
  }
}


//findMax of Binary Node
BinaryNode* MyTree::findMax() const{

  return max(root, root);
}

BinaryNode* MyTree::max(BinaryNode* curr, BinaryNode* largestNode) const{
  if(curr != nullptr){

    if(largestNode->myInt < curr->myInt){

      largestNode = curr;
    }
    largestNode = max(curr->lchild, largestNode);
    largestNode = max(curr->rchild,largestNode);
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

  if(curr != nullptr && curr != nextLeaf){

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
