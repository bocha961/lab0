#include <iostream>
#include <array>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/DtConsulta.h"
#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"
#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtFecha.h"
#include "../Cabezales/Gato.h"
#include "../Cabezales/Mascota.h"
#include "../Cabezales/Perro.h"
#include "../Cabezales/Utils.h"

const int MAX_SOCIOS = 100;
std::array <Socio, MAX_SOCIOS + 1> coleccionSocios;

void agregar_a_coleccion(Socio &agregar){

coleccionSocios->end() = agregar;


}

int BuscarSocio(string ci, array coleccion){
    int =0;
    while(i<=tamanio &&  coleccionSocios[i]->CI != ci )
        i++;
return i;
}

void agregarMascota(string ci, const DtMascota &dtMascota){
     //busco el socio en la coleccion
     int tamanio = sizeof(coleccionSocios);
     int i = 0;
     //busca el indice donde esta el socio
     int i = BuscarSocio(ci,coleccionSocios);
     //aca va un try
     if(i<= tamanio) //Si se encuentra el socio, se agrega su mascota
        coleccionSocios[i]->agregarMascota(dtMascota);


};


void registrarSocio(string ci, string nombre, const dtMascota &dtMascota){
        //Obtener fecha del sistema
        time_t t1;
        struct tm *tm_t2;

        time(&t1);
        tm_t2 = localtime(&t1);
        int dia = tm_t2->tm_mday;
        int mes = tm_t2->tm_mon;
        int anio = tm_t2->tm_year;
        DtFecha fechaIngreso = new DtFecha(dia, mes, anio);

        Socio *nuevoSocio = new Socio(ci, nombre, fechaIngreso);

        //Usar fecha del sistema (ni idea como gg ekide)

        //try
        //agrega la mascota al vector de mascotas
        nuevoSocio.agregarMascota(dtMascota);

        // Esta funcion deberia determinar si es Perro o Gato

        //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
        //deberia tener una operacion para agregar a la coleccion de socios
        agregar_a_coleccion(nuevoSocio);


};
void ingresarConsulta(string motivo, string ci){
    int tamanio = coleccionSocios.size();

     //busca el indice donde esta el socio
     int i = BuscarSocio(ci,coleccionSocios);
     //aca va un try
     if(i<= tamanio){  //Si se encuentra el socio, se agrega su mascota
        DtConsulta consulta = new DtConsulta(fecha, motivo);
        coleccionSocios[i].agregarConsulta(consulta);
        };

}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ciSocio, int& cantConsultas){
    int i = buscarSocio(ciSocio, coleccionSocios);
    int j = 0;
    DtConsulta** arregloCons = new DtConsulta[cantConsultas]; //arreglo que voy a devolver
    DtConsulta** consultasHechas = coleccionSocios[i].getConsultas();
        while( consultasHechas[j].getFecha() < fecha ){
            //Hago una copia del arreglo hasta la fecha
            arregloCons[j] = new Consulta(consultasHechas.getFecha(), consultasHechas.getMotivo())
            j++;

        } // Hay que sobrecargar el operador < para comparar fechas



    return arregloCons;

}
void eliminarSocio(string ci){
    int i = BuscarSocio(ci, coleccionSocios);
    //Usar destructor de Socio
    // Segun Santi esto llama a todo implicitamente
    delete coleccionSocios[i];
}

DtMascota** obtenerMascotas(string ci, int &cantMascotas){
    int i = BuscarSocio(ci, coleccionSocios);
    j=0;
    DtMascota** arregloMascotas = new DtMascotas[cantMascotas];
    DtMascota** mascotasExistentes = coleccionSocios[i].getMascotas();
    while(j < cantMascotas){
        arregloMascotas[j] = mascotasExistentes[j];
        j++;
    }
    return arregloMascotas;
}


int main(){

bool termino = false;
    int opcion;
    while (!termino){
        cout << " Bienvenido. Elija una opcion:\n";
        cout << " 1. Registrar socio\n";
        cout << " 2. Agregar mascota\n";
        cout << " 3. Insertar consulta\n";
        cout << " 4. Ver consultas antes de fecha\n";
        cout << " 5. Eliminar socio\n";
        cout << " 6. Ver mascotas de socio\n";
        cout << " 0. Salir\n";
        cout << "\n Opcion:";
        cin >> opcion;
        cout << "\033[2J\033[1;1H"; //Clear Screen
        switch (opcion){
            case 0:
                termino= true;
            break;
            case 1:
                cout << " 1 Agregar Perro\n";
                cout << " 2 Agregar Gato \n";
                int opcionMascota;
                cin >> opcionMascota;
                switch(opcionMascota){
                    case 1:
			cout << "Ingrese sus datos personales" << endl;
			cout << "Ingrese su nombre: ";			
			string nombreSocio;
			cin >> nombre;
			cout << "Ingrese su cedula de identidad";
			string ci;
			cin >> ci;		
			
                        cout << "Ingrese datos de su perro";
                        //cargar datatype Perro
                        string nombrePerro;
                        float peso;
                        Genero genero;
                        RazaPerro raza;
                        bool vacuna;
                        //carga un DTPerro
                        DtPerro *dataPerro = new DtPerro(nombrePerro, genero, peso, raza, 				vacuna);
                        registrarSocio(ci, nombre, dataPerro);
                    break;

                    case 2:

                        cout << "Ingrese datos de su gato";

                        //cargar datatype gato
                        DtGato dataGato = new DtGato(nombre, peso, genero, tipopelo);
                        registrarSocio(ci, nombre, dataGato);


                    break;
                }

            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            default: cout << " Ingrese una opcion correcta\n";
        }

    }










    return 0;
};
