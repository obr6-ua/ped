#include "../include/tlistacom.h"

TListaNodo::TListaNodo(){
    e = TComplejo();
    this->anterior = NULL;
    this->siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &t){
    this->e = t.e;
    this->anterior = t.anterior;
    this->siguiente = t.siguiente;
}

TListaNodo::~TListaNodo (){
    this->e = TComplejo();
    if(this->anterior != NULL){
        delete [] anterior;
        this->anterior = NULL;
    }
    if(this->siguiente != NULL){
        delete [] siguiente;
        this->siguiente = NULL;
    }
}
    
TListaNodo & TListaNodo::operator=(const TListaNodo &t){
<<<<<<< HEAD

    e = this->e;
    this->anterior = t.anterior;
    this->siguiente = t.siguiente;

    return *this;
    
=======
    if(this==&t){
        return *this;
    }
    else{
        (*this).~TListaNodo();
        e = this->e;
        this->anterior = t.anterior;
        this->siguiente = t.siguiente;

        return *this;
    }
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14
}

// Constructor por defecto
TListaPos::TListaPos (){
    this->pos = NULL;
}
// Constructor de copia
TListaPos::TListaPos (const TListaPos &tpos){
    this->pos = tpos.pos;
}
// Destructor
TListaPos::~TListaPos (){
    delete [] pos;
    this->pos = NULL;
}
// Sobrecarga del operador asignación
TListaPos& TListaPos::operator=(const TListaPos &tpos){
    if(this==&tpos){
        return *this;
    }
    else{
        this->pos = tpos.pos;
    }
}

// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos &tpos){
    if(this->pos == tpos.pos){
        return true;
    }
    return false;
}
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos &tpos){
    return !((*this)==tpos);
}
// Devuelve la posición anterior
TListaPos TListaPos::Anterior(){
    TListaPos tpos;
<<<<<<< HEAD
    if(this->pos != NULL){
=======
    if(this->pos != NULL && this->pos->anterior != NULL){
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14
        tpos.pos = this->pos->anterior;
        return tpos;
    }
    return tpos;
}
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente(){
    TListaPos tpos;
<<<<<<< HEAD
    if(this->pos != NULL){
=======
    if(this->pos != NULL && this->pos->siguiente != NULL){
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14
        tpos.pos = this->pos->siguiente;
        return tpos;
    }
    return tpos;
}
// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPos::EsVacia(){
    if(this->pos == NULL){
        return true;
    }
    return false;
}

<<<<<<< HEAD
// Constructor por defecto
TListaCom::TListaCom::TListaCom (){
    this->primero = NULL;
    this->ultimo = NULL;
}
// Constructor de copia
TListaCom::TListaCom (const TListaCom &tlis){
    
}

// Destructor
TListaCom::~TListaCom (){
    if(this->primero != NULL){
        delete [] primero;
        this->primero = NULL;
    }
    if(this->ultimo != NULL){
        delete [] ultimo;
        this->ultimo = NULL;
    }
}
// Sobrecarga del operador asignación
TListaCom & TListaCom::operator=(const TListaCom &tlis){
    if(this==&tlis){
        return *this;
    }
    else{
        (*this).~TListaCom();
        // for(int i = 0;i < tlis.Longitud();i++){ 
        //     if( && =tpos.pos)
        // }
    }
}

// Sobrecarga del operador igualdad
bool TListaCom::operator==(const TListaCom &tlis){
    
}
// Sobrecarga del operador desigualdad
bool TListaCom::operator!=(const TListaCom &tlis){
    if((*this)==tlis) return false;
    else return true;
}
// Sobrecarga del operador suma
TListaCom TListaCom::operator+(const TListaCom &){

}
// Sobrecarga del operador resta
TListaCom TListaCom::operator-(const TListaCom &tlis){
    TListaNodo *aux;
    TListaCom tlisaux(*this);
    if(!tlis.primero == NULL && !tlis.ultimo == NULL){
        aux=tlis.primero;
        while(aux!=NULL){
            tlisaux.BorrarTodos(aux->e);
            aux=aux->siguiente;
        }
    }
    return tlisaux;
}
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCom::EsVacia(){
    if(this->primero == NULL && this->ultimo == NULL){
        return true;
    }
    return false;
}
// Inserta el elemento en la cabeza de la lista
bool TListaCom::InsCabeza(TComplejo &){

}
// Inserta el elemento a la izquierda de la posición indicada
bool TListaCom::InsertarI(TComplejo &, TListaPos &){

}
// Inserta el elemento a la derecha de la posición indicada
bool TListaCom::InsertarD(TComplejo &, TListaPos &){

}
// Busca y borra la primera ocurrencia del elemento
bool TListaCom::Borrar(TComplejo &t){
    for(int i = 0; i < this->Longitud();i++){
        if(this->Buscar(t)){
            return true;
        }
    }
    return false;
}
// Busca y borra todas las ocurrencias del elemento
bool TListaCom::BorrarTodos(TComplejo &t){
    for(int i = 0; i < this->Longitud();i++){
        if(this->Buscar(t)){
            return true;
        }
    }
}
// Borra el elemento que ocupa la posición indicada
bool TListaCom::Borrar(const TListaPos &){

}
// Obtiene el elemento que ocupa la posición indicada
TComplejo TListaCom::Obtener(const TListaPos &tpos){
    TListaNodo *aux;
    TComplejo c;
    if(!this->EsVacia() && tpos.pos == NULL ){
        aux=primero;
        while(aux!=NULL && aux!=tpos.pos){
            aux=aux->siguiente;
        }
        if(aux!=NULL && aux == tpos.pos){
            c=aux->e;
        }
    }
    return c;
}
// Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaCom::Buscar(const TComplejo &c){
    TListaNodo *aux;
    if(!this->EsVacia()){
        aux=primero;
        while((aux!=NULL)&&(aux->e!=c)){
            aux=aux->siguiente;
        }
        if(aux=NULL) return false;
        else return true;
    }
    return false;
}
// Devuelve la longitud de la lista
int TListaCom::Longitud(){
    int pos=0;
    TListaNodo *aux;
    aux=primero;
    while(aux!=NULL){
        pos++;
        aux=aux->siguiente;
    }
    return pos;
}
// Devuelve la primera posición en la lista
TListaPos TListaCom::Primera(){
    TListaPos pos;
    if(!this->EsVacia()) pos.pos=primero;
    return pos;
}
// Devuelve la última posición en la lista
TListaPos TListaCom::Ultima(){
    TListaPos res;
    if(!this->EsVacia()) res.pos=ultimo;
    return res;
} 

// Sobrecarga del operador salida
ostream & operator<<(ostream &,const TListaCom &){

}
=======
        // Constructor por defecto
        TListaCom::TListaCom::TListaCom (){
            this->primero = NULL;
            this->ultimo = NULL;
        }
        // Constructor de copia
        TListaCom::TListaCom (const TListaCom &tlis){
            this->primero = tlis.primero;
            this->ultimo = tlis.ultimo;
        }
        // Destructor
        TListaCom::~TListaCom (){
            if(this->primero != NULL){
                delete [] primero;
                this->primero = NULL;
            }
            if(this->ultimo != NULL){
                delete [] ultimo;
                this->ultimo = NULL;
            }
        }
        // Sobrecarga del operador asignación
        TListaCom & TListaCom::operator=(TListaCom &tlis){
            if(this==&tlis){
                return *this;
            }
            else{
                (*this).~TListaCom();
                for(int i = 0;i < tlis.Longitud();i++){ 
                    this->Insertar(i.pos->c);
                }
            }
        }

        // Sobrecarga del operador igualdad
        bool TListaCom::operator==(const TListaCom &tlis){
            this.
        }
        // Sobrecarga del operador desigualdad
        bool TListaCom::operator!=(const TListaCom &){

        }
        // Sobrecarga del operador suma
        TListaCom TListaCom::operator+(const TListaCom &){

        }
        // Sobrecarga del operador resta
        TListaCom TListaCom::operator-(const TListaCom &){

        }
        // Devuelve true si la lista está vacía, false en caso contrario
        bool TListaCom::EsVacia(){
            if(this->primero == NULL && this->ultimo == NULL){
                return true;
            }
            return false;
        }
        // Inserta el elemento en la cabeza de la lista
        bool TListaCom::InsCabeza(TComplejo &){

        }
        // Inserta el elemento a la izquierda de la posición indicada
        bool TListaCom::InsertarI(TComplejo &, TListaPos &){

        }
        // Inserta el elemento a la derecha de la posición indicada
        bool TListaCom::InsertarD(TComplejo &, TListaPos &){

        }
        // Busca y borra la primera ocurrencia del elemento
        bool TListaCom::Borrar(TComplejo &t){
            for(int i = 0; i < this->Longitud();i++){
                if(this->Buscar(t)){
                    return true;
                }
            }
            return false;
        }
        // Busca y borra todas las ocurrencias del elemento
        bool TListaCom::BorrarTodos(TComplejo &t){
            for(int i = 0; i < this->Longitud();i++){
                if(this->Buscar(t)){
                    return true;
                }
            }
        }
        // Borra el elemento que ocupa la posición indicada
        bool TListaCom::Borrar(TListaPos &){

        }
        // Obtiene el elemento que ocupa la posición indicada
        TComplejo TListaCom::Obtener(TListaPos &){

        }
        // Devuelve true si el elemento está en la lista, false en caso contrario
        bool TListaCom::Buscar(TComplejo &){

        }
        // Devuelve la longitud de la lista
        int TListaCom::Longitud(){
                
        }
        // Devuelve la primera posición en la lista
        TListaPos TListaCom::Primera(){

        }
        // Devuelve la última posición en la lista
        TListaPos TListaCom::Ultima(){

        } 

        // Sobrecarga del operador salida
        ostream & operator<<(ostream &, TListaCom &){

        }
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14
