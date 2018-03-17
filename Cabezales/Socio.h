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
<<<<<<< HEAD
        Socio(string ci, string nombre); 
=======
        Socio(string ci, string nombre);
		~Socio();

>>>>>>> 0b615632ab6e03b6e34e0ffc78a25277f2124552
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
