#include "RBTree.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>


//Konstruktor nowego drzewa czerwono-czarnego (razem inicjalizacja elementu NULL na koñcu drzewa)
RBTree::RBTree() {
    nullElement.value = 0;
    nullElement.color = 'b';
    nullElement.right = &nullElement;
    nullElement.left = &nullElement;
    nullElement.parent = &nullElement;
    root = &nullElement;
    size = 0;
}

//Destruktor drzewa (usuwanie wszystkich elementów)
RBTree::~RBTree() {
    removeAll(root);
}

//Dodawanie nowych elementów o podanej wartoœci (dodajemy nowy czarny element w podobny sposób jak w BST, nastêpnie przywracamy w³asnoœci RBT)
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
    //Tutaj przywracamy w³asnoœci
    fixTreeFrom(newElement);
}

//Funkcja s³u¿¹ca do usuwania wszystkich elementów od wybranego elementu w dó³
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

//Funkcja s³u¿aca do usuwania wybranej wartoœci z drzewa (usuwamy wartoœæ poprzez znalezienie nastêpnika a nastêpnie naprawiamy w³asnoœci RBT)
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

    //Rozpoczecie naprawiania w³asnoœci drzewa
    if(succ->color == 'b') {
        while(el1 != root && el1->color == 'b') {
            if(el1 == el1->parent->left) {
                el2 = el1->parent->right;

                //Przypadek 1
                if(el2->color == 'r') {
                    el2->color = 'b';
                    el1->parent->color = 'r';
                    rotateLeft(el1->parent);
                    el2 = el1->parent->right;
                }
                
                //Przypadek 2
                if(el2->right->color == 'b' && el2->left->color == 'b') {
                    el2->color = 'r';
                    el1 = el1->parent;
                    
                } else {
                    //Przypadek 3
                    if(el2->right->color == 'b') {
                        el2->left->color = 'b';
                        el2->color = 'r';
                        rotateRight(el2);
                        el2 = el1->parent->right;
                    }
                    //Przypadek 4
                    el2->color = el1->parent->color;
                    el1->parent->color = 'b';
                    el2->right->color = 'b';
                    rotateLeft(el1->parent);
                    el1 = root;
                }
            }
            else { //ROZPATRZENIE LUSTRZANYCH PRZYPADKÓW
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

//Funkcja szukaj¹ca wybranego elementu zaczynaj¹c od podanego - dzia³a rekurencyjnie
RBTree::TreeElement* RBTree::findElement(int value, TreeElement* current) {
    if(current == &nullElement) return &nullElement;
    if(current->value == value)
        return current;
    if(current->value > value) return findElement(value, current->left);
    else return findElement(value, current->right);
}

//Funkcja sprawdzaj¹ca czy wybrany element znajduje siê w drzewie RBT
bool RBTree::contains(int value) {
    if(findElement(value, root) != &nullElement) return true;
    return false;
}

//Funkcja dodaj¹ca nowy element w drzewie na zasadzie BST (pierwsza czêœæ dodawania elementu do drzewa RBT0 - dzia³a rekurencyjnie
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

//Funkcja drukuj¹ca drzewo
void RBTree::printTree() {
    printTreeFromElement("","",root);
}

//Funkcja ³aduj¹ca elementy z pliku do nowego RBT
void RBTree::loadFromFile() {
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file.is_open()) {
        removeAll(root);
        std::string input;
        std::getline(file, input);
        int elements = std::stoi(input);
        for (int iii = 0; iii < elements; iii++) {
            std::getline(file, input);
            add(std::stoi(input));
        }
    }
    else std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
    file.close();
}

//Funkcja generuj¹ca nowe RBT z losowymi elemenatami (podajemy wielkoœæ elementów i maksmylan¹ wartoœæ)
void RBTree::createRandom(int elements, int max) {
    removeAll(root);
    unsigned int seed = time(NULL);
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> dist(-max, max);

    for(int iii = 0; iii < elements; iii++) {
        this->add(dist(generator));
    } 
}

//Funkcja pomocnicza wyswietlaj¹ca kolejne czêœci drzewa
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

//Funkcja pomocnicza s³u¿aca do obrócenia czêœci drzewa wzglêdem wybranego elementu w prawo
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

//Funkcja pomocnicza s³u¿aca do obrócenia czêœci drzewa wzglêdem wybranego elementu w lewo
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

//Funkcja naprawiaj¹ca w³asnoœci drzewa zniszczone przy dodawniu nowego elementu - dzia³a rekurencyjnie
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
            //Przypadek 1
            if(elGParent->right != &nullElement && elGParent->right->color == 'r') {
                if(elGParent != root) {
                    elGParent->color = 'r';
                }
                elGParent->right->color = 'b';
                elParent->color = 'b';
                fixTreeFrom(elGParent);
            }
            else if(elParent->left == element && (elGParent->right == &nullElement || (elGParent->right != &nullElement && elGParent->right->color == 'b'))) { //Przypadek 2
                rotateRight(elGParent);
                elGParent->color = 'r';
                elParent->color = 'b';
                if(elParent->parent == nullptr) root = elParent;
            }
            else if(elParent->left != element && (elGParent->right == &nullElement || (elGParent->right != &nullElement && elGParent->right->color == 'b'))) { //Przypadek 3
                rotateLeft(elParent);
                rotateRight(elGParent);
                elGParent->color = 'r';
                element->color = 'b';
                if(element->parent == nullptr) root = element;
            }
        }
        else { //ELEMENT JEST PO PRAWEJ DZIADKA - przypadki lustrzane
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