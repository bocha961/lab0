#ifndef UTILS_H
#define UTILS_H
// Write your header file here.
#include <string>

using std::string;

enum Genero{macho, hembra};

string generoString(Genero g); 

enum RazaPerro{ labrador, ovejero, bulldog, pitbull, collie, pekines, otro};

string razaPerroString(RazaPerro r);

enum TipoPelo{ corto, mediano, largo};

string tipoPeloString(TipoPelo t);

#endif