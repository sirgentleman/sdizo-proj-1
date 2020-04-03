#include "RBTree.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

RBTree::RBTree() {
    nullElement.value = 0;
    nullElement.color = 'b';
    nullElement.right = &nullElement;
    nullElement.left = &nullElement;
    nullElement.parent = &nullElement;
    root = &nullElement;
    size = 0;
}

RBTree::~RBTree() {
    removeAll(root);
}

void RBTree::add(int value) {
    TreeElement* newElement = new TreeElement;
    newElement->value = value;
    newElement->color = 'r';
    newElement->right = &nullElement;
    newElement->left = &nullElement;
    newElement->parent = nullptr;
    if(size == 0) {
        newElement->color = 'b';
        root = newElement;
    }
    else insert(root, newElement);
    size++;

    fixTreeFrom(newElement);
}


void RBTree::removeAll(TreeElement*& element) {
    if(size == 0) {
        nullElement.value = 0;
        nullElement.color = 'b';
        nullElement.right = &nullElement;
        nullElement.left = &nullElement;
        nullElement.parent = &nullElement;
        root = &nullElement;
        return;
    }
    if(element->right != &nullElement) removeAll(element->right);
    if(element->left != &nullElement) removeAll(element->left);
    delete element;
    size--;
}

void RBTree::remove(int value) {
    TreeElement* element = findElement(value, root);
    if(element == &nullElement) return;
    TreeElement *succ, *el1, *el2;

    if(element->right == &nullElement || element->left == &nullElement)
        succ = element;
    else {
        succ = element->right;
        while(succ->left != &nullElement) succ=succ->left;
    }

    if(succ->left != &nullElement)  el1 = succ->left;
    else el1 = succ->right;

    el1->parent = succ->parent;

    if(succ->parent == nullptr) root = el1;
    else {
        if(succ->parent->left == succ) succ->parent->left = el1;
        else succ->parent->right = el1;
    }

    if(element != succ) {
        element->value = succ->value;
    }

    if(succ->color == 'b') {
        while(el1 != root && el1->color == 'b') {
            if(el1 == el1->parent->left) {
                el2 = el1->parent->right;

                //el2 jest czeronwe
                if(el2->color == 'r') {
                    el2->color = 'b';
                    el1->parent->color = 'r';
                    rotateLeft(el1->parent);
                    el2 = el1->parent->right;
                }
                
                if(el2->right->color == 'b' && el2->left->color == 'b') {
                    el2->color = 'r';
                    el1 = el1->parent;
                    
                } else {
                    if(el2->right->color == 'b') {
                        el2->left->color = 'b';
                        el2->color = 'r';
                        rotateRight(el2);
                        el2 = el1->parent->right;
                    }
                    el2->color = el1->parent->color;
                    el1->parent->color = 'b';
                    el2->right->color = 'b';
                    rotateLeft(el1->parent);
                    el1 = root;
                }
            }
            else {
                el2 = el1->parent->left;

                if(el2->color == 'r') {
                    el2->color = 'b';
                    el1->parent->color = 'r';
                    rotateRight(el1->parent);
                    el2 = el1->parent->left;
                }
                
                if(el2->right->color == 'b' && el2->left->color == 'b') {
                    el2->color = 'r';
                    el1 = el1->parent;
                    
                } else {
                    if(el2->left->color == 'b') {
                        el2->right->color = 'b';
                        el2->color = 'r';
                        rotateLeft(el2);
                        el2 = el1->parent->left;
                    }
                    el2->color = el1->parent->color;
                    el1->parent->color = 'b';
                    el2->right->color = 'b';
                    rotateRight(el1->parent);
                    el1 = root;
                }
            } 
        }
    }
    el1->color = 'b';
    delete succ;
    size--;
}

RBTree::TreeElement* RBTree::findElement(int value, TreeElement* current) {
    if(current == &nullElement) return &nullElement;
    if(current->value == value)
        return current;
    if(current->value > value) return findElement(value, current->left);
    else return findElement(value, current->right);
}

bool RBTree::contains(int value) {
    if(findElement(value, root) != &nullElement) return true;
    return false;
}

void RBTree::insert(RBTree::TreeElement* current,RBTree::TreeElement* newElement) {
     if(current->value >= newElement->value) {
         if(current->left != &nullElement) insert(current->left, newElement);
         else {
             newElement->parent = current;
              current->left = newElement;
         }
     }
     else {
         if(current->right != &nullElement) insert(current->right, newElement);
         else {
             newElement->parent = current;
             current->right = newElement;
         }
     }
}

