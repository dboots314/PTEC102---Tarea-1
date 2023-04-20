#include "../include/celentereo.h"

Celentereo::Celentereo(string _nombre, string _peso, string _color, int _cantidad_tentaculos) : Animal(_nombre, _peso, _color), cantidad_tentaculos(_cantidad_tentaculos) {}

string Celentereo::getCantidadTentaculos() {
    return to_string(cantidad_tentaculos) + " tentáculos";
}