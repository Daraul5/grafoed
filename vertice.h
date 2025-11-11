#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <ostream>

class Vertice {
private:
    std::string nombre;
    int numVertice;
public:
    Vertice(std::string x="");
    std::string nomVertice() const;
    bool equals(const Vertice &n) const;
    void asigVert(int n);
    int getIndex() const;
    friend std::ostream &operator<<(std::ostream &os, const Vertice &v);
};

#endif // VERTICE_H

