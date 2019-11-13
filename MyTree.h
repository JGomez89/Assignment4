#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,string> nodePair;

class MyTree;

class BinaryNode {
public:
  BinaryNode():myString("Null"),myInt(-1),lchild(nullptr),rchild(nullptr),parent(nullptr){};
  BinaryNode(string s, int m):myString(s),myInt(m),lchild(nullptr),rchild(nullptr),parent(nullptr){};
  ~BinaryNode() {};
  int getInt() const {return myInt;};
  string getString() const {return myString;};
private:
  string myString;
  int myInt;
  BinaryNode *lchild;
  BinaryNode *rchild;
  BinaryNode *parent;
  friend class MyTree;
};


class MyTree {
public:
  MyTree();
  ~MyTree();

  // Insert new node into first available position (to keep the tree almost complete).
  void insert (int x ,string s);

  //Output all strings in pre-order
  //all the strings will be print in one line separated by spaces
  void preorder() const;

  //Returns a pointer to the node with maximum myInt
  BinaryNode *findMax() const;

  // Converts the binary tree into a binary search tree (BST) with respect to myInt.
  // That is, move around node values (myString and myInt) to satisfy the BST property.
  void makeBST();

private:
  BinaryNode *root;
  BinaryNode *nextLeaf;

  //helper functions
  BinaryNode* max(BinaryNode *curr, BinaryNode* largestNode) const;

  void createVector(BinaryNode *curr, vector<nodePair>& myVector);

  void treeToBST(BinaryNode* curr, vector<nodePair> myVector, int,int);

  void deleteTree(BinaryNode* curr);

  void PrintPreOrder(BinaryNode* currPtr) const;

};
