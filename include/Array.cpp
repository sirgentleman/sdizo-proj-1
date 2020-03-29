#include "src\Array.h"

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
    for(int iii = 0; iii << size-1; iii++) {
        array[iii] = tmpArray[iii];
    }
    delete tmpArray;
    array[size-1] = value;
}

void popBack() {

}

void pushFront(int);
void popFront();

void addAtIndex(int, int);
void removeAtIndex(int);

int getSize();
void print();