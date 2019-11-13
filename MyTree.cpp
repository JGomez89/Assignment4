#include <iostream>
#include <vector>
#include <vector>
#include <utility>
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
void MyTree::PrintPreOrder(BinaryNode* currPtr) const{
  if(currPtr != nullptr && currPtr != nextLeaf){
    if(depth != 0){
      cout << endl;
    }
    for(unsigned i = 0; i < depth; ++i){
      cout << "  ";
    }
    if(currPtr != root){
      cout << " " << currPtr->myString;
    }
    else{
      cout << currPtr->myString;
    }
    PrintPreOrder(currPtr->lchild,depth+1);
    PrintPreOrder(currPtr->rchild,depth+1);
    // PrintPreOrder(currPtr->lchild);
    // PrintPreOrder(currPtr->rchild);
  }
}

void MyTree::preorder() const{
  if(root != nextLeaf){
    PrintPreOrder(root);
  }
  else{
    cout << "Tree is currently empty." << endl;
  }
}

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


// Not Done
void MyTree::makeBST(){

  vector<nodePair> treeVector;
  createVector(root, treeVector);

  int index = treeVector.size()/2;

  sort(treeVector.begin(), treeVector.end());

  cout << "VEC SIZE: " << treeVector.size() << endl;

  for(unsigned i = 0; i < treeVector.size(); ++i){

    cout << "FIRST: ";
    cout << treeVector.at(i).first;
    cout << ", SECOND: ";
    cout << treeVector.at(i).second << endl;

  }

  treeToBST(root, treeVector, index);


  /*
  //
  BinaryNode *temp = root;
  while(temp->rchild != nullptr){

    temp = temp->rchild;
  }

  temp->myInt = treeVector.at(treeVector.size()-1).first;
  temp->myString = treeVector.at(treeVector.size()-1).second;*/
  
}

void MyTree::createVector(BinaryNode *curr, vector<nodePair> &treeVector){

  nodePair x;

  if(curr != nullptr && curr != nextLeaf){

    createVector(curr->lchild, treeVector);

    x.first = curr->myInt;
    x.second = curr->myString;
    treeVector.push_back(x);

    createVector(curr->rchild, treeVector);

  }

}
void MyTree::treeToBST(BinaryNode* curr, vector<nodePair> myVector, int index){
  if(curr != nullptr && index < myVector.size()){

  
    treeToBST(curr->lchild, myVector, index - 1);

    curr->myInt = myVector.at(index).first;
    curr->myString = myVector.at(index).second;

    index++;

    treeToBST(curr->rchild, myVector, index + 1);
  }
}
