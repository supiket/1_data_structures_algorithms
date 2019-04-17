#include "LinkedList.h"

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::LinkedList(const LinkedList& list){
    this->length = list.length;
    this->head = new Node(*list.head);
    Node* thisCurrent = this->head;
    Node* listCurrent = list.head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node(*(listCurrent->next));
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->tail = new Node(*listCurrent);
}

LinkedList& LinkedList::operator=(const LinkedList& list){
    this->length = list.length;
    this->head = new Node(*(list.head));
    Node *thisCurrent = this->head;
    Node *listCurrent = list.head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node(*(listCurrent->next));
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->tail = new Node(*listCurrent);
    return *this;

}

LinkedList::LinkedList(LinkedList&& list){
    this->length = move(list.length);
    this->head = move(list.head);
    Node *thisCurrent = this->head;
    Node *listCurrent = list.head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node(*move(listCurrent->next));
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->tail = new Node(*move(listCurrent));
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
}

LinkedList& LinkedList::operator=(LinkedList&& list){
    this->length = move(list.length);
    this->head = move(list.head);
    Node *thisCurrent = this->head;
    Node *listCurrent = list.head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node(*move(listCurrent->next));
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->tail = new Node(*move(listCurrent));
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return *this;
}

void LinkedList::pushTail(string _name, float _amount){
    Node *newTail = new Node(_name, _amount);
    if(this->head) {
        this->tail->next = newTail;
        this->tail = newTail;
        this->length++;
    }
    else {
        this->head = newTail;
        this->tail = newTail;
    }
}

void LinkedList::updateNode(string _name, float _amount){
    Node *iterator = this->head;
    for(;;){
        if(iterator->name == _name){
            iterator->amount = 0;
            iterator->amount = _amount;
            break;
        }
        iterator = iterator->next;
    }
}

LinkedList::~LinkedList(){
    Node* current = this->head;
    while(current != NULL){
        Node* next = current->next;
        current = NULL;
        current = next;
    }
    current = NULL;
}