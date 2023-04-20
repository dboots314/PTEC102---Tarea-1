#pragma once

#include "animal.h"

class Reptil : public Animal {
    private: 
        string tipo;

    public:
        Reptil(string _nombre, string _peso, string _color, string _tipo);

        // Getters
        string getTipo() const;
};