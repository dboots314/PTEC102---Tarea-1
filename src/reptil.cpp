#include "../include/reptil.h"

Reptil::Reptil(string _nombre, string _peso, string _color, string _tipo) : Animal(_nombre, _peso, _color), tipo(_tipo) {}

string Reptil::getTipo() const {
    return tipo;
}