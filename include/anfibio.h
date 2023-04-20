#pragma once

#include "animal.h"

class Anfibio : public Animal {
    private: 
        bool piel_babosa;

    public: 
        Anfibio(string _nombre, string _peso, string _color, bool _piel_babosa);

        // Getters
        string getPielBabosa() const;
};