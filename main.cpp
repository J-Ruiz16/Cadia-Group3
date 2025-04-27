/**
 * @file main.cpp
 * @author Jocelyn Ruiz
 * @date 2025-04-24
 * @brief driver testing program
 * 
 * driver to test program implemention of the deque template class
 * 
 */

#include "deque.h"
#include <iostream>
#include <string>

int main() {
  Deque<int> deque;

  deque.push_front(2000);
  deque.push_front(1000);
  deque.push_front(500);

  deque.push_back(3500);
  deque.push_back(2500);
  deque.push_back(500);

  std::cout << "Front was: " << deque.front() << std::endl; 
  std::cout << "Back was: " << deque.back() << std::endl;   
  std::cout << "Size was: " << deque.size() << std::endl;   

  std::cout << "Elements: " << std::endl;
  for (int i = 0; i < deque.size(); i++) {
      std::cout << deque[i] << " ";
  }
  std::cout << std::endl;

  deque.pop_front();
  deque.pop_back();

  std::cout << "After popping:" << std::endl;
  std::cout << "Front is: " << deque.front() << std::endl;
  std::cout << "Back is: " << deque.back() << std::endl;

  return 0;
}
