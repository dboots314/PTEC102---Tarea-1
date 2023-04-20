#include "../include/pez.h"

Pez::Pez(string _nombre, string _peso, string _color, int _cantidad_aletas, bool _escamas) : Animal(_nombre, _peso, _color), cantidad_aletas(_cantidad_aletas), escamas(_escamas) {}

string Pez::getCantidadAletas() const {
    switch (cantidad_aletas) {
        case 2:
            return "dos";
            break;
        case 3:
            return "tres";
            break;
        case 4:
            return "cuatro";
            break;
        case 5:
            return "cinco";
            break;
        case 6:
            return "seis";
            break;
        default:
            return "más de seis";
            break;
    }
}

string Pez::getEscamas() const { return (escamas) ? "SI" : "NO"; }