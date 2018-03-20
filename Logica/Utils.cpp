#include "../Cabezales/Utils.h"
#include <iostream>

using namespace std;

string generoString(Genero g){
    string res = "";
    switch(g){
        case hembra:
            res = "Hembra";
        break;
        case macho:
            res = "Macho";
        break;
    }
    return res;    
}

string razaPerroString(RazaPerro r){
    string res = "";
    switch(r){
        case labrador:
            res = "Labrador";
        break;
        case ovejero:
            res = "Ovejero";
        break;
        case bulldog:
            res = "Bulldog";
        break;
        case pitbull:
            res = "Pitbull";
        break;
        case collie:
            res = "Collie";
        break;
        case pekines:
            res = "Pekines";
        break;
        case otro:
            res = "Otro";
        break;
    }
    return res;        
}

string tipoPeloString(TipoPelo t){
    string res = "";
    switch(t){
        case corto:
            res = "Corto";
        break;
        case mediano:
            res = "Mediano";
        break;
    }
    return res;
}
