#include "../Cabezales/Mascota.h"

using std::string;

Mascota::Mascota(string nombre, float peso, Genero genero){
	this->nombre 	= nombre;
	this->peso 		= peso;
	this->genero	= genero;
}

Genero Mascota::getGenero(){
    return this->genero;
}

void Mascota::setGenero(Genero genero){
    this->genero= genero;
}

string Mascota::getNombre(){
    return this->nombre;
}
void Mascota::setNombre(string nombre){
    this->nombre= nombre;
}

float Mascota::getPeso(){
    return this->peso;
}

void Mascota::setPeso(float peso){
    this->peso = peso;
}


 
