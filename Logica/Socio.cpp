#include <string>
#include <exception>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/Mascota.h"
#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtGato.h"
#include "../Cabezales/Perro.h"
#include "../Cabezales/Gato.h"

using std::string;
 
Socio::Socio(string ci, string nombre, DtFecha *fechaIngreso){
    this->ci = ci;
    this->nombre = nombre;
	this->fechaIngreso = fechaIngreso;
}
Socio::~Socio(){
	delete[] this->mascotas;
	delete[] this->consultas;
	delete this->fechaIngreso; // must be a pointer to a complete object type
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
 
void Socio::setFechaIngreso(DtFecha *fecha){
    this->fechaIngreso = fecha;
}
DtFecha Socio::getFechaIngreso(){
    return this->fechaIngreso;
}

void Socio::agregarConsulta(DtConsulta *datosConsulta){
	Consulta * nuevaConsulta = new Consulta(datosConsulta.getFecha(), datosConsulta.getMotivo());
	int posicionAgregar = this->consultas.size(); // Esto no funciona, no esta size implementado, falta un tope. 
	int capacidad = sizeof(this->consultas); // maximo del arreglo, lo cambie porque no funcionaba sino

	if(posicionAgregar < capacidad)
		this->consultas[posicionAgregar] = nuevaConsulta;
	else
		throw std::range_error("Maximo de consultas");
}
void Socio::setConsultas(Consulta* consultas){
    this->consultas = consultas; // must be a modifiable lvalue wtf??
}
Consulta* Socio::getConsultas(){
    return this->consultas; // return type does not match the function type
}

void Socio::agregarMascota(const DtMascota *datosMascota){
	int posicionAgregar = this->consultas.size();	
	int capacidad = this->consultas.max_size(); // idem agregarConsulta

	if(posicionAgregar < capacidad){
		DtPerro datosMascotaPerro	= dynamic_cast<DtPerro*>(datosMascota); // The operand of a pointer dynamic_cast must be a pointer to a complete class
		DtGato datosMascotaGato		= dynamic_cast<DtGato*>(datosMascota); // subraya en datosMascota, ni idea que es 

		Mascota* nuevaMascota;
		if(datosMascotaPerro != NULL){ // Esto no tiene sentido DtPerro != int hay que preguntar distinto.
			nuevaMascota = new Perro(	datosMascotaPerro.getNombre(),
												datosMascotaPerro.getPeso(),
												datosMascotaPerro.getGenero(),
												datosMascotaPerro.getRazaPerro(),
												datosMascotaPerro.getVacunaCachorro());
		}else{
			nuevaMascota = new Gato(	datosMascotaGato.getNombre(),
												datosMascotaGato.getPeso(),	
												datosMascotaGato.getGenero(),
												datosMascotaGato.getTipoPelo());
		}
		this->mascotas[posicionAgregar] = nuevaMascota;
	}else
		throw std::range_error("Maximo de mascotas");
}
void Socio::setMascotas(Mascota* mascotas){
    this->mascotas = mascotas; //must be a modifiable lvalue
}
Mascota* Socio::getMascotas(){
    return this->mascotas; //must be a modifiable lvalue
}