void RBTree::printTree() {
    printTreeFromElement("","",root);
}

void RBTree::loadFromFile() { //jakas informacja czemu sie nie otworzylo?
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if(file.is_open()) {
        removeAll(root);
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for(int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            add(std::stoi(input));
        }
    }
    file.close();
}

void RBTree::createRandom(int elements, int max) {
    removeAll(root);
    unsigned int seed = time(NULL);
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> dist(-max, max);

    for(int iii = 0; iii < elements; iii++) {
        this->add(dist(generator));
    } 
}


//UTIL FUNCTIONS


void RBTree::printTreeFromElement(std::string sp, std::string sn, TreeElement* current)
{
    std::string s;
    std::string cr,cp,cl;
    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;
    if (current != &nullElement)
    {
        s = sp;
        if (sn == cr)
            s[s.length() - 2] = ' ';
        printTreeFromElement(s + cp, cr, current->right);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << current->value << current->color << std::endl;

        s = sp;
        if (sn == cl)
            s[s.length() - 2] = ' ';
        printTreeFromElement(s + cp, cl, current->left);
    }
}


void RBTree::rotateRight(TreeElement* element) {
    TreeElement* leftElement = element->left;
    TreeElement* rightElement = element->right;
    
    if(element->parent == nullptr) 
        root = leftElement;
    else if(element->parent->left == element)
        element->parent->left = leftElement;
    else
        element->parent->right = leftElement;
    leftElement->parent = element->parent;

    if(leftElement->right != &nullElement)
        leftElement->right->parent = element;
    element->left = leftElement->right;

    element->parent = leftElement;
    leftElement->right = element;

}

void RBTree::rotateLeft(TreeElement* element) {
    TreeElement* leftElement = element->left;
    TreeElement* rightElement = element->right;
    
    if(element->parent == nullptr) 
        root = rightElement;
    else if(element->parent->left == element)
        element->parent->left = rightElement;
    else
        element->parent->right = rightElement;
    rightElement->parent = element->parent;

    if(rightElement->left != &nullElement)
        rightElement->left->parent = element;
    element->right = rightElement->left;

    element->parent = rightElement;
    rightElement->left = element;
}

void RBTree::fixTreeFrom(TreeElement* element) {
    if(element == root) {
        element->color = 'b';
        return;
    }

    if(element->color == 'r' && element->parent->color == 'r') {
        TreeElement* elParent = element->parent;
        TreeElement* elGParent = element->parent->parent;
        //ELEMENT JEST PO LEWEJ DZIADKA
        if(elGParent->left == elParent) {
            if(elGParent->right != &nullElement && elGParent->right->color == 'r') {
                if(elGParent != root) {
                    elGParent->color = 'r';
                }
                elGParent->right->color = 'b';
                elParent->color = 'b';
                fixTreeFrom(elGParent);
            }
            else if(elParent->left == element && (elGParent->right == &nullElement || (elGParent->right != &nullElement && elGParent->right->color == 'b'))) {
                rotateRight(elGParent);
                elGParent->color = 'r';
                elParent->color = 'b';
                if(elParent->parent == nullptr) root = elParent;
            }
            else if(elParent->left != element && (elGParent->right == &nullElement || (elGParent->right != &nullElement && elGParent->right->color == 'b'))) {
                rotateLeft(elParent);
                rotateRight(elGParent);
                elGParent->color = 'r';
                element->color = 'b';
                if(element->parent == nullptr) root = element;
            }
        }
        else {
            if(elGParent->left != &nullElement && elGParent->left->color == 'r') {
               if(elGParent != root) {
                    elGParent->color = 'r';
                }
                elGParent->left->color = 'b';
                elParent->color = 'b';
                fixTreeFrom(elGParent);
            }
            else if(elParent->right == element && (elGParent->left == &nullElement || (elGParent->left != &nullElement && elGParent->left->color == 'b'))) {
                rotateLeft(elGParent);
                elGParent->color = 'r';
                elParent->color = 'b';
                if(elParent->parent == nullptr) root = elParent;
            }
            else if(elParent->right != element && (elGParent->left == &nullElement || (elGParent->left != &nullElement && elGParent->left->color == 'b'))) {
                rotateRight(elParent);
                rotateLeft(elGParent);
                elGParent->color = 'r';
                element->color = 'b';
                if(element->parent == nullptr) root = element;
            }
        }
    }
}