#pragma once

#include <string>

using namespace std;

class Animal {
    protected: 
        string nombre;
        string peso;
        string color;
    
    public:
        Animal(string _nombre, string _peso, string _color);

        // Getters
        string getNombre() const;
        string getPeso() const;
        string getColor() const;

        virtual string toString();
};