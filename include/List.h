#ifndef LIST_H
#define LIST_H


class List {
private:
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

        void pushBack(int);
        void popBack();

        void pushFront(int);
        void popFront();

        void addAtIndex(int, int);
        void removeAtIndex(int);

        int getSize();
        void print();
        void clearList();

        void loadFromFile(); //todo   
        bool contains(int); 


};

#endif