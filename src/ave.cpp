#include "../include/ave.h"

Ave::Ave(string _nombre, string _peso, string _color, int _cantidad_alas) : Animal(_nombre, _peso, _color), cantidad_alas(_cantidad_alas) {}

string Ave::getCantidadAlas() {
    return to_string(cantidad_alas) + " alas";
}