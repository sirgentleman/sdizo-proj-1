#ifndef RBTree_H
#define RBTree_H

#include <string>

class RBTree {
    private:
        //struktura reprezentuj¹ca element znajduj¹cy siê w drzewie
        struct TreeElement {
            char color;
            int value;

            TreeElement* parent;
            TreeElement* right;
            TreeElement* left;
        };

        int size;
        TreeElement* root;
        TreeElement nullElement;

        void insert(TreeElement*, TreeElement*);
        void rotateLeft(TreeElement*);
        void rotateRight(TreeElement*);
        TreeElement* findElement(int, TreeElement*);
        void removeAll(TreeElement*&);
        void printTreeFromElement(std::string, std::string, TreeElement*);
    public:
        RBTree();
        ~RBTree();

        void add(int value);
        void remove(int value);

        void printTree();
        bool contains(int value);

        void loadFromFile();

        void fixTreeFrom(TreeElement *);
        void createRandom(int size, int max);

        
};

#endif