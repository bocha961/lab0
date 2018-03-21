#include "../Cabezales/Gato.h"
#include "../Cabezales/Mascota.h"
#include "../Cabezales/Utils.h"
Gato::Gato(string nombre, float peso, Genero genero, TipoPelo tipoPelo) : Mascota(nombre, peso, genero){
	this->tipoPelo = tipoPelo;
}
Gato::~Gato(){
	
}

float Gato::obtenerRacionDiaria(){
    return this->getPeso() * 0.015;
}

void Gato::setTipoPelo(TipoPelo pelo){
    this->tipoPelo= pelo;
}

TipoPelo Gato::getTipoPelo(){
    return this->tipoPelo;
}
