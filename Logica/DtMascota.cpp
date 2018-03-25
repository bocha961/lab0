#include "../Cabezales/DtMascota.h"

DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiaria){
    this->nombre         = nombre;
    this->genero         = genero;
    this->peso           = peso;
    this->racionDiaria   = racionDiaria;
}

DtMascota::~DtMascota() {
}

string DtMascota::getNombre() const{
    return this->nombre;
}

Genero DtMascota::getGenero() const{
    return this->genero;
}

float DtMascota::getPeso() const{
    return this->peso;
}

float DtMascota::getRacionDiaria() const{
    return this->racionDiaria;
}