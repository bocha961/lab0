#ifndef SOCIO_H
#define SOCIO_H

#include <string>
#include "Mascota.h"
#include "Consulta.h"
#include "DtFecha.h"

using std::string;

class Socio{
    private:
        string ci, nombre;
        DtFecha fechaIngreso;
        Mascota *mascotas[10];
        Consulta *consultas[20];

    public:
        Socio(string ci, string nombre);
		~Socio();

        void setCI(string ci);
        string getCI();
        void setNombre(string nombre);
        string getNombre();
        void setFechaIngreso(DtFecha fecha);
        DtFecha getFechaIngreso();
		void agregarConsulta(DtConsulta nuevaConsulta);
        void setConsultas(Consulta* consultas);
        Consulta *getConsultas();
		void agregarMascota(DtMascota nuevaMascota);
        void setMascotas(Mascota *mascotas);
        Mascota *getMascotas();
};



#endif
