#include <iostream>
#include <array>
#include "../Cabezales/Socilso.h"
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

        Socio *nuevoSocio = new Socio(ci, nombre);



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
    int tamanio = sizeof(coleccionSocios);
     
     //busca el indice donde esta el socio
     int i = BuscarSocio(ci,coleccionSocios);
     //aca va un try
     if(i<= tamanio){  //Si se encuentra el socio, se agrega su mascota
        DtConsulta consulta = new DtConsulta(fecha, motivo);
        coleccionSocios[i]->agregarConsulta(consulta);
        };

}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ciSocio, int& cantConsultas){
    int = buscarSocio(i)
    DtConsulta** arregloCons = new DtConsulta[cantConsultas];
        while( getFecha(coleccionSocios[i]->consultas[j]) < fecha ){
            //Hago una copia del arreglo hasta la fecha
            arregloCons[j] = new Consulta(coleccionSocios[i]->consultas[j].getFecha, coleccionSocios[i]->consultas[j].getMotivo())

        } // Hay que sobrecargar el operador < para comparar fechas



return arregloCons;

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

                        cout << "Ingrese datos de su perro";
                        //cargar datatype Perro
                        string nombre;
                        float peso;
                        Genero genero;
                        Raza raza;
                        bool vacuna;
                        //carga un DTPerro
                        DtPerro dataPerro = new DtPerro(nombre, peso, genero, raza, vacuna);
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
<<<<<<< HEAD
};
=======
}
>>>>>>> 0b615632ab6e03b6e34e0ffc78a25277f2124552
