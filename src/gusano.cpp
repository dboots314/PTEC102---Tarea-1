#include "../include/gusano.h"

Gusano::Gusano(string _nombre, string _peso, string _color, string _tipo) : Animal(_nombre, _peso, _color), tipo(_tipo) {}

string Gusano::getTipo() const {
    return tipo;
}