//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_ELEMENT_H
#define JOGO_ELEMENT_H


template <class  TE> class Element {

private:
    Element<TE>* pNext;
    TE* item;

public:
    Element();
    ~Element();

    void setNext(Element<TE>* pNext){ this->pNext = pNext; }
    void setItem(TE* item){ this->item = item; }
    Element<TE>* getPNext(){ return pNext; }
    TE* getItem(){ return item; }
};

template <class TE>
Element<TE>::Element(){
    pNext = nullptr;
    item = nullptr;
}

template <class TE>
Element<TE>::~Element(){
    pNext = nullptr;
    item = nullptr;
}


#endif //JOGO_ELEMENT_H
