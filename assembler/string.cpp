// function implementations
// Kaila Anderson
// CS23001 Project 2

#include<iostream>
#include<fstream>
#include <vector>
#include "string.hpp"
#include <string>

String::String(){
  stringSize = 1;
  str = new char[stringSize];
  str[0] = 0;
}

String::String(char ch){
  if (ch == '\0'){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
  }
  else {
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = 0;
  }
     
}

String::String(const char ch[]){
  int len = 0;
  while (ch[len] != 0) ++len;

  stringSize = len + 1;
  str = new char[stringSize];
  
  for (int i = 0; i < stringSize; ++i)
    str[i] = ch[i];
  str[len] = 0;
}

//copy constructor
String::String(const String& actual){
  stringSize = actual.stringSize;
  str = new char[stringSize];
  for(int i = 0; i < stringSize; ++i)
    str[i] = actual.str[i];
}

//Destructor
String::~String(){
  delete[] str;
}

//Time swap
void String::swap(String& rhs){
  char *temp = str;
  str = rhs.str;
  rhs.str = temp;
  char sizeTemp = stringSize;
  stringSize = rhs.stringSize;
  rhs.stringSize = sizeTemp;
}

//Assignment copy
String& String:: operator=(String rhs) {
  if (str == rhs.str) return *this;
  delete[] str;
  stringSize = rhs.stringSize;
  str = new char[stringSize];
  for(int i = 0; i < stringSize; ++i)
    str[i] = rhs.str[i];
  return *this;
}

int String::capacity() const {
  return stringSize - 1;
}

int String::length() const{
  return capacity();
}

char& String::operator[](int index){
  if (index < 0 || index >= stringSize){
    std::cout << "index is out of range";
    return str[0];
  }
  else
    return str[index];
}

char String::operator[](int index) const {
  if(index < 0 || index >= stringSize){
    std::cout << "index is out of range";
    return str[0];
  }
  else
    return str[index];
}

String& String::operator+= (const String& rhs){
  int length = this->length();
  int rhsLength = rhs.length();
  
  String temp = str;
  delete[] str;
  stringSize = length + rhsLength + 1;
  str = new char[stringSize];

  for(int i = 0; i < length; ++i)
    str[i] = temp[i];
  for(int i = 0; i < rhsLength; ++i){
    str[(i + length)] = rhs.str[i];
  }

  str[(stringSize-1)] = 0;
  return *this;
}

bool String::operator== (const String& rhs) const{
  int length = this->length();
  int rhsLength = rhs.length();

  if(length != rhsLength) return false;
  for (int i = 0; i < length; ++i){
    if (str[i] != rhs.str[i]) return false;
  }
  return true;
}

bool String::operator< (const String& rhs) const{
  int i = 0;
  while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))
    ++i;
  return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const{
  String result;
  
  if (start < 0) start = 0;
  if (end < start) return result;
  if (end >= length()) end = length() - 1;
  
    for (int i = start; i <= end; ++i){
      result += str[i];
    }
  return result;
}

int String::findch (int start, char ch) const{
  if (start < 0) start = 0;
  if (start >= length()) return -1;

  int i = start;
  while ((str[i] != 0) && (str[i] !=ch)) ++i;
  if (str[i] == ch)
    return i;
  else
    return -1;
}


int String::findstr (int start, const String& chArray) const{
  if (start < 0) start = 0;
  if (start >= length()) return -1;
  int location = start;

  while (chArray.length() + location <= length()){
    String temp = substr(location, location + chArray.length() - 1);
    if (chArray == temp)
      return location;
    else
      ++location;
  }
  return -1;
}

std::vector<String> String::split(char ch) const {
  std::vector<String> strVector;
  int start = 0, end;
  String sub;

  while(start < stringSize){
    end = this->findch(start, ch);
    if (end == -1)
      end = this->length();
    sub = substr(start, end - 1);
    strVector.push_back(sub);
    if(end != this->length())
      start = end + 1;
    else
      start = stringSize;
  }
  return strVector;  
}

std::istream& operator>>(std::istream& input, String& object){
  char ch[200];
  input.get(ch, 50);
  String temp(ch);
  object = temp;
  //std::cout << "testing input operator: " << object << std::endl;

  /*
  input >> ch;
  while (ch != ';'){
    temp += ch;
    input >> ch;
    }
    object = temp;*/
  /*do {
    input >> ch;
    object += ch;
    } while (!input.eof());*/
  //input.getline(object.str, '\n');
  //std::cout << "object is: " << object << std::endl;
  
  return input;
}

std::ostream& operator<<(std::ostream& out, const String& object){
  for(int i = 0; i < object.length(); ++i){
    out << object.str[i];
  }
  return out;
} 
      
// free functions

String operator+ (String first, const String& second){
  String result = first;
  result += second;
  return result;
}

bool operator==(const char ch[], const String& object){
  String chArray(ch);
  return chArray == object;
}

bool operator==(char ch, const String& object){
  String character(ch);
  return character == object;
}

bool operator< (const char ch[], const String& object){
  String chArray(ch);
  return chArray < object;
}

bool operator< (char ch, const String& object){
  String character(ch);
  return character < object;
}

bool operator <= (const String& one, const String& two){
  if (one == two)
    return true;
  else if (one < two)
    return true;
  else
    return false;
}

bool operator!= (const String& one, const String& two){
  if (one == two)
    return false;
  return true;
}

bool operator >= (const String& one, const String& two){
  if (one == two)
    return true;
  else if (one < two)
    return false;
  else
    return true;
}

bool operator > (const String& one, const String& two){
  if (one < two)
    return false;
  return true;
}
