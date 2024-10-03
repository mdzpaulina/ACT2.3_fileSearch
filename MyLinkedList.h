#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;
struct MyNodoLL{
    int data;
    MyNodoLL* next;
    MyNodoLL(int data, MyNodoLL* next){
        this-> data = data;
        this-> next = next;
    }

    // Constructor para el caso en el que inicializa el nodo solo con un valor (el siguiente es nullptr por defecto)
    MyNodoLL(int data):MyNodoLL(data, nullptr){}  //Reutilización de código
};

class MyLinkedList{
    public:
        MyNodoLL* head;
        MyNodoLL* tail;
        int size;
        int pos;
    //public:
        MyLinkedList();
        ~MyLinkedList();  //Destructor
        int length();
        bool isEmpty();
        int first();
        int last();
        void insertFirst(int data);
        int getAt(int pos);
        void setAt(int pos, int data);
        void insertLast(int data);
        void insertAt(int pos, int data);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        // Sobrecarga del operador << para imprimir la lista enlazada
        friend ostream& operator<<(ostream& os, const MyLinkedList& ll);  //Imprime los elementos de la lista con comas y sin espacios
};

#endif