#pragma once 

#include "animal.h"

class Gusano : public Animal {
    private:
        string tipo;

    public:
        Gusano(string _nombre, string _peso, string _color, string tipo);

        // Getters
        string getTipo() const;
};