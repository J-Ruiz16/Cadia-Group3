/**
 * @file deque.h
 * @author Jocelyn Ruiz
 * @date 2025-04-24
 * @brief deque template class definition and implementation
 * 
 *building a deque template class for adding and removing from front and back, check if deque is empty, and returning the size of deque
 * 
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

/**
 * template deque class with private members blockmap, blocksize, 
 *capacity, front block, front position, back block, back position, and totalSize
 *methods push front and back, pop front and back, front, back, empty
 *size, operator[], constructor, destructor
 *
 * @class <typename deque.h "cadia_group3/deque.h"
 * @brief deque template class
 *
 */
template <typename T> class Deque{
 private:
  T** blockmap;
  int blockSize;
  int capacity;
  int frontB, frontPosition;
  int backB, backPosition;
  int totalSize;

 public:

/**
 * class constructer, initializes an empty deque 
 * 
 */
  Deque();

/**
 * class destructor, deletes both dimensions of the deque
 * 
 */
  ~Deque();

/**
 * add from the front, reallocating as necessary by either adding an array to your blockmap or resizing your blockmap.
 * @param const T& value
 * @return void return nothing 
 * 
 */
  void push_front(const T& value);

/**
 * remove from the front, reallocating as necessary by either adding an array to your blockmap or resizing your blockmap
 *
 * @return void return nothing 
 * 
 */
  void pop_front();

/**
 * add from the back
 * @param const T* value
 * @return void return nothing 
 * 
 */
  void push_back(const T& value);

/**
 * remove from the back
 *
 * @return void return nothing 
 * 
 */
  void pop_back();

/**
 * return a copy of the item at the particular location
 *
 * @return T  
 * 
 */
  T front();

/**
 * return a copy of the item at the particular location
 *
 * @return T  
 * 
 */
  T back();

/**
 * should return a boolean describing whether the deque is empty
 *
 * @return bool true or false 
 * 
 */
  bool empty();

/**
 * should return the size of the deque(number of elements currently stored)
 *
 * @return int size of the deque 
 * 
 */
  int size();


/**
 * overloaded operator []
 *
 * @param int index 
 * @return T&  
 * 
 */
  T& operator[](int index);
  
};
#endif //DEQUE_H

template <typename T> Deque<T>::Deque(){
  blockSize = 60;
  capacity = 8;
  totalSize= 0;

  blockmap = new T*[capacity];
  for (int i = 0; i < capacity; i++)
    blockmap[i] = NULL;
  //start at the beginning
  frontB = backB = 0;
  frontPosition = backPosition = blockSize/2;//gives space on both sides of block
  
}


template <typename T> Deque<T>::~Deque(){
  //this deletes each block
  for (int i = 0; i < capacity; i++)
    delete[] blockmap[i];

  delete[] blockmap;//deletes the blockmap
}
template <typename T> void Deque<T>::pop_front(){
  if (totalSize == 0){//if deque empty
    return;
  }
  //if they are same only one element left
  if(frontB == backB and frontPosition == backPosition){
    frontB = backB = 0;
    frontPosition = backPosition = blockSize/2;//center of block
  }
  else if (frontPosition == blockSize - 1){//if end of block
    frontB++;//moves to the next block
    frontPosition = 0;
  }
  
  totalSize--;
}
  
template <typename T> void Deque<T>::pop_back(){
  if (totalSize == 0){//if deque empty
    return;
  }
  if(frontB == backB and frontPosition == backPosition){
    frontB = backB = 0;
    frontPosition = backPosition = blockSize/2;
  }
  else if (backPosition == 0){//if at start of block
    backB--;//move to previous block
    backPosition = blockSize - 1;//end of previous block
  }
  totalSize--;
}

template <typename T> T Deque<T>::front(){
  return blockmap[frontB][frontPosition];
}

template <typename T> T Deque<T>::back(){
  return blockmap[backB][backPosition];
}

template <typename T> bool Deque<T>::empty(){
  if (totalSize == 0) {
    return true;
  }
  else
    return false;
}

template <typename T> int Deque<T>::size(){
  return totalSize;
}
