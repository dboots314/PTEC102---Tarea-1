#include "../include/animal.h"

Animal::Animal(string _nombre, string _peso, string _color) : nombre(_nombre), peso(_peso), color(_color) {}

// Getters
string Animal::getNombre() const { return nombre; }
string Animal::getPeso() const { return peso; }
string Animal::getColor() const { return color; }

string Animal::toString() {
    return "nombre: " + getNombre() + "\npeso: " + peso + "\ncolor: " + getColor();
}