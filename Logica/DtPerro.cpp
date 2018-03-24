#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtMascota.h"
#include "Utils.h"
#include <iostream>

using std::cout;
using std::endl;

DtPerro::DtPerro(string nombre, Genero genero, float peso,  RazaPerro raza, bool vacunaCachorro) : DtMascota(nombre, genero, peso,  (float)(peso * 0.025)){
    this->raza           = raza;
    this->vacunaCachorro = vacunaCachorro;
}

DtPerro::~DtPerro(){}

RazaPerro DtPerro::getRazaPerro() const{
    return this->raza;
}

bool DtPerro::getVacunaCachorro() const{
    return this->vacunaCachorro;
}

ostream& operator << (ostream &o,const DtPerro &p){
    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Género: " << generoString(p.getGenero()) << endl;
    cout << "Peso: " << p.getPeso() << "kg" <<endl;
    cout << "Racion diaria: " << p.getRacionDiaria() << "gramos" << endl;
    cout << "Vacuna de cachorro: " << (p.getVacunaCachorro()? "SI" : "NO") << endl;
    cout << "Tipo pelo: " << razaPerroString(p.getRazaPerro()) << endl;
    
    return o;	
}
