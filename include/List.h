#ifndef LIST_H
#define LIST_H


class List {
private:
        //struktura elementu znajduj¹cego siê w liœcie
        struct ListElement {
            int value;
            ListElement* prev;
            ListElement* next;
        };
        
        ListElement* head;
        ListElement* tail;
        int size;

public:
        List();
        ~List();

        void pushBack(int value);
        void popBack();

        void pushFront(int value);
        void popFront();

        void addAtIndex(int index, int value);
        void removeAtIndex(int index);
        void remove(int value);

        int getSize();
        void print();
        void clearList();

        void loadFromFile();
        bool contains(int value); 
        void createRandom(int elements, int max);


};

#endif