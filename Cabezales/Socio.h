#ifndef SOCIO_H
#define SOCIO_H

#include <string>
#include <vector>
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
        void setConsultas(Consulta* consultas);
        Consulta *getConsultas();
        void setMascotas(Mascota *mascotas);
        Mascota *getMascota();
};



#endif
