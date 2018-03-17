#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"

DtGato::DtGato(string nombre, float peso, Genero genero, TipoPelo tipoPelo) : DtMascota(nombre, peso, genero, (peso * 0.015)){
    this.tipoPelo = tipoPelo;
}

DtGato::~DtGato(){}

TipoPelo DtGato::getTipoPelo(){
    return this->tipoPelo;
}

