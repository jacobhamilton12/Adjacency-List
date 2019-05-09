//Jacob Hamilton, jake7054, 509, jacobhamilton@tamu.edu

#include <iostream>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <fstream>
#include <stack>

using namespace std;


class AdjacencyMat{
private:
  vector<list<int>> matrix;
  stack<int> path;

public:
  void insert(int num1, int num2);
  vector<list<int>> get(){return matrix;}
  void search();
  bool searchHelp(list<int> u);
  void printPath();
  bool isEmpty(list<int> u);
};

ostream& operator<<(ostream& out, AdjacencyMat& mat);
istream& operator>>(istream& in, AdjacencyMat& mat);