#include <iostream>
#include "GrafoMatriz.h"

int main() {
    GrafoMatriz miGrafo(7);
    std::cout << "Mi Grafo\n";
    miGrafo.nuevoVertice("1");
    miGrafo.nuevoVertice("2");
    miGrafo.nuevoVertice("3");
    miGrafo.nuevoVertice("4");
    miGrafo.nuevoVertice("5");
    miGrafo.nuevoVertice("6");
    miGrafo.nuevoVertice("7");
    miGrafo.nuevaArista("1","2");
    miGrafo.nuevaArista("1","3");
    miGrafo.nuevaArista("2","1");
    miGrafo.nuevaArista("2","3");
    miGrafo.nuevaArista("2","4");
    miGrafo.nuevaArista("3","1");
    miGrafo.nuevaArista("3","2");
    miGrafo.nuevaArista("3","4");
    miGrafo.nuevaArista("3","6");
    miGrafo.nuevaArista("4","2");
    miGrafo.nuevaArista("4","2");
    miGrafo.nuevaArista("4","6");
    miGrafo.nuevaArista("5","6");
    miGrafo.nuevaArista("6","3");
    miGrafo.nuevaArista("6", "4");
    miGrafo.nuevaArista("6","5");
    miGrafo.nuevaArista("6","7");
    miGrafo.nuevaArista("7","6");
    miGrafo.mostrarMatAd();
    miGrafo.borrarArista("7","6");
    miGrafo.mostrarMatAd();
    miGrafo.adyacente("7","7");
    miGrafo.borraVertice("2");
    miGrafo.borraVertice("7");
    miGrafo.borraVertice("5");
    miGrafo.muestraVertice();
    miGrafo.mostrarMatAd();

    return 0;
}
