#ifndef __BINARYNODE_H__
#define __BINARYNODE_H__
using namespace std;

struct BinaryNode{
  int dataInt;
  string dataString;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode *parent;
  BinaryNode():dataInt(-1),dataString("Null"),left(nullptr),right(nullptr),parent(nullptr) {};

  BinaryNode(int dataInt,string dataString):
  dataInt(dataInt),dataString(dataString),left(nullptr),right(nullptr),parent(nullptr) {};
};

#endif
