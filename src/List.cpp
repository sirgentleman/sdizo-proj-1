#include "List.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

//Konstruktor nowej listy (inicjalizacja ogona i głowy oraz rozmiaru)
List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Destruktor listy
List::~List() {
    head = nullptr;
    tail = nullptr;
}

//Dodawanie nowego elementu na końcu aktulanej listy (zmiana wskaźników ostatniego elementu)
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

//Usuwanie ostatniego elementu z listy (modyfikacja wskaźniak przedostatniego elementu)
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
    size != 0 ? --size : size;
}

//Dodawanie nowego elementu do listy na jej początku (zmiana w pierwszym elemencie)
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

//Usuwanie pierwszego elementu z listy (zmiany w drugim elemencie)
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

//Dodawanie nowego elementu na podanym "indeksie" czyli miejscu (przechodzimy po kolejnych elementach do wybranego indeksu - od tyłu lub od przodu)
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

//Usuwanie elementu z wybranego miejsca (docieramy tam od przodu lub tyłu, zależy od bliskości indeksu do rozmiaru listy)
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

//Usuwanie elementu o podanej wartości z listy
void List::remove(int value) {
    ListElement *current = head;
    for(int iii = 0; iii < size; iii++) {
        if(current->value == value) {
            if(iii == 0) {
                popFront();
                return;
            }
            if(iii == size-1) {
                popBack();
                return;
            }
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

//Funkcja zwracająca rozmiar listy
int List::getSize() {
    return size;
}

//Funkcja drukująca listę w formie: "Lista: [element1 element2 ...]"
void List::print() {
    std::cout << "Lista: [ ";
    ListElement* current = head;
    for(int iii = 0; iii < size; iii++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

//Funkcja usuwająca wszystkie elementy z listy
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

//Funkcja sprawdzająca czy element o podanej wartości znajduje się w liście
bool List::contains(int value) {
    ListElement* current = head;
    for(int iii = 0; iii < size; iii++) {
        if(current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

//Funkcja ładująca elementy z pliku do nowej listy
void List::loadFromFile() {
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file.is_open()) {
        this->clearList();
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for (int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            this->pushBack(std::stoi(input));
        }
    }
    else std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
    file.close();
}

//Funkcja generująca nową listę o losowych elementach (podajemy rozmiar oraz maksymalną wielkość elementu)
void List::createRandom(int elements, int max) {
    clearList();
    unsigned int seed = time(NULL);
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> dist(-max, max);

    for(int iii = 0; iii < elements; iii++) {
        this->pushBack(dist(generator));
    } 
}
