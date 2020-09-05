#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::vector;
using std::stack;
using std::endl;

//stack<string> functions;
bool iter_count = false;

void ReadBoardFile(string path) {
  ifstream myfile (path);
  ofstream outfile ("iter.txt");
  bool flag = false;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
        if(line.find("while")!=string::npos || line.find("for")!=string::npos){
            outfile << line;
            iter_count=true;
        }
    }
  }
}

int main(int argc, char** argv) {
  // cout << "file entered for detection -> " << argv[1] << endl;
  ReadBoardFile(argv[1]);
  if(iter_count){
    cout<<"true";
  }else{
    cout<<"false";
  }
}
