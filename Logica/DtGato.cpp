#include "../Cabezales/DtGato"

DtGato::DtGato(TipoPelo tipoPelo){
    this.tipoPelo = tipoPelo;
}

~DtGato(){}

TipoPelo DtGato::getTipoPelo(){
    return this->tipoPelo
}

