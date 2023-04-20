#pragma once

#include "animal.h"

class Pez : public Animal {
    private: 
        int cantidad_aletas;
        bool escamas;

    public: 
        Pez(string _nombre, string _peso, string _color, int _cantidad_aletas, bool _escamas);

        // Getters
        string getCantidadAletas() const;
        string getEscamas() const;
};