#include "../include/tvectorcom.h"

TVectorCom::TVectorCom(){
    c = NULL;
    this->tamano = 0;
}

TVectorCom::TVectorCom(int tam){
    if(tam<= 0){
        c = NULL;
        this->tamano = 0;
    }
    else{
        this->tamano = tam;
        this->c = new TComplejo [tam];
    }
}

TVectorCom::TVectorCom(const TVectorCom &v){
    if(v.tamano<= 0){
        c = NULL;
        this->tamano = 0;
    }
    else{
        this->tamano = tamano;
        this->c = new TComplejo [tamano];
    }
    for(int i=0;i<tamano;i++){
        this->c[i] = v.c[i];
    }
}

TVectorCom::~TVectorCom (){
    this->tamano = 0;
    if(this->c != NULL){
        delete [] c;
        this->c = NULL;
    }
}

TVectorCom & TVectorCom::operator=(const TVectorCom &v){
    //En caso de que se iguale el mismo objeto , devuelve el mismo
    if(this == &v){
        return *this;
    }
    else{
        (*this).~TVectorCom();
        if(v.tamano<= 0){
            c = NULL;
            this->tamano = 0;
        }
        else{
            this->tamano = tamano;
            this->c = new TComplejo [tamano];
        }
        for(int i=0;i<tamano;i++){
            this->c[i] = v.c[i];
        }
        return *this;
    }
}

bool TVectorCom::operator==(const TVectorCom &v){
    if(this->tamano != v.tamano)
        return false;
    else{
        for(int i = 0; i < this->tamano; i++){
            if(this->c[i] != v.c[i])
                return false;
        }
    }
    return true;
}

bool TVectorCom::operator!=(const TVectorCom &v){
    return !(*(this)==v);
}

TComplejo & TVectorCom::operator[](int tam){
    if(tam >= 1 && tam<=tamano){
        return this->c[tam-1];
    } 
    return error;
}

TComplejo TVectorCom::operator[](int tam) const{
    if(tam >= 1 && tam<=tamano){
        return this->c[tam-1];
    } 
    return error;
}

int TVectorCom::Tamano(){
    return tamano;
}

int TVectorCom::Ocupadas(){
    TComplejo t;
    int ocupadas = 0;

    for(int i=0; i<tamano;i++){
        if(this->c[i] != t){
            ocupadas++;
        }
    }
    return ocupadas;
}

bool TVectorCom::ExisteCom(const TComplejo &c){
    for(int i=0; i<tamano;i++){
        if(this->c[i] == c) return true;
    }
    return false;
}

void TVectorCom::MostrarComplejos(double re){
    for(int i=0; i<tamano;i++){
        if(this->c[i].Re() >= re) cout << this->c[i] << endl;
    }
}

bool TVectorCom::Redimensionar(int tam){
    if(tam<=this->tamano){
        return false;
    } 
    else{
        TVectorCom aux(*this);
        (*this).~TVectorCom();
        
        this->c = new TComplejo [tam];
        this->tamano = tam;

        return true;
    }

}

ostream & operator<<(ostream &s,const TVectorCom &v){
    s << "[(1) " << v.c[0] <<", ";
    if(v.tamano >2){
        for(int i=2;i<=v.tamano-1; i++){
            s << "(" << i << ") " << v.c[i-1] <<", "; 
        }
    }

    s << "("<<v.tamano << ") " << v.c[v.tamano-1] << "]";
    return s;
}