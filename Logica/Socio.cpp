#include <string>
#include <exception>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/Mascota.h"

using std::string;
 
Socio::Socio(string ci, string nombre, DtFecha fechaIngreso){
    this->ci = ci;
    this->nombre = nombre;
	this->fechaIngreso = fechaIngreso;
}
Socio::~Socio(){
	delete[] this->mascotas;
	delete[] this->consultas;
	delete this->fechaIngreso;
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
	int posicionAgregar = this->consultas.size();	
	int capacidad = this->consultas.max_size();

	if(posicionAgregar < capacidad)
		this->consultas[posicionAgregar] = nuevaConsulta;
	else
		throw std::range_error("Maximo de consultas");
}
void Socio::setConsultas(Consulta* consultas){
    this->consultas = consultas;
}
Consulta* Socio::getConsultas(){
    return this->consultas;
}

void Socio::agregarMascota(DtMascota datosMascota){
	int posicionAgregar = this->consultas.size();	
	int capacidad = this->consultas.max_size();

	if(posicionAgregar < capacidad){
		DtPerro datosMascotaPerro	= dynamic_cast<DtPerro*>(datosMascota);
		DtGato datosMascotaGato		= dynamic_cast<DtGato*>(datosMascota);

		if(datosMascotaPerro != NULL){
			Mascota nuevaMascota = new Perro(	datosMascotaPerro.getNombre(),
												datosMascotaPerro.getPeso(),
												datosMascotaPerro.getGenero(),
												datosMascotaPerro.getRazaPerro(),
												datosMascotaPerro.getVacunaCachorro());
		}else{
			Mascota nuevaMascota = new Gato(	datosMascotaPerro.getNombre(),
												datosMascotaPerro.getPeso(),
												datosMascotaPerro.getGenero(),
												datosMascotaPerro.getTipoPelo());
		}
		this->mascotas[posicionAgregar] = nuevaMascota;
	}else
		throw std::range_error("Maximo de mascotas");
}
void Socio::setMascotas(Mascota* mascotas){
    this->mascotas = mascotas;
}
Mascota* Socio::getMascotas(){
    return this->mascotas;
}
