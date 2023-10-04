#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* tail;
};
class Stack {
    Node* top;
    int count;
public:
    Stack();
    ~Stack();
    void Add(int n);
    void Del();
    int max();
    bool Empty();
    int Getsize();

};
Stack :: Stack() {
    top = nullptr; 
    count = 0;
}  
Stack :: ~Stack() {
    while (!Empty()) {
        Del();
    }
}
void Stack :: Add(int n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = top;
    newNode->tail = nullptr;

    if (top != nullptr) {
        top->tail = newNode;
    }

    top = newNode;
    count++;
}
void Stack ::Del() {
    if (Empty()) {
        cout << "Stack empty." << endl;
        return;
    }

    Node* temp = top;
    top = top->next;

    if (top != nullptr) {
        top->tail = nullptr;
    }

    delete temp;
    count--;
}
int Stack::max() {
    if (Empty()) {
        cout << "Stack empty." << endl;
    }
    return top->data;
}
bool Stack::Empty() {
    return count == 0;
}
int Stack::Getsize() {
    return count;
}

int main() {
    int size = 10;
    Stack stacktest;

    for (int i = 0; i < size; i++) {
        stacktest.Add(rand() % 100);
    }
    while (!stacktest.Empty()) {
        cout << "Top element: " << stacktest.max() << endl;
        stacktest.Del();
    }
    if (stacktest.Empty()) {
        cout << "The stack empty!" << endl;
    }
}
