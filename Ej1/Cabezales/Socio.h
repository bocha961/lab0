#ifndef SOCIO_H
#define SOCIO_H

#include <string>
#include <vector>
#include "Mascota.h"
#include "Consulta.h"
#include "Fecha.h"

using std::string;

class Socio{
    private:
        string ci, nombre;
        Fecha fechaIngreso;
        Mascota *mascotas[10];
        Consulta *consultas[20];

    public
        Socio(string ci, string nombre);
        
        void setCI(string ci);
        string getCI();
        void setNombre(string nombre);
        string getNombre();
        void setFechaIngreso(Fecha fecha);
        Fecha getFechaIngreso();
        void setConsultas(Consulta* consultas);
        Consulta *getConsultas();        
        void setMascotas(Mascota *mascotas);
        Mascota *getMascota();
};



#endif