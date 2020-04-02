#ifndef RBTree_H
#define RBTree_H

#include <string>

class RBTree {
    private:
        struct TreeElement {
            char color;
            int value;

            TreeElement* parent;
            TreeElement* right;
            TreeElement* left;
        };

        int size;
        TreeElement* root;

    public:
        RBTree();
        ~RBTree();

        void add(int); //ok
        void remove(int); //ok

        //void print();
        void printTree(); //ok
        bool contains(int); //ok

        void loadFromFile(); //ok

        void fixTreeFrom(TreeElement *); //ok

        //utility
        void insert(TreeElement*, TreeElement*);
        void rotateLeft(TreeElement*);
        void rotateRight(TreeElement*);
        TreeElement* findElement(int, TreeElement*);
        void removeAll(TreeElement*&); //ok
        void printTreeFromElement(std::string, std::string, TreeElement*);
};

#endif

//TODO POSPRZATAC