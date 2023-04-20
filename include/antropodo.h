#pragma once 

#include "animal.h"

class Antropodo : public Animal {
    private:
        int cantidad_pares_patas;
        bool antenas;

    public:
        Antropodo(string _nombre, string _peso, string _color, int _cantidad_pares_aletas, bool _antenas);

        // Getters
        string getCantidadParesPatas();
        string getAntenas() const;
};