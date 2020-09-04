#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
// #include <filesystem>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::vector;
using std::stack;
using std::endl;
// namespace fs = std::filesystem;


stack<string> functions;
int recur_count = 0;

void check(string line);
void parseFunction(string line);

void ParseLine(string line) {
    istringstream sline(line);
    string type;
    string func_name;
    while (sline >> type >> func_name) {
      if(func_name.find("(")!=string::npos){
        string funct = func_name.substr(0,func_name.find("("));
        if(funct.compare(""))
          functions.push(funct);
      }
    }
}

void ReadBoardFile(string path) {
  ifstream myfile (path);
  ofstream outfile ("check.txt");
  bool flag = false;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
        if (line.at(0)=='#'){
          continue;
        }
        else if (line.at(0)=='/' && line.at(1)=='/'){
          continue;
        }
        else if (line.at(0)=='/' && line.at(1)=='*'){
          flag = true;
          continue;
        }
        else if (line.find("*/")!=string::npos){
          flag = false;
          continue;
        }
        else if(line.find("using")!=string::npos){
          continue;
        }
        else if(!flag && line.find(";")==string::npos){
          parseFunction(line);
        }else{
          check(line);
        }
        outfile << line;
    }
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main(int argc, char** argv) {
  // string path = "./";
  // for (const auto & entry : fs::directory_iterator(path))
  //   cout << entry.path() << endl;
  // cout << "file entered for detection -> " << argv[1] << endl;
  ReadBoardFile(argv[1]);
//   PrintBoard(board);
}

void check(string line){
  if(!functions.empty() && line.find(functions.top())!=string::npos){
    recur_count++;
    // cout << "recursion at " << functions.top() << endl;
    cout << recur_count << "\n";
    functions.pop();
  }
}

void parseFunction(string line) {
    istringstream sline(line);
    string type;
    string func_name;
    while (sline >> type >> func_name) {
      if(func_name.find("(")!=string::npos){
        string funct = func_name.substr(0,func_name.find("("));
        if(funct.compare(""))
          functions.push(funct);
      }
    }
}