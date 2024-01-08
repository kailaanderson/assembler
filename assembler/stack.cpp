//stack ADT function implementation
//
// Kaila Anderson

#include "stack.hpp"
#include<iostream>
#include<new>
#include <cassert>
#include "./string/string.hpp"

//==========================================================

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack<T>(){
  Node<T>* temp = actual.tos;
  Node<T>* bottom;

  while(temp != 0){
    if (tos == 0){
      tos = new Node<T>(temp->data);
      bottom = tos;
    }
    else{
      bottom->next = new Node<T>(temp->data);
      bottom = bottom->next;
    }
    temp = temp->next;
  }
}

template <typename T>
stack<T>::~stack(){
  Node<T>* temp = 0;
  while(tos != 0){
    temp = tos;
    tos = tos->next;
    delete temp;
  }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs){
  Node<T>* temp = tos;
  tos = rhs.tos;
  rhs.tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator= (stack<T> rhs){
  swap(rhs);
  return *this;
}

template <typename T>
bool stack<T>::empty() const {
  return tos == 0;
}

template <typename T>
bool stack<T>::full() const {
  Node<T>* temp = new(std::nothrow) Node<T>();
  if(temp == 0) return true;
  delete temp;
  return false;
}

template <typename T>
T stack<T>::top() const{
  assert(!empty());
  return tos->data;
}

template <typename T>
T stack<T>::pop(){
  assert(!empty());
  T result = tos->data;
  Node<T>* temp = tos;
  tos = tos->next;
  delete temp;
  return result;
}

template <typename T>
void stack<T>::push(const T& item){
  assert(!full());
      Node<T>* temp = new Node<T>(item);
      temp->next = tos;
      tos = temp;
 }
  
