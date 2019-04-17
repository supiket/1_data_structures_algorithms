#include "SurveyClass.h"

SurveyClass::SurveyClass() {
    LinkedList *members = NULL;
}

SurveyClass::SurveyClass(const SurveyClass& other){
    this->members = new LinkedList();
    this->members->head = other.members->head;
    Node* thisCurrent = this->members->head;
    Node* otherCurrent = other.members->head;
    while(otherCurrent->next != NULL){
        thisCurrent->next = new Node (*otherCurrent->next);
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    this->members->tail = new Node(*otherCurrent);
}

SurveyClass& SurveyClass::operator=(const SurveyClass& list){
    if(this->members != NULL){
        this->members = NULL;
    }
    this->members = new LinkedList();
    this->members->head = list.members->head;
    Node* thisCurrent = this->members->head;
    Node* listCurrent = list.members->head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node (*listCurrent->next);
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->members->tail = new Node(*listCurrent);
}

SurveyClass::SurveyClass(SurveyClass&& other){
    this->members = new LinkedList();
    this->members->head = move(other.members->head);
    Node* thisCurrent = this->members->head;
    Node* otherCurrent = other.members->head;
    while(otherCurrent->next != NULL){
        thisCurrent->next = new Node (move(*otherCurrent->next));
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    this->members->tail = new Node(move(*otherCurrent));
    other.members = NULL;
}

SurveyClass& SurveyClass::operator=(SurveyClass&& list){
    if(this->members != NULL)
        this->members = NULL;
    this->members = new LinkedList;
    this->members->head = move(list.members->head);
    Node* thisCurrent = this->members->head;
    Node* listCurrent = list.members->head;
    while(listCurrent->next != NULL){
        thisCurrent->next = new Node (move(*listCurrent->next));
        thisCurrent = thisCurrent->next;
        listCurrent = listCurrent->next;
    }
    this->members->tail = new Node(move(*listCurrent));
    list.members = NULL;
    return *this;
}

SurveyClass::~SurveyClass(){
    Node* current = this->members->head;
    while(current != NULL){
        Node* next = current->next;
        current = NULL;
        current = next;
    }
    this->members->head = NULL;
}

void SurveyClass::handleNewRecord(string _name, float _amount){
    if(this->members != NULL) {
        if(this->members->head != NULL){
            Node *iterator = this->members->head;
            bool updated = false;
            while (iterator != NULL) {
                if (iterator->name == _name) {
                    iterator->amount = 0;
                    iterator->amount = _amount;
                    updated = true;
                    break;
                }
                iterator = iterator->next;
            }
            if (!updated) {
                Node *newNode = new Node(_name, _amount);
                this->members->tail->next = newNode;
                this->members->tail = newNode;
                this->members->length++;
            }
        }
        else{
            this->members->head = new Node(_name, _amount);
            this->members->tail = this->members->head;
            this->members->length = 1;
        }
    } else{
        this->members = new LinkedList();
        this->members->head = new Node(_name, _amount);
        this->members->tail = this->members->head;
        this->members->length = 1;
    }
}

float SurveyClass::calculateMinimumExpense(){
    Node* iterator = this->members->head;
    float result = iterator->amount;
    while(iterator != NULL){
        if(iterator->next != NULL) {
            if (result >= iterator->next->amount)
                result = iterator->next->amount;
        }
        iterator = iterator->next;
    }
    return result;
}

float SurveyClass::calculateMaximumExpense(){
    Node* iterator = this->members->head;
    float result = iterator->amount;
    while(iterator != NULL){
        if(iterator->next != NULL) {
            if (result < iterator->next->amount)
                result = iterator->next->amount;
        }
        iterator = iterator->next;
    }
    return result;
}

float SurveyClass::calculateAverageExpense(){
    Node* iterator = this->members->head;
    float result;
    int number = 0;
    while(iterator != NULL){
        result = result + iterator->amount;
        iterator = iterator->next;
        number++;
    }
    if(number != 0) {
        result = result / number;
        result = result * 100;
        result = (int) result;
        result = (float) result;
        result = result / 100;
        return result;
    }
    else
        return 0;
}
