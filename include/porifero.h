#pragma once 

#include "animal.h"

class Porifero : public Animal {
    private:
        string tipo;

    public:
        Porifero(string _nombre, string _peso, string _color);
};