#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <string>

class BinaryHeap {
private:
    int* table;
    int size;

public:
    BinaryHeap();
    ~BinaryHeap();

    void add(int);
    void remove(int);

    void heapifyDown(int); //moze tak moze nie

    void print();
    void printTree(std::string, std::string, int);
    bool contains(int);
    int getIndex(int);

    void loadFromFile();

};

#endif