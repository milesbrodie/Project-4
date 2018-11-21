/*
Miles Brodie
CS20A -- Section 4452
Project #4

This program will create a LinkedList and then sort it in ascending order using Merge Sort
*/

/*
This was a tough assignment for me and I unfortunately was not able to successfully get the program to work properly. I did
a lot of investigating on the internet and although I did find code that would allow me to successfully merge through a
LinkedList I still had a hard time making sense of it. I tried my best with my own attempt and I was able to create a LinkedList
of 50 random values and pass it to a function that would separate the values. I was unable to then sort through the values into
ascending order
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Node class which will point to next value in LinkedList
class node
{
public:
    node* next;
    int data;
};

// LinkedList class with public variables and functions
class LinkedList
{
public:
    int length;
    node* head;

    LinkedList();
    ~LinkedList();
    node* Insert(int index, int data);
    void print();
    void mergeSort(LinkedList* a, int first, int last);
    void mergeTogether(LinkedList* a, int first, int middle, int last);
};

// LinkedList constructor
LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
}

// LinkedList destructor
LinkedList::~LinkedList()
{
    std::cout << "LIST DELETED";
}

// Function that allows values to be placed into called LinkedList
node* LinkedList::Insert(int index, int data){

    if (index < 0) return NULL;
    int currIndex = 1;
    node* currNode = head;

    while (currNode && index > currIndex) {
        currNode = currNode->next;
        currIndex++;
    }

    if (index > 0 && currNode == NULL) return NULL;

    node* newNode = new node;
    newNode->data = data;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        this->length++;
    }
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
        this->length++;
    }

    return newNode;
}

// Function that will output all values within called LinkedList
void LinkedList::print()
{
    node* head = this->head;
    int i = 1;
    while(head){
        cout << head->data << " ";
        head = head->next;
        i++;
    }

    cout << "\n\n";
}

// Function that attempts to take in called LinkedList and sort values in ascending order
void mergeSort(LinkedList* a, int first, int last)
{
    LinkedList* x = a;

    if (first < last)
    {
        int middle = ((first + (last - 1)) / 2);
        mergeSort(x, first, middle);
        mergeSort(x, (middle + 1), last);
    } else {
        cout << "Invalid List" << endl;
    }
}

int main()
{
    // Create a new LinkedList named 'list'
    LinkedList* list = new LinkedList();

    // Fill 'list' with 50 random integers
    int index = 50;
    for (int i = 0; i < index; i++)
    {
        list->Insert(i, rand() % 100);
    }

    // print() will output values within LinkedList
    cout << "LinkedList values: \n";
    list->print();

    cout << "Merge Sort: \n";

    // mergeSort() will take in reference LinkedList and sort through values
    // mergeSort() will separate LinkedList values into single values and then rearrange values into ascending order
    mergeSort(list, 0, (list->length - 1));

    cout << endl;

    // print() will output values within LinkedList which should be in ascending order
    list->print();

    return 0;
}
