#include "../include/anfibio.h"

Anfibio::Anfibio(string _nombre, string _peso, string _color, bool piel_babosa) : Animal(_nombre, _peso, _color), piel_babosa(piel_babosa) {}

string Anfibio::getPielBabosa() const {
    return (piel_babosa) ? "Babosa" : "No Babosa";
}