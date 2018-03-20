#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"

DtGato::DtGato(string nombre, Genero genero, float peso,  TipoPelo tipoPelo) : DtMascota(nombre, genero, peso, (float)(peso * 0.015)){
    this->tipoPelo = tipoPelo;
}
DtGato::~DtGato(){}

TipoPelo DtGato::getTipoPelo(){
    return this->tipoPelo;
}

