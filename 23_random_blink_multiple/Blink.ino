

#define MAX_BLINK_AMOUNT 4

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

    Blink** current = &_head;

    while (*current != nullptr && *current != b) {
        current = &(*current)->next;
    }

    if (*current == nullptr) {
        Serial.println("Node not found in the linked list.");
        return;
    }

    Blink* toRemove = *current;
    *current = (*current)->next;
    delete toRemove;
    _length--;
    // Serial.println("Element removed");

    

    //Blink* toRemove = b;

    // if(b == _head){
    //   Serial.println("removing head");
    //   _head = b->next;
    //   delete toRemove;
    //   _length--;
    //   return;
    // }

    // if(b->next){
    //   b = b->next;
    //   delete toRemove;
    //   _length--;
    //   return;
    // }

    // Blink* toRemove = b;

    // Blink* prev = nullptr;
    // Blink* current = _head;

    // while(current != nullptr && current != b){
    //   prev = current;
    //   current = current->next;
    // }

    // if(prev != nullptr){
    //     prev->next = current->next;
    // } 
    // else{
    //     _head = current->next;
    // }

    // delete toRemove;
    // _length--;

  }

  int LinkedList::getLength(){
    return this->_length;
  }

  Blink* LinkedList::getHead(){
    return this->_head;
  }