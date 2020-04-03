#ifndef ARRAY_H
#define ARRAY_H

class Array {
    private:
        int size;
        int* array;

        
    public:
        Array();
        ~Array();

        void pushBack(int);
        void popBack();

        void pushFront(int);
        void popFront();

        void addAtIndex(int, int);
        void removeAtIndex(int);

        int getSize();
        void print();

        void loadFromFile();
        bool contains(int);
        void createRandom(int size, int max);

};


#endif