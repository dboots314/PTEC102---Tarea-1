#include "../include/molusco.h"

Molusco::Molusco(string _nombre, string _peso, string _color, string _tipo_concha) : Animal(_nombre, _peso, _color), tipo_concha(_tipo_concha) {}

string Molusco::getTipoConcha() const {
    return tipo_concha;
}