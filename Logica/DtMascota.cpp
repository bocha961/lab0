#include "../Cabezales/DtMascota.h"

void DataMascota::DataMascota(string nombre, Genero genero, float peso, float racionDiario){
    this.nombre         = nombre;
    this.genero         = genero;
    this.peso           = peso;
    this.racionDiario   = racionDiaria;
}

string DataMascota::getNombre(){
    return this.nombre;
}

Genero DataMascota::getGenero(){
    return this.genero;
}

float DataMascota::getPeso(){
    return this.peso;
}

float DataMascota::getRacionDiaria(){
    return this.racionDaria;
}