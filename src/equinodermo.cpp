#include "../include/equinodermo.h"

Equinodermo::Equinodermo(string _nombre, string _peso, string _color, string _tipo) : Animal(_nombre, _peso, _color), tipo(_tipo) {}

string Equinodermo::getTipo() const {
    return tipo;
}