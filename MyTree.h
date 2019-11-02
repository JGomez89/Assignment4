#ifndef __MYTREE_H__
#define __MYTREE_H__
#include <iostream>
#include "BinaryNode.h"
using namespace std;

class MyTree{
private:
  BinaryNode DummyLeaf;
  BinaryNode *root;
  BinaryNode *nextLeaf;
  int height; // Including root
  void PrintPreOrder(BinaryNode*,int);

public:
  MyTree(){
    height = 0;
    root = nullptr;
    nextLeaf = &DummyLeaf;
  };
  void Insert(int,string);
  void PreOrder();
  // BinaryNode FindMax();
  // BinaryNode MakeBST();
};



//   // If empty
//   if(root == nullptr){
//     root = newNode;
//     root->left = nextLeaf;
//     nextLeaf->parent = root;
//   }
//   // If not empty
//   else{
//     // If nextLeaf BinaryNode is a left child, then parent's right child becomes nextLeaf BinaryNode
//     if(nextLeaf->parent->left == nextLeaf){
//       nextLeaf->parent->left = newNode;
//       newNode->parent = nextLeaf->parent;
//       // Update nextLeaf BinaryNode's location in tree
//       nextLeaf->parent->right = nextLeaf;
//     }
//     // If nextLeaf BinaryNode is a right child
//     else{
//       bool isPlaced = false;
//       newNode->parent = nextLeaf->parent;
//       nextLeaf->parent->right = newNode;
//       // Update nextLeaf BinaryNode's location in tree
//       // Climb tree until curr BinaryNode is a left child (or hit the root)
//       for(BinaryNode* curr = nextLeaf; (curr != root) && !isPlaced; curr = curr->parent){
//         // If curr is a left child, then parent's right child's left child becomes nextLeaf BinaryNode
//         if(curr->parent->left == curr){
//           nextLeaf->parent = curr->parent->right;
//           nextLeaf->parent->left = nextLeaf;
//           isPlaced = true;
//         }
//       }
//       // If curr BinaryNode reaches root (if nextLeaf BinaryNode was at the very right of tree)
//       if(!isPlaced){
//         // Travel down very left of tree until a leaf BinaryNode is reached
//         for(BinaryNode* curr = root->left; curr != nullptr; curr = curr->left){
//           if(curr->left == nullptr){
//             nextLeaf->parent = curr;
//             nextLeaf->parent->left = nextLeaf;
//           }
//         }
//       }
//     }
//   }
//   ++height;
// }



#endif
