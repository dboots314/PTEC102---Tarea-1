#pragma once

#include "animal.h"

class Ave : public Animal {
    private: 
        int cantidad_alas;

    public: 
        Ave(string _nombre, string _peso, string _color, int _cantidad_alas);

        // Getters
        string getCantidadAlas();
};