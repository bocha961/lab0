#include <iostream>
#include <array>
#include <ctime>
#include <string>
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
#include <typeinfo>

using namespace std;

const int MAX_SOCIOS = 100;

struct coleccionSocios {
    Socio *arraySocios[MAX_SOCIOS];
    int tope;
};

typedef coleccionSocios *coleSocios;

coleSocios crearColeSocios() {
    coleSocios res = new coleccionSocios();
    res->tope = 0;
    return res;
}

//Arreglo auxiliar
coleSocios socios;

void agregar_a_coleccion(Socio *agregar) {
    if (socios->tope < MAX_SOCIOS) {
        socios->arraySocios[socios->tope] = agregar;
        socios->tope++;
    }
}

int buscarSocio(string ci) {
    int i = 0;
    while (i < socios->tope  &&  socios->arraySocios[i]->getCI().compare(ci) != 0 )
        i++;
    if(i < socios->tope)
        return i;
    else
        throw invalid_argument("Usuario no existente");
}

void agregarMascota(string ci, const DtMascota &dtMascota) {
    //busco el socio en la coleccion
    int tamanio = MAX_SOCIOS;
    DtMascota *mascotaAux = (DtMascota *)&dtMascota;
    //int i = 0;
    //busca el indice donde esta el socio
    int i = buscarSocio(ci);
    //aca va un try
    if (i < tamanio) //Si se encuentra el socio, se agrega su mascota
        socios->arraySocios[i]->agregarMascota(mascotaAux);
}


void registrarSocio(string ci, string nombre, const DtMascota &dtMascota) { //aca?
    //Obtener fecha del sistema
    time_t t1;
    struct tm *tm_t2;

    time(&t1);
    tm_t2 = localtime(&t1);
    int dia = tm_t2->tm_mday;
    int mes = tm_t2->tm_mon;
    int anio = tm_t2->tm_year;
    DtFecha *fechaIngreso = new DtFecha(dia, mes + 1, anio + 1900);

    Socio *nuevoSocio = new Socio(ci, nombre, fechaIngreso);

    DtMascota *mascotaAux = (DtMascota *)&dtMascota;

    //try
    //agrega la mascota al vector de mascotas
    nuevoSocio->agregarMascota(mascotaAux);

    // Esta funcion deberia determinar si es Perro o Gato

    //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
    //deberia tener una operacion para agregar a la coleccion de socios
    agregar_a_coleccion(nuevoSocio);
}


void ingresarConsulta(string motivo, string ci) {
    int tamanio = socios->tope;
    //busca el indice donde esta el socio
    /*
     CREAR FUNCION OBTENER FECHA
     */

    int i = buscarSocio(ci);

    time_t t1;
    struct tm *tm_t2;

    time(&t1);
    tm_t2 = localtime(&t1);
    int dia = tm_t2->tm_mday;
    int mes = tm_t2->tm_mon;
    int anio = tm_t2->tm_year;
    DtFecha *fecha = new DtFecha(dia, mes + 1, anio + 1900);
    //aca va un try
    if (i < tamanio) { //Si se encuentra el socio, se agrega su mascota
        DtConsulta *consulta = new DtConsulta(fecha, motivo);
        socios->arraySocios[i]->agregarConsulta(consulta);
    }

}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ciSocio, int& cantConsultas) {
    int i = buscarSocio(ciSocio);
    int j = 0;
    if(cantConsultas > socios->arraySocios[i]->getTopeConsultas())
        cantConsultas = socios->arraySocios[i]->getTopeConsultas();
    
    DtConsulta **arregloRes = new DtConsulta *[cantConsultas]; //arreglo que voy a devolver
    for(int k=0; k < cantConsultas; k++){
        arregloRes[k]= NULL;
    }
    Consulta **consultasHechas = socios->arraySocios[i]->getConsultas();//arreglo de todas las consultas hechas
    DtFecha *fechaAux = (DtFecha *)&fecha;

    while (j < cantConsultas && consultasHechas[j]->getFecha() < fechaAux) {
        //Hago una copia del arreglo hasta la fecha
        //Esto esta Mal ya que no son tipos compatibles
        arregloRes[j] = new DtConsulta(consultasHechas[j]->getFecha(), consultasHechas[j]->getMotivo());
        j++;

    }
    return arregloRes;
}
void eliminarSocio(string ci) {
    int i = buscarSocio(ci);
    //Usar destructor de Socio
    // Segun Santi esto llama a todo implicitamente
    Socio *socioAux = socios->arraySocios[i];
    socios->arraySocios[i] = socios->arraySocios[socios->tope - 1];
    delete socioAux;
    socios->tope--;
}

DtMascota** obtenerMascotas(string ci, int &cantMascotas) {
    int i = buscarSocio(ci);
    int j = 0;
    if(cantMascotas > socios->arraySocios[i]->getTopeMascotas())
        cantMascotas = socios->arraySocios[i]->getTopeMascotas();
    
    DtMascota **arregloMascota = new DtMascota*[cantMascotas];
    Mascota **mascotasExistentes = socios->arraySocios[i]->getMascotas();
    Perro *datosMascotaPerro;
    Gato *datosMascotaGato;
    while (j < cantMascotas) { // trabajar con tope
        datosMascotaPerro = dynamic_cast<Perro*>(mascotasExistentes[j]); // The operand of a pointer dynamic_cast must be a pointer to a complete class
        datosMascotaGato = dynamic_cast<Gato*>(mascotasExistentes[j]);
        if (datosMascotaPerro != NULL)
            arregloMascota[j] = new DtPerro(datosMascotaPerro->getNombre(), datosMascotaPerro->getGenero(), datosMascotaPerro->getPeso(), datosMascotaPerro->getRazaPerro(),
                                            datosMascotaPerro->getVacunaCachorro());
        else if(datosMascotaGato != NULL)
            arregloMascota[j] = new DtGato(datosMascotaGato->getNombre(), datosMascotaGato->getGenero(), datosMascotaGato->getPeso(), datosMascotaGato->getTipoPelo());
        j++;
    }
    return arregloMascota;
}

void insertarSocio() {
    cout << "Ingrese datos personales" << endl;
    cout << "Ingrese el nombre del socio: ";
    string nombreSocio;
    cin.ignore();
    getline(cin, nombreSocio);
   
    cout << "Ingrese la cedula de identidad(sin espacios):";
    string ci;
    cin >> ci;
    
    
    cout << "Ingrese datos de la mascota\n";
    cout << "   Nombre:";
    string nombreMascota;
    cin.ignore();
    getline(cin, nombreMascota);
    
    cout << "   Peso:";
    string pesoEntrada;
    cin >> pesoEntrada;
    float peso = stof(pesoEntrada, NULL);
    
    cout << "   Genero:\n";
    cout << "   1. Macho\n";
    cout << "   2. Hembra\n";
    int opcionGenero;
    cin >> opcionGenero;
    Genero genero;
    switch (opcionGenero) {
    case 1:
        genero = macho;
        break;
    case 2:
        genero = hembra;
        break;
        default:
            throw invalid_argument("Genero invalido");
            break;
    }
    
    cout << "   Identifique a la mascota:\n";
    cout << "   1. Perro\n";
    cout << "   2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1: {
        //cargar datatype Perro
        cout << "   Ingrese la raza del perro:\n";
        cout << "   0. Labrador\n";
        cout << "   1. Ovejero\n";
        cout << "   2. Bulldog\n";
        cout << "   3. Pitbull\n";
        cout << "   4. Collie\n";
        cout << "   5. Pekines\n";
        cout << "   6. Otro\n";
        int opcionRaza;
        cin >> opcionRaza;
        RazaPerro raza;
        switch (opcionRaza) {
        case 0:
            raza = labrador;
            break;
        case 1:
            raza = ovejero;
            break;
        case 2:
            raza = bulldog;
            break;
        case 3:
            raza = pitbull;
            break;
        case 4:
            raza = collie;
            break;
        case 5:
            raza = pekines;
            break;
        case 6:
            raza = otro;
            break;
        default:
            throw invalid_argument("Genero invalido");
            break;
        }
        cout << "   Esta vacunado?\n";
        cout << "   0. Falso\n";
        cout << "   1. Verdadero\n";
        int opcionVacuna;
        cin >> opcionVacuna;
        bool vacuna;
        switch (opcionVacuna) {
        case 0:
            vacuna= false;
            break;
        case 1:
            vacuna= true;
            break;
        default:
            throw invalid_argument("Opcion invalida");
            break;
        }


        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, genero, peso, raza, vacuna);
        const DtPerro auxPerro = *dataPerro;
        registrarSocio(ci, nombreSocio, auxPerro);
        break;
    }

    case 2:{

        cout << "   Ingrese el tipo de pelo del gato:\n";
        cout << "   1. Corto\n";
        cout << "   2. Mediano\n";
        cout << "   3. Largo\n";
        int opcionPelo;
        cin >> opcionPelo;
        TipoPelo tipoPelo;
        switch (opcionPelo) {
        case 1:
            tipoPelo = corto;
            break;
        case 2:
            tipoPelo = mediano;
            break;
        case 3:
            tipoPelo = largo;
            break;
        default:
            throw invalid_argument("Pelo invalido");
            break;
        }

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, genero, peso, tipoPelo);
        const DtGato auxGato = *dataGato;
        registrarSocio(ci, nombreSocio, auxGato);
        break;
    }
    default:
            throw invalid_argument("Identidad invalido");
            break;
    }
}

void insertarMascota() {
cout << "Ingrese la cedula de identidad(sin espacios):";
    string ci;
    cin >> ci;
    
    
    cout << "Ingrese datos de la mascota\n";
    cout << "   Nombre:";
    string nombreMascota;
    cin.ignore();
    getline(cin, nombreMascota);
    
    cout << "   Peso:";
    string pesoEntrada;
    cin >> pesoEntrada;
    float peso = stof(pesoEntrada, NULL);
    
    cout << "   Genero:\n";
    cout << "   1. Macho\n";
    cout << "   2. Hembra\n";
    int opcionGenero;
    cin >> opcionGenero;
    Genero genero;
    switch (opcionGenero) {
    case 1:
        genero = macho;
        break;
    case 2:
        genero = hembra;
        break;
        default:
            throw invalid_argument("Genero invalido");
            break;
    }
    
    cout << "   Identifique a la mascota:\n";
    cout << "   1. Perro\n";
    cout << "   2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1: {
        //cargar datatype Perro
        cout << "   Ingrese la raza del perro:\n";
        cout << "   0. Labrador\n";
        cout << "   1. Ovejero\n";
        cout << "   2. Bulldog\n";
        cout << "   3. Pitbull\n";
        cout << "   4. Collie\n";
        cout << "   5. Pekines\n";
        cout << "   6. Otro\n";
        int opcionRaza;
        cin >> opcionRaza;
        RazaPerro raza;
        switch (opcionRaza) {
        case 0:
            raza = labrador;
            break;
        case 1:
            raza = ovejero;
            break;
        case 2:
            raza = bulldog;
            break;
        case 3:
            raza = pitbull;
            break;
        case 4:
            raza = collie;
            break;
        case 5:
            raza = pekines;
            break;
        case 6:
            raza = otro;
            break;
        default:
            throw invalid_argument("Genero invalido");
            break;
        }
        cout << "   Esta vacunado?\n";
        cout << "   0. Falso\n";
        cout << "   1. Verdadero\n";
        int opcionVacuna;
        cin >> opcionVacuna;
        bool vacuna;
        switch (opcionVacuna) {
        case 0:
            vacuna= false;
            break;
        case 1:
            vacuna= true;
            break;
        default:
            throw invalid_argument("Opcion invalida");
            break;
        }


        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, genero, peso, raza, vacuna);
        const DtPerro auxPerro = *dataPerro;
        agregarMascota(ci, auxPerro);
        break;
    }

    case 2:{

        cout << "   Ingrese el tipo de pelo del gato:\n";
        cout << "   1. Corto\n";
        cout << "   2. Mediano\n";
        cout << "   3. Largo\n";
        int opcionPelo;
        cin >> opcionPelo;
        TipoPelo tipoPelo;
        switch (opcionPelo) {
        case 1:
            tipoPelo = corto;
            break;
        case 2:
            tipoPelo = mediano;
            break;
        case 3:
            tipoPelo = largo;
            break;
        default:
            throw invalid_argument("Pelo invalido");
            break;
        }

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, genero, peso, tipoPelo);
        const DtGato auxGato = *dataGato;
        agregarMascota(ci, auxGato);
        break;
    }
    default:
            throw invalid_argument("Identidad invalido");
            break;
    }

}

void insertarConsulta() {
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la consulta:";
    string consulta;
    cin.ignore();
    getline(cin, consulta);
    ingresarConsulta(consulta, ci);
}

void verConsultas() {
    cout << "Ingrese la fecha que quiera ver las consultas realizas hasta entonces" << endl;
    cout << "Dia:";
    string diaEntrada;
    cin >> diaEntrada;
    int dia = stoi(diaEntrada, NULL);
    cout << "Mes:";
    string mesEntrada;
    cin >> mesEntrada;
    int mes = stoi(mesEntrada, NULL);
    cout << "Anio:";
    string anioEntrada;
    cin >> anioEntrada;
    int anio = stoi(anioEntrada, NULL);
    DtFecha *fecha = new DtFecha(dia, mes, anio);
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de consultas que desea ver:";
    string cantEntrada;
    cin >> cantEntrada;
    int cant = stoi(cantEntrada, NULL);
    DtConsulta** lista = verConsultasAntesDeFecha(*fecha, ci, cant);
        
    int k= 1;
    int i = 0;
    while (i < cant && cant != 0) {
        //DtFecha *fecha_i = lista[i]->getFecha();
        int dia_i = lista[i]->getFecha()->getDia();
        int mes_i = lista[i]->getFecha()->getMes();
        int anio_i = lista[i]->getFecha()->getAnio();
        cout << "Consulta " << k << " fecha:" << dia_i << "/" << mes_i << "/" << anio_i << endl;
        cout << "Motivo: " << lista[i]->getMotivo() << endl;
        
        i++;
        k++;
    }
    cout << "<< Ingrese 0/1 para continuar >>\n";
    bool finish;
    cin >> finish;
}

void verMascotas() {
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de mascotas que desea ver:";
    int cant;
    cin >> cant;
    DtMascota** lista = obtenerMascotas(ci, cant);
    DtPerro* datosMascotaPerro;
    DtGato* datosMascotaGato;
    for(int i = 0; i < cant; i++){
        datosMascotaPerro = dynamic_cast<DtPerro*>(lista[i]); // The operand of a pointer dynamic_cast must be a pointer to a complete class
        datosMascotaGato = dynamic_cast<DtGato*>(lista[i]);
        
        cout << "Mascota #" << i + 1;
        if (datosMascotaPerro != NULL)
            cout << *datosMascotaPerro;
        else if(datosMascotaGato != NULL)
            cout << *datosMascotaGato;
    }  
    cout << "<< Ingrese 0/1 para continuar >>\n";
    bool finish;
    cin >> finish;
}

void removerSocio() {
    cout << "Ingrese la cedula de identidad del socio que desea eliminar:";
    string ci;
    cin >> ci;
    eliminarSocio(ci);
}

int main() {
    socios = crearColeSocios();
    string error;
    bool termino = false;
    int opcion;
    while (!termino) {
        cout << "\033[2J\033[1;1H"; //Clear Screen
        cout << " Bienvenido. Elija una opcion:\n";
        cout << " 1. Registrar socio\n";
        cout << " 2. Agregar mascota\n";
        cout << " 3. Insertar consulta\n";
        cout << " 4. Ver consultas antes de fecha\n";
        cout << " 5. Ver mascotas de socio\n";
        cout << " 6. Eliminar socio\n";
        cout << " 0. Salir\n" << endl;
        cout << error ;
        error= "";
        cout << "\n Opcion:";
        cin >> opcion;
        cout << "\033[2J\033[1;1H"; //Clear Screen

        switch (opcion) {
        case 0:
            termino = true;
            break;
        case 1:
            try{
                insertarSocio();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " Valor invalido";                        
            }
            break;
        case 2:
            try{
                insertarMascota();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " Valor invalido";                        
            }
            break;
        case 3:
            try{
                insertarConsulta();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " CI no registrada";                        
            }
            break;
        case 4:
            try{
            verConsultas();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " CI no registrada";                        
            }
            break;
        case 5:
            try{
            verMascotas();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " CI no registrada";                        
            }
            break;
        case 6:
            try{
            removerSocio();
            }
            catch(invalid_argument e){
                cout << "\033[2J\033[1;1H"; //Clear Screen
                error = " CI no registrada";                        
            }
            break;
        default: cout << " Ingrese una opcion correcta\n";
        }
        
    }

    return 0;
};