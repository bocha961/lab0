#include <string>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/Mascota.h"

using std::string;
 
Socio::Socio(string ci, string nombre){
    this->ci = ci;
    this->nombre = nombre;
}
Socio::~Socio(){
	delete[] this->mascotas;
	delete[] this->consultas;
}
 
void Socio::setCI(string ci){
    this->ci = ci;
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
 
void Socio::setFechaIngreso(DtFecha fecha){
    this->fechaIngreso = fecha;
}
DtFecha Socio::getFechaIngreso(){
    return this->fechaIngreso;
}

void Socio::agregarConsulta(DtConsulta datosConsulta){
	Consulta nuevaConsulta = new Consulta(datosConsulta.getFecha(), datosConsulta.getMotivo());
	
	

}
void Socio::setConsultas(Consulta* consultas){
    this->consultas = consultas;
}
Consulta* Socio::getConsultas(){
    return this->consultas;
}

void Socio::agregarMascota(DtMascota datosMascota){

}
void Socio::setMascotas(Mascota* mascotas){
    this->mascotas = mascotas;
}
Mascota* Socio::getMascotas(){
    return this->mascotas;
}
