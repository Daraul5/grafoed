#include "vertice.h"

#include <utility>

Vertice::Vertice(std::string x): nombre(std::move(x)), numVertice(-1) {}

std::string Vertice::nomVertice() const {
    return nombre;
}

bool Vertice::equals(const Vertice &n) const {
    return nombre == n.nombre;
}

void Vertice::asigVert(int n) {
    numVertice = n;
}

int Vertice::getIndex() const {
    return numVertice;
}

std::ostream &operator<<(std::ostream &os, const Vertice &v) {
    os << v.nombre << " (" << v.numVertice << ")";
    return os;
}
