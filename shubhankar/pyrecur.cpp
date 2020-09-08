#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::vector;
using std::stack;
using std::endl;
using namespace std;

stack<string> functions;
stack<int> functind;
bool recur_count = false;

void check(string line);
void parseFunction(string line);
int ind=0;
void ReadBoardFile(string path) {

  ifstream myfile (path);
 // ofstream outfile ("check.txt");
  bool flag = false;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      if(recur_count==true)
        break;
    	ind=0;
      if(line.size()>0)
      {
        for(int i=0;i<line.size();i++)
        {
          if(line[i]==' ')
            ind++;
          else
            break;
        }
      }
    
    	if(line.size()==0)
    		continue;
        if (line.find("import")!=string::npos){
          continue;
        }
        else if(line.find(":")!=string::npos){
        	//cout << "check";
          parseFunction(line);
        }else{
          check(line);
        }
       // outfile << line;
    }
  }
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

int main(int argc, char** argv) {
  ReadBoardFile(argv[1]);
  if(recur_count){
    cout<<"true";
  }else{
    cout<<"false";
  }
}

void check(string line){
  int k = functind.top();
  if(!functions.empty() && line.find(functions.top())!=string::npos && k<ind){
    recur_count= true;
    functions.pop();
    functind.pop();
  }
}

void parseFunction(string line) {
    istringstream sline(line);
    string type;
    string func_name;
    while (sline >> type >> func_name) {
    	//cout << func_name <<endl;
      trim(func_name);
      trim(type);
      //cout << func_name<<endl;
      if(type=="def")
      {
        if(func_name.find("(")!=string::npos){
        string funct = func_name.substr(0,func_name.find("("));
       // cout << funct<<endl;
        functions.push(funct);
            functind.push(ind);
          
      }
      }
      
    }
}