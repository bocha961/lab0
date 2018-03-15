#include <string>
#include "../Cabezales/Socio.h"
 
using std::string;
 
Socio::Socio(string ci, string nombre){
    this->ci = ci;
    this->nombre = nombre;
}
 
void Socio::setCI(string ci){
    thisci = ci;
} 
string Socio::getCI(){
    return this->ci;
}
 
void Socio::setNombre(string nombre){
    this->nombre = nombre;
}
string Socio::getNombre(){
    return this->nombre;
}
 
void Socio::setFechaIngreso(Fecha fecha){
    this->fechaIngreso = fecha;
}
Fecha Socio::getFechaIngreso(){
    return this->fechaIngreso;
}

void Socio::setConsultas(Consulta* consultas){
    this->consultas = consultas;
}
Consulta* Socio::getConsultas(){
    return this->consultas;
}

void Socio::setMascotas(Mascota* mascotas){
    this->mascotas = mascotas;
}
Mascota* Socio::getMascotas(){
    return this->mascotas;
}
