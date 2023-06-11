

// #define MAX_BLINK_AMOUNT 4

  LinkedList::LinkedList(){

  };
  
  void LinkedList::insert(Blink* b){

    if(_length == MAX_BLINK_AMOUNT) return;

    _length++;

    //Serial.println(b->position);

    if(!_head){
      _head = b;
      return;
    }

    Blink* temp = _head;
    _head = b;
    b->next = temp;
  }

  void LinkedList::remove(Blink* b){

    if(b == _head){
      _head = b->next;
      delete b;
    }
    else{
      Blink* current = _head;

      while (current->next != nullptr) {
        
        if(current->next == b) break;

        current = current->next;
      }

      Blink* toRemove = current->next;
      current->next = toRemove->next;
      delete toRemove;

    }

    _length--;

  }

  int LinkedList::getLength(){
    return this->_length;
  }

  Blink* LinkedList::getHead(){
    return this->_head;
  }