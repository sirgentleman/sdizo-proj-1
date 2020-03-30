#include "../include/List.h"
#include <iostream>
#include <fstream>

List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List() {
    head = nullptr;
    tail = nullptr;
}

void List::pushBack(int value) {
    ListElement* tmp = new ListElement;
    tmp->value = value;
    tmp->prev = tail;
    tmp->next = nullptr;
    if(head == nullptr) {
        head = tmp;
    }
    else {
        tail->next = tmp;
    }
    tail = tmp;
    size++;
}

void List::popBack() {
    ListElement* oldTail = tail;
    if(size > 1) {
        tail = oldTail->prev;
        tail->next = nullptr;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }
    delete oldTail;
    size != 0 ? --size : size; //DUZA SZANSA ŻE SIE TUTAJ WYSYPIE
}

void List::pushFront(int value) {
    ListElement* tmp = new ListElement;
    tmp->value = value;
    tmp->next = head;
    tmp->prev = nullptr;
    if(size == 0) {
        tail = tmp;
    }
    else {
        head->prev = tmp;
    }
    head = tmp;
    size++;
}

void List::popFront() {
    ListElement* oldHead = head;
    if(size > 1) {
        head = oldHead->next;
        head->prev = nullptr;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }
    delete oldHead;
    size != 0 ? --size : size;
}

void List::addAtIndex(int index, int value) {
    if(index < 0 || index > size) {
        std::cout << "Niewlasciwy indeks!" << std::endl;
        return;
    }

    if(index == size) pushBack(value);
    else if(index == 0) pushFront(value);
    else {
        ListElement* currentElement;
        if(index <= size/2) {
            currentElement = head;
            for(int iii = 1; iii < index; iii++)
                currentElement = currentElement->next;
        }
        else {
            currentElement = tail;
            for(int iii = size-1; iii >= index; iii--)
                currentElement = currentElement->prev;
        }
        ListElement* tmp = new ListElement;
        tmp->value = value;
        tmp->prev = currentElement;
        tmp->next = currentElement->next;
        currentElement->next->prev = tmp;
        currentElement->next = tmp;
        size++;
    }
}

void List::removeAtIndex(int index) {
    if(index < 0 || index > size) {
        std::cout << "Niewlasciwy indeks!" << std::endl;
        return;
    }

    if(index == size) popBack();
    else if(index == 0) popFront();
    else {
        ListElement* currentElement;
        if(index <= size/2) {
            currentElement = head;
            for(int iii = 1; iii <= index; iii++)
                currentElement = currentElement->next;
        }
        else {
            currentElement = tail;
            for(int iii = size-1; iii > index; iii--)
                currentElement = currentElement->prev;
        }
        currentElement->next->prev = currentElement->prev;
        currentElement->prev->next = currentElement->next;
        delete currentElement;
        size--;
    }
}

int List::getSize() {
    return size;
}

void List::print() {
    std::cout << "List: [ ";
    ListElement* current = head;
    for(int iii = 0; iii < size; iii++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

void List::clearList() {
    ListElement* current;
    while (head != nullptr) {
        current = head->next;
        delete head;
        head = current;
    }
    tail = nullptr;
    size = 0;
}

bool List::contains(int value) {
    ListElement* current = head;
    for(int iii = 0; iii < size; iii++) {
        if(current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

void List::loadFromFile() { //jakas informacja czemu sie nie otworzylo?
    std::string fileName;
    std::cout << "Podaj nazwę pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if(file.is_open()) {
        this->clearList();
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for(int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            this->pushBack(std::stoi(input));
        }
    }
    file.close();
}
