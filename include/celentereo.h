#pragma once 

#include "animal.h"

class Celentereo : public Animal {
    private:
        int cantidad_tentaculos;

    public:
        Celentereo(string _nombre, string _peso, string _color, int cantidad_tentaculos);

        // Getters
        string getCantidadTentaculos();
};