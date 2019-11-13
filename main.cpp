#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;
using namespace std::chrono;
#include "MyTree.h"

string randstring();

int main(){
  char userChar = ' ';
  MyTree userTree;

  while(userChar != 'q'){
    cout << "Enter a to add node to tree" << endl
         << "Enter p to print in PreOrder" << endl
         << "Enter f to find the max value" << endl
         << "Enter c to convert Binary Tree to BST" << endl
         << "Enter t to test and measure performance" << endl
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

      userTree.insert(userInt,userString);
      cout << "Inserted..." << endl;
    }

    else if(userChar == 'p'){
      cout << "PREORDER" << endl;
      userTree.preorder();
      cout << endl;
    }

    else if(userChar == 'f'){
      cout << "FIND MAX" << endl;

      int val = (userTree.findMax())->getInt();

      cout << "Max Value: " << val << endl;
    }
    else if(userChar == 'c'){
      cout << "BST" << endl;

      userTree.makeBST();
    }
    else if(userChar == 't'){
      cout << "MEASURE PERFORMACE" << endl;

      double compTimes[4][4] = {0};
      MyTree testTree;
      int new_size = 100;

      // test 4 sizes (100, 1000, 10000, 100000)
      for(unsigned k = 0; k < 4; ++k){

        // populate curr
        nodePair *curr = new nodePair[new_size];
        for(unsigned j = 0; j < new_size; ++j){
          nodePair a;
          a.first = rand();
          a.second = randstring();
          curr[j] = a;
        }

        duration<double> runTime;
        for(unsigned i = 0; i < 4; ++i){
          auto start = high_resolution_clock::now();

          if(i == 0){
            for(unsigned j = 0; j < new_size; ++j){
              testTree.insert(curr[j].first, curr[j].second);
            }
          }
          else if(i == 1){
            testTree.preorder();
          }
          else if(i == 2){
            testTree.findMax();
          }
          else{
            testTree.makeBST();
          }
          auto finish = high_resolution_clock::now();
          compTimes[k][i] += duration_cast<microseconds>(finish - start).count();
        }
        new_size *= 10;
      }

      cout << endl << "RESULTS: (µs)" << endl << endl;
      cout << "Sizes         ||  100 ||  1000  || 10000  ||  100000  ||" << endl;
      for(unsigned i = 0; i < 4; ++i){
        if(i == 0){
          cout << "insert(*,*)   ||  ";
        }
        else if(i == 1){
          cout << "preorder()    ||  ";
        }
        else if(i == 2){
          cout << "findMax()     ||  ";
        }
        else{
          cout << "makeBST()     ||  ";
        }
        for(unsigned j = 0; j < 4; ++j){
          cout << compTimes[j][i] << "  ||  " ;
        }
        cout << endl;
      }

    }
    else if(userChar != 'q'){
      cout << "Invald command." << endl;
    }
    cout << endl;
  }

  return 0;
}

string randstring(){
  string a;
  // All strings will have length 10
  for(unsigned i = 0; i < 10; ++i){
    char b = 97 + (rand() % 26);
    a += b;
  }
  return a;
}
