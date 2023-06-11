#pragma once

struct Blink{
  Blink(int pos, int size, float speed){
    this->position = pos;
    this->size = size;
    this->speed = speed;
  }
  int position;
  int size;
  float animation = 0;
  float speed = 0;
  Blink* next = nullptr;
  Blink* prev = nullptr;
};

class LinkedList{
  public:
  LinkedList();
  ~LinkedList();
  void insert(Blink* b);
  void remove(Blink* b);
  Blink* getHead();
  int getLength();
  bool isFull();
  private:
  Blink* _head = nullptr;
  int _length = 0;
};