#ifndef ARRAY_H
#define ARRAY_H

class Array {
    public:
        int size;
        int* array;

    private:
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

};


#endif