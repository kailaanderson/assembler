#include <iostream>
#include "utilities.hpp"
#include <fstream>
#include "string.hpp"
#include "stack.hpp"
#include <vector>

int main(int argc, char* argv[]){
  // std::cout << "In postfix main" << std::endl;
  //Options
  std::vector<String> option(3);
  option[0] = "postfix";
  option[1] = "file";
  option[2] = "outfile (optional)";

  if(argc < 2) {
    std::cerr << "Error" << std::endl;
    std::cerr << "Useage: " << argv[0] << " [ "
	      << option[0] << " | "
	      << option[1] << " | "
	      << option[2] << " | optional " << std::endl;
    exit(1);
  }

  std::ifstream file(argv[1]);
  if(!file){
    std::cerr << "Error: cannot open " << argv[1] << std::endl;
    exit(2);
  }

  std::ofstream out(argv[2]);

  char chArr[100];
  while(!file.eof()){
    char ch = file.get();
    if(file.eof()) break;
    for(int i = 0; ch != '\n'; ++i){
      if(ch == '\r'){
	ch = file.get();
	continue;
      }
      chArr[i] = ch;
      ch = file.get();
      if(file.eof()) break;
      chArr[i+1] = 0;
    }
    String expr(chArr);

    String post = MakePostfix(expr);
  }
}

  /*  String result;

  do{
     char ch[200];
  file.get(ch, 50);
  String temp(ch);
  result = temp;

    //String result;
    file >> result;
    MakePostfix(result);
    ++newLine;
    //std::cout << "Postfix Expression: " << std::endl;
  } while (newLine < 10);//while (!file.eof());
}*/
  /*  while(file.get()){
    std::cout << "Infix Expression: " << result << std::endl;
    result = MakePostfix(file);
    std::cout << "Postfix Expression: " << result << std::endl;
  }
  return 0;
  } */
/*
int main(){
  std::ifstream file("data3-1.txt");
  if (!file){
    std::cout << "file failed to open" << std::endl;
    return 1;
  }
  while (!file.eof()){
    stack<String> post = MakePostfix<String>(file);
    std::cout << post.top() << std::endl;
  }
  }*/



