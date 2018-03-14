#ifndef UTILS_H
#define UTILS_H
// Write your header file here.
#include <string>

using std::string;

enum class Genero{Macho, Hembra};

string generoString(); 

enum class RazaPerro{ labrador, ovejero, bulldog, pitbull, collie, pekines, otro};

string razaPerroString();

enum class TipoPelo{ Corto, Mediano, Largo};

string tipoPeloString();

#endif