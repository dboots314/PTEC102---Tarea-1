#include "../include/antropodo.h"

Antropodo::Antropodo(string _nombre, string _peso, string _color, int _cantidad_pares_patas, bool _antenas) : Animal(_nombre, _peso, _color), cantidad_pares_patas(_cantidad_pares_patas), antenas(_antenas) {}

string Antropodo::getCantidadParesPatas() {
    return to_string(cantidad_pares_patas) + " pares";
}

string Antropodo::getAntenas() const {
    return (antenas) ? "con antenas" : "sin antenas";
}