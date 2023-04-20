#pragma once 

#include "animal.h"

class Molusco : public Animal {
    private:
        string tipo_concha;

    public:
        Molusco(string _nombre, string _peso, string _color, string _tipo_concha);

        // Getters
        string getTipoConcha() const;
};