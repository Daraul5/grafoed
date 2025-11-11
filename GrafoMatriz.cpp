#include "GrafoMatriz.h"
#include <iostream>

GrafoMatriz::GrafoMatriz(): numVerts(0), MaxVerts(20) {
    verts.reserve(MaxVerts);
    matAd.assign(MaxVerts, std::vector<int>(MaxVerts, 0));
}

GrafoMatriz::GrafoMatriz(int mx): numVerts(0), MaxVerts(mx) {
    verts.reserve(MaxVerts);
    matAd.assign(MaxVerts, std::vector<int>(MaxVerts, 0));
}

void GrafoMatriz::nuevoVertice(const std::string &nom) {
    if (existeVertice(nom)) {
        std::cout << "Lo siento no lo puedo agregar, Ya existe\n";
        return;
    }
    if (numVerts >= MaxVerts) {
        std::cout << "No se puede agregar, se alcanzó el número máximo de vértices\n";
        return;
    }
    Vertice v(nom);
    v.asigVert(numVerts);
    verts.push_back(v);
    numVerts++;
    if (numVerts == 1)
        std::cout << "Se agrego el primer vertice:" << nom << '\n';
    else
        std::cout << "Se agrego el siguiente vertice:" << nom << '\n';
}

bool GrafoMatriz::existeVertice(const std::string &nom) const {
    for (int j = 0; j < numVerts; j++) {
        if (verts[j].nomVertice() == nom) return true;
    }
    return false;
}

int GrafoMatriz::indiceVertice(const std::string &nom) const {
    for (int j = 0; j < numVerts; j++) {
        if (verts[j].nomVertice() == nom) return j;
    }
    return -1;
}

void GrafoMatriz::borraVertice(const std::string &nom) {
    if (!existeVertice(nom)) return;
    int indice = indiceVertice(nom);
    if (indice < 0) return;
    // eliminar vértice
    verts.erase(verts.begin() + indice);
    // actualizar índices en vértices
    for (int i = 0; i < static_cast<int>(verts.size()); i++) verts[i].asigVert(i);
    // eliminar fila
    matAd.erase(matAd.begin() + indice);
    // eliminar columna
    for (auto &row : matAd) {
        if (static_cast<int>(row.size()) > indice)
            row.erase(row.begin() + indice);
    }
    numVerts--;
    std::cout << "Se borro vertice: " << nom << " (indice " << indice << ")\n";
}

void GrafoMatriz::muestraVertice() const {
    std::cout << "Mostrando los vertices son:\n";
    for (int i = 0; i < numVerts; i++) {
        std::cout << "----:" << verts[i].nomVertice() << '\n';
    }
}

void GrafoMatriz::nuevaArista(const std::string &v1, const std::string &v2) {
    if (existeVertice(v1) && existeVertice(v2)) {
        std::cout << "Se agrega la arista\n";
        int i = indiceVertice(v1);
        int j = indiceVertice(v2);
        if (i >= 0 && j >= 0) {
            if (i >= static_cast<int>(matAd.size()) || j >= static_cast<int>(matAd.size())) {
                // expandir la matriz si es necesario (raro con la implementación actual)
                int newSize = std::max(i, j) + 1;
                matAd.resize(newSize);
                for (auto &row : matAd) row.resize(newSize);
            }
            matAd[i][j] = 1;
        }
    } else {
        std::cout << "No se puede agregar la arista alguno de los vertices no existe\n";
    }
}

void GrafoMatriz::borrarArista(const std::string &v1, const std::string &v2) {
    if (existeVertice(v1) && existeVertice(v2)) {
        int i = indiceVertice(v1);
        int j = indiceVertice(v2);
        if (i >= 0 && j >= 0 && i < static_cast<int>(matAd.size()) && j < static_cast<int>(matAd.size()))
            matAd[i][j] = 0;
    } else {
        std::cout << "No se puede borrar la arista alguno de los vertices no existe\n";
    }
}

void GrafoMatriz::adyacente(const std::string &v1, const std::string &v2) const {
    if (existeVertice(v1) && existeVertice(v2)) {
        int i = indiceVertice(v1);
        int j = indiceVertice(v2);
        if (i >= 0 && j >= 0 && i < static_cast<int>(matAd.size()) && j < static_cast<int>(matAd.size())) {
            if (matAd[i][j] == 1)
                std::cout << "\nSi son adyasentes, existe una arista entre los dos vértices\n";
            else
                std::cout << "\nNo son adyasentes, No existe una arista entre los vértices\n";
        }
    } else {
        std::cout << "\nAlguno de los dos vértices No existe\n";
    }
}

void GrafoMatriz::mostrarMatAd() const {
    for (int i = 0; i < numVerts; i++) {
        for (int j = 0; j < numVerts; j++) {
            std::cout << "(" << (i + 1) << "," << (j + 1) << ")=" << matAd[i][j] << " ";
        }
        std::cout << "\n";
    }
}
