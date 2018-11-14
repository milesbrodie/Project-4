/*
Miles Brodie
CS20A -- Section 4452
Project #4
*/

#include <iostream>
#include <cstdlib>
#include <fstream>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    Node*  Insert(int index, int data);
    void print();
};


LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    std::cout << "LIST DELETED";
}

Node* LinkedList::Insert(int index, int data)
{

    if (index < 0) return NULL;

    int currIndex    =    1;
    Node* currNode    =    head;
    while (currNode && index > currIndex) {
        currNode    =    currNode->next;
        currIndex++;
    }

    if (index > 0 && currNode == NULL) return NULL;

    Node* newNode    =    new    Node;
    newNode->data    =    data;
    if (index == 0) {
        newNode->next    =    head;
        head        =    newNode;
        this->length++;
    }
    else {
        newNode->next    =    currNode->next;
        currNode->next    =    newNode;
        this->length++;
    }
    return newNode;
}


void LinkedList::print()
{
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << head->data<<endl;
        head = head->next;
        i++;
    }
}


int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();

    int index = 50;
    for (int i = 0; i < index; i++)
    {
        list->Insert(i, rand() % 100);
    }

    list->print();


    return 0;
}
