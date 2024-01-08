#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"
#include <vector>

String MakePostfix(String& expr){
  //if(expr == "") exit(1);
  stack<String> result;
  String space(" ");

  String temp(expr);
  std::cout << "Infix expression: " << temp << std::endl;

  std::vector<String> part = temp.split(' ');
  String right, left, oper;

  size_t i = 0;
  while(i < part.size() && part[i] != ';'){
    if (part[i] == ')'){
      right = result.pop();
      oper = result.pop();
      left = result.pop();
      result.push(left + right + oper);
    }
    else {
      if (part[i] != '(')
	result.push(part[i] + space);
    }
    ++i;
  }
  temp = result.top();
  std::cout << "Postfix Expression: " << temp << std::endl;
  return temp;
}

void MakeAssembly(String& post){
  std::vector<String> token = post.split(' ');
  stack<String> result;
  String right, left;
  size_t i = 0;
  
  while(i < token.size()){
    String t = token[i];
    if (t != "+" && t != "-" &&
	t != "*" && t != "/"){
      result.push(t);
    }
    else{
      right = result.pop();
      left = result.pop();
      result.push(evaluate(left, t, right));
    }
    ++i;
  }
}  
String evaluate(String left, String t, String right){
  String space1("   ");
  String space2("     ");

  std::vector<String> TMP;
  
  for(size_t i = 0; i < TMP.size(); ++i){
    if(left == TMP[i]){
      String temp("TMP");
      //temp += (char(index + 1));
      left = temp;
    }
    if(right == TMP[i]){
      String temp("TMP");
      //temp += (char(index + 1));
      right = temp;
    }
    //    ++index;
  }

  char oper = t[0];
  std::cout << space1 << "LD" << space2 << left << std::endl;
  switch(oper){
  case '+':
    std::cout << space1 << "AD" << space2 << right << std::endl;
    break;
  case '-':
    std::cout << space1 << "SB" << space2 << right << std::endl;
    break;
  case '*':
    std::cout << space1 << "MU" << space2 << right << std::endl;
    break;
  case '/':
    std::cout << space1 << "DV" << space2 << right << std::endl;
    break;
  }

  String full;
  if(TMP.size() == 0){
    TMP.push_back(left + t + right);
    //stores expression into temp
  }
  full = left + t + right;
  //index = 0;
  for(size_t i = 0; i < TMP.size(); ++i){
    if(full == TMP[i]){
      String temp("TMP");
      full = temp;
      //  ++index;
    }
    if(full != TMP[i] && i == (TMP.size()-1)){
      TMP.push_back(full);
      //++index;
    }
    //++index;
  }
  
  std::cout << space1 << "ST" << space2 << full << std::endl;
  return full;
}
   
