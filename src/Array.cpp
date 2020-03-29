#include "../include/Array.h"
#include "iostream"

Array::Array()
{
    array = new int[0];
    size = 0;
}

Array::~Array()
{
    delete array;
    array = nullptr;
}

void Array::pushBack(int value) {
    int* tmpArray = array;
    array = new int[++size]; //moze jednak prosciej
    for(int iii = 0; iii < size-1; iii++) {
        array[iii] = tmpArray[iii];
    }
    delete tmpArray;
    array[size-1] = value;
}

void Array::popBack() {
    int* tmpArray = array;
    array = new int[--size]; //moze prosciej
    for(int iii = 0; iii < size; iii++) {
        array[iii] = tmpArray[iii];
    }
    delete tmpArray;
}

void Array::pushFront(int value) {
    int* tmpArray = array;
    array = new int[++size]; //moze jednak prosciej
    array[0] = value;
    for(int iii = 1; iii < size; iii++) {
        array[iii] = tmpArray[iii-1];
    }
    delete tmpArray;
}

void Array::popFront() {
    int* tmpArray = array;
    array = new int[--size]; //moze prosciej
    for(int iii = 0; iii < size; iii++) {
        array[iii] = tmpArray[iii+1];
    }
    delete tmpArray;
}

void Array::addAtIndex(int index, int value) {
    if(index < 0 || index > size) {
        std::cout << "Brak podanego indeksu w tablicy" << std::endl; //moze exception?
        return;
    }
    int* tmpArray = array;
    array = new int[++size];
    for(int iii = 0; iii < index; iii++) {
        array[iii] = tmpArray[iii];
    }

    array[index] = value;

    for(int iii = index+1; iii < size; iii++) {
        array[iii] = tmpArray[iii-1];
    }

    delete tmpArray;
}

void Array::removeAtIndex(int index) {
    if(index < 0 || index > size) {
        std::cout << "Brak podanego indeksu w tablicy" << std::endl; //moze exception?
        return;
    }
    int* tmpArray = array;
    array = new int[--size];
    for(int iii = 0; iii < index; iii++) {
        array[iii] = tmpArray[iii];
    }

    for(int iii = index; iii < size; iii++) {
        array[iii] = tmpArray[iii+1];
    }

    delete tmpArray;
}

int Array::getSize() {
    return size;
}
void Array::print() {
    std::cout << "Array: [";
    for(int iii=0; iii < size; iii++) {
        std::cout << " " << array[iii];
    }
    std::cout << " ]" << std::endl;
}