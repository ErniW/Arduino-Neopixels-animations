LinkedList::LinkedList(){

};

LinkedList::~LinkedList(){
  Blink* current = _head;

  while(current){
    remove(current);
  }
};

void LinkedList::insert(Blink* b) {

  if (_length == MAX_BLINK_AMOUNT) return;

  _length++;

  if (!_head) {
    _head = b;
    return;
  }

  Blink* temp = _head;
  _head = b;
  b->next = temp;
  temp->prev = _head;
}

void LinkedList::remove(Blink* b) {

  if(b == _head){
    _head = b->next;
    if(_head){
      _head->prev = nullptr;
    }
  }
  else{
    if(b->next != nullptr){
      b->prev->next = b->next;
      b->next->prev = b->prev;
    }
    else{
      b->prev->next = nullptr;
    }
  }

  delete b;
  _length--;
}

int LinkedList::getLength() {
  return this->_length;
}

bool LinkedList::isFull() {
  return _length >= MAX_BLINK_AMOUNT;
}

Blink* LinkedList::getHead() {
  return this->_head;
}