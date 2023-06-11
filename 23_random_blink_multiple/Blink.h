#pragma once

struct Blink{
  Blink(int pos, int size){
    this->position = pos;
    this->size = size;
  }
  int position;
  int size;
  float animation = 0;
  bool isPending = true;
  Blink* next = nullptr;
};

class LinkedList{
  public:
  LinkedList();
  void insert(Blink* b);
  void remove(Blink* b);
  Blink* getHead();
  int getLength();
  private:
  Blink* _head = nullptr;
  int _length = 0;
};