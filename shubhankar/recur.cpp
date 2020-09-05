#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
// #include <filesystem>
using namespace std;
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

// void ParseLine(string line) {
//     istringstream sline(line);
//     string type;
//     string func_name;
//     while (sline >> type >> func_name) {
//       if(func_name.find("(")!=string::npos){
//         string funct = func_name.substr(0,func_name.find("("));
//         if(funct.compare(""))
//           functions.push(funct);
//       }
//     }
// }
int iter_count = 0;

void ReadBoardFile_itr(string path) {
  ifstream myfile (path);
  //ofstream outfile ("iter.txt");
  bool flag = false;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
        if(line.find("while")!=string::npos || line.find("for")!=string::npos){
           // outfile << line;
            iter_count++;
        }
    }
  }
}
void ReadBoardFile(string path) {
  ifstream myfile (path);
 // ofstream outfile ("check.txt");
  bool flag = false;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
    	int ch=0;
    	if(line.length()==0)
    		continue;
    	if(ch==line.size())
    		continue;
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
        	//cout << "check";
          parseFunction(line);
        }else{
          check(line);
        }
       // outfile << line;
    }
  }
}

// void PrintBoard(const vector<vector<int>> board) {
//   for (int i = 0; i < board.size(); i++) {
//     for (int j = 0; j < board[i].size(); j++) {
//       cout << board[i][j];
//     }
//     cout << "\n";
//   }
// }

int main(int argc, char** argv) {
  // string path = "./";
  // for (const auto & entry : fs::directory_iterator(path))
  //   cout << entry.path() << endl;
  // cout << "file entered for detection -> " << argv[1] << endl;
	//cout << "check";
  ReadBoardFile(argv[1]);
  ReadBoardFile_itr(argv[1]);
  cout << recur_count << endl;
  cout << iter_count <<endl;
//   PrintBoard(board);
}

void check(string line){
  if(!functions.empty() && line.find(functions.top())!=string::npos){
    recur_count++;
    // cout << "recursion at " << functions.top() << endl;
    //cout << recur_count << endl;
    functions.pop();
  }
}

void parseFunction(string line) {
    istringstream sline(line);
    string type;
    string func_name;
    while (sline >> type >> func_name) {
    	//cout << func_name <<endl;
      if(func_name.find("(")!=string::npos){
        string funct = func_name.substr(0,func_name.find("("));
        if(funct.compare(""))
          functions.push(funct);
      }
    }
}