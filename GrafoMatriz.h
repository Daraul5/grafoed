#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "vertice.h"
#include <vector>
#include <string>

class GrafoMatriz {
private:
    int numVerts;
    int MaxVerts;
    std::vector<Vertice> verts;
    std::vector<std::vector<int>> matAd;
public:
    GrafoMatriz();
    GrafoMatriz(int mx);
    void nuevoVertice(const std::string &nom);
    bool existeVertice(const std::string &nom) const;
    int indiceVertice(const std::string &nom) const;
    void borraVertice(const std::string &nom);
    void muestraVertice() const;
    void nuevaArista(const std::string &v1, const std::string &v2);
    void borrarArista(const std::string &v1, const std::string &v2);
    void adyacente(const std::string &v1, const std::string &v2) const;
    void mostrarMatAd() const;
};

#endif // GRAFOMATRIZ_H
