#pragma once

#include "animal.h"

class Mamifero : public Animal {
    private: 
        int cantidad_patas;

    public: 
        Mamifero(string _nombre, string _peso, string _color, int _cantidad_patas);

        // Getters
        string getCantidadPatas() const;
};