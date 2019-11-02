#include <iostream>
#include "MyTree.h"
#include "BinaryNode.h"
using namespace std;

int main(){
  char userChar = ' ';
  MyTree userTree;

  while(userChar != 'q'){
    cout << "Enter a to add node to tree" << endl
         << "Enter p to print in PreOrder" << endl
         << "Enter f to find the max value" << endl
         << "Enter c to convert Binary Tree to BST" << endl
         << "Enter q to quit" << endl;
    cin >> userChar;
    cout << endl;

    if(userChar == 'a'){
      int userInt = 0;
      string userString;
      cout << "INSERT" << endl;
      cout << "Enter new node's int data: ";
      cin >> userInt;
      cout << "Enter new node's string data: ";
      cin >> userString;

      userTree.Insert(userInt,userString);
      cout << "Inserted..." << endl;
    }

    else if(userChar == 'p'){
      cout << "PREORDER" << endl;
      userTree.PreOrder();
    }

    else if(userChar == 'f'){
      cout << "FIXME" << endl;
    }
    else if(userChar == 'c'){
      cout << "FIXME" << endl;
    }
    else if(userChar != 'q'){
      cout << "Invald command." << endl;
    }
    cout << endl;
  }

  return 0;
}
