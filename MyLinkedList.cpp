#include "MyLinkedList.h"
#include <stdexcept>
using namespace std;



MyLinkedList::MyLinkedList(){
    this-> head = nullptr;
    this -> head = this->tail = nullptr;
    this-> size = 0;
}

MyLinkedList::~MyLinkedList() {
    MyNodoLL* actual = head;
    while (actual != nullptr) {
        MyNodoLL* temp = actual;
        actual = actual->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

int MyLinkedList::length(){
    return this-> size;
}

bool MyLinkedList::isEmpty(){
    return this->size ==0;
}

int MyLinkedList::first(){
    if(size >0){
        return this->head->data;
    }else{
        throw invalid_argument("No se puede regresar el primer elemento de una lista vacia");
    }
}

int MyLinkedList::last(){
        if(size >0){
        return this->tail->data;
    }else{
        throw invalid_argument("No se puede regresar el primer elemento de una lista vacia");
    }
}

int MyLinkedList::getAt(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("No se puede obtener el elemento en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
    MyNodoLL* actual = this->head;
    int cont = 0;
    while (cont < pos) {
        actual = actual->next;
        cont++;
    }
    return actual->data;
}

void MyLinkedList::setAt(int pos, int data) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("No se puede establecer el valor en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
    MyNodoLL* actual = this->head;
    int cont = 0;
    while (cont < pos) {
        actual = actual->next;
        cont++;
    }
    actual->data = data;
}

void MyLinkedList::insertFirst(int data){
    MyNodoLL* nuevo = new MyNodoLL(data, this->head);
    nuevo ->next = this->head;
    this->head = nuevo;
    if(size==0){
        this->tail = nuevo;
    }
    this->size++;
}

void MyLinkedList::insertLast(int data) {
    MyNodoLL* nuevo = new MyNodoLL(data);
    if (this->size == 0) {
        this->head = this->tail = nuevo;
    } else {
        this->tail->next = nuevo;
        this->tail = nuevo;
    }
    this->size++;
}

void MyLinkedList::insertAt(int pos, int data) {
    if (pos < 0 || pos > this->size) {
        throw invalid_argument("No se puede insertar en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
    if (pos == 0) {
        insertFirst(data);
    } else if (pos == this->size) {
        insertLast(data);
    } else {
        MyNodoLL* actual = this->head;
        for (int i = 0; i < pos - 1; ++i) {
            actual = actual->next;
        }
        MyNodoLL* nuevo = new MyNodoLL(data, actual->next);
        actual->next = nuevo;
        this->size++;
    }
}

void MyLinkedList::removeFirst(){
    if (this->size > 0){
        MyNodoLL* temp = this-> head;
        this->head = this->head->next;
        delete temp;
        this->size--;
        if (this->size == 0){
            this->tail = nullptr;
        }
    } else {
        throw invalid_argument("No se puede eliminar el primer elemento de una lista vacia");
    }
}

void MyLinkedList::removeLast() {
    if (this->size == 0) {
        throw invalid_argument("No se puede eliminar el último elemento de una lista vacía");
    } else if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else {
        MyNodoLL* actual = this->head;
        while (actual->next != this->tail) {
            actual = actual->next;
        }
        delete this->tail;
        actual->next = nullptr;
        this->tail = actual;
    }
    this->size--;
}

void MyLinkedList::removeAt(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("No se puede eliminar el elemento en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
    if (pos == 0) {
        removeFirst();
    } else if (pos == this->size - 1) {
        removeLast();
    } else {
        MyNodoLL* actual = this->head;
        for (int i = 0; i < pos - 1; ++i) {
            actual = actual->next;
        }
        MyNodoLL* temp = actual->next;
        actual->next = temp->next;
        delete temp;
        this->size--;
    }
}

ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* actual = ll.head;
    while (actual != nullptr) {
        os << actual->data; 
        if (actual->next != nullptr) {
            os << ", "; 
        }
        actual = actual->next; 
    }
    return os; 
}