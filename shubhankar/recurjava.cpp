
#include <fstream>
#include <bits/stdc++.h>
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


stack<string> functions;
bool recur_count=false;
void check(string line);
void parseFunction(string line);
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
        else if(line.find("import")!=string::npos){
        	//cout << "check1"<<endl;
          continue;
        }
        else if(line.find("class")!=string::npos){
        	//cout << "check2"<<endl;
          continue;
        }
        else if(!flag && line.find(";")==string::npos){
        	//cout << "check3"<<endl;
        	//cout << "check";
          parseFunction(line);
         }else{
          check(line);
         }
       // outfile << line;
    }
  }
}
int main(int argc, char** argv) {
  ReadBoardFile(argv[1]);
  if(recur_count){
    cout<<"true";
  }else{
    cout<<"false";
  }
//   PrintBoard(board);
}
std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}
void check(string line){
  if(!functions.empty() && line.find(functions.top())!=string::npos){
    recur_count= true;
    // cout << "recursion at " << functions.top() << endl;
    //cout << recur_count << endl;
    functions.pop();
  }
}
void parseFunction(string line) {
	std::stringstream ss(line);
	char delim = ' ';
    std::string token;
    vector<string> cont;
    while (std::getline(ss, token, delim)) {
    	if(token.size()>0)
    	{
    		trim(token);
    		cont.push_back(token);
    	}
        
    }
    int l = cont.size();
    if(l>1)
    {
    	for(int i=0;i<l;i++)
    	{
    		if(cont[i] == "int" || cont[i] == "void" || cont[i] == "float" || cont[i] == "double" || cont[i] == "char" || cont[i] == "bool" || cont[i] == "string" || cont[i].find("*")!=string::npos)
    		{
    			if(cont[i+1].find("(")!=string::npos){
        	string funct = cont[i+1].substr(0,cont[i+1].find("("));
        	if(funct.compare(""))
          	functions.push(funct);
          	break;
    		}
    	}
    }	
    }
}