#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <string>

class BinaryHeap {
private:
    int* table;
    int size;

    void heapifyDown(int index);
public:
    BinaryHeap();
    ~BinaryHeap();

    void add(int value);
    void remove(int value);

    void print();
    void printTree(std::string, std::string, int);
    bool contains(int value);
    int getIndex(int value);

    void loadFromFile();
    void createRandom(int size, int max);

};

#endif