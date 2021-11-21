//
// Created by segalle on 11/10/21.
//

#ifndef JOGO_BEING_H
#define JOGO_BEING_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Being {

private:

    int id;

public:

    Being();

    ~Being();

    virtual void run() = 0;

    void setId(int id);

    const int getId();

};


#endif //JOGO_BEING_H
