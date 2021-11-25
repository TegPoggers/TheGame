//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_LIST_H
#define JOGO_LIST_H

#include "Element.h"
#include <iostream>
using namespace std;

template <class  TL> class List {
private:
    Element<TL>* pFirst;
    Element<TL>* pLast;
    int len;

public:
    List();
    ~List();

    int getLen(){ return len; }
    TL* getItem( int pos);
    void push(TL* item);
    void pop(TL* item);

    TL* operator[](int i);

};

template <class TL>
List<TL>::List(){
    len = 0;
    pFirst = nullptr;
    pLast = nullptr;
}

template <class TL>
List<TL>::~List(){
    pFirst = nullptr;
    pLast = nullptr;
    len = 0;
}

template <class TL>
TL* List<TL>::getItem(int pos){
    Element<TL>* temp = pFirst;

    if (pos == 0){
        return temp->getItem();
    }
    for (int i = 0; i < pos; i++){
        temp = temp->getPNext();
    }

    return temp->getItem();
}

template <class TL>
void List<TL>::push(TL* item){

    if (pFirst == nullptr){
        pFirst = new Element<TL>;
        pFirst->setItem(item);
        pLast = pFirst;
    }
    else {
        Element<TL>* temp = new Element<TL>;
        temp->setItem(item);
        pLast->setNext(temp);
        pLast = temp;
    }
    len++;
}

template <class TL>
void List<TL>::pop(TL* item){

    Element<TL>* temp = pFirst;
    Element<TL>* previous = nullptr;

    while (temp && temp->getItem() != item){
        previous = temp;
        temp = temp->getPNext();
    }

    if (temp = pFirst){
        pFirst = temp->getPNext();
    }
    else if (temp = pLast){
        previous->setNext(nullptr);
        pLast = previous;
    }
    else if (temp){
        previous->setNext(temp->getPNext());
    }

    if (temp){
        len--;
    }
    delete temp;
}

template <class TL>
TL* List<TL>::operator[](int i){
    return this->getItem(i);
}



#endif //JOGO_LIST_H
