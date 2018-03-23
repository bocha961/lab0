#include <iostream>
#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"
#include "Utils.h"

using namespace std;

DtGato::DtGato(string nombre, Genero genero, float peso,  TipoPelo tipoPelo) : DtMascota(nombre, genero, peso, (float)(peso * 0.015)){
    this->tipoPelo = tipoPelo;
}
DtGato::~DtGato(){}

TipoPelo DtGato::getTipoPelo() const{
    return this->tipoPelo;
}

ostream& operator << (ostream &o,const DtGato &p){
    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Género: " << generoString(p.getGenero()) << endl;
    cout << "Peso: " << p.getPeso() << "kg" <<endl;
    cout << "Racion diaria: " << p.getRacionDiaria() << "gramos" << endl;
    cout << "Tipo de pelo: " << tipoPeloString(p.getTipoPelo()) << endl;
            
    return o;
}