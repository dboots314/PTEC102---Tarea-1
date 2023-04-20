#include "../include/mamifero.h"

Mamifero::Mamifero(string _nombre, string _peso, string _color, int _cantidad_patas) : Animal(_nombre, _peso, _color), cantidad_patas(_cantidad_patas) {}

string Mamifero::getCantidadPatas() const {
    if (cantidad_patas == 2)
        return "dos";
    else 
        return "cuatro";
}