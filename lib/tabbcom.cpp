#include "../include/tabbcom.h"

using namespace std;

    // Constructor por defecto
    TNodoABB::TNodoABB (){
    }
    // Constructor de copia
    TNodoABB::TNodoABB (const TNodoABB &tnodoabb){
        this->item = tnodoabb.item;
        this->iz = tnodoabb.iz;
        this->de = tnodoabb.iz;
    }
    // Destructor
    TNodoABB::~TNodoABB (){
    }
    // Sobrecarga del operador asignación
    TNodoABB & TNodoABB::operator=(const TNodoABB &tnodoabb){
        if(this != &tnodoabb){
            (*this).~TNodoABB();
        }
        this->de = tnodoabb.de;
        this->item = tnodoabb.item; 
        this->iz = tnodoabb.iz;
        
        return *this;
    }
    // Constructor por defecto
    TABBCom::TABBCom (){
        this->nodo = NULL;
    }
    // Constructor de copia
    TABBCom::TABBCom (const TABBCom &tabbcom){
        Copiar(tabbcom);   
    }

    void TABBCom::Copiar(const TABBCom &origen) {
	if (!origen.EsVacio()) {
		this->nodo = new TNodoABB();
		this->nodo->item = origen.nodo->item;

		this->nodo->iz.Copiar(origen.nodo->iz);
		this->nodo->de.Copiar(origen.nodo->de);
	} else
		this->nodo = NULL;
    }

    // Destructor
    TABBCom::~TABBCom (){
        while (!this->EsVacio()) {
            this->nodo->iz.~TABBCom();
            this->nodo->de.~TABBCom();

            delete this->nodo;
            this->nodo = NULL;
        }
    }

    // Sobrecarga del operador asignación
    TABBCom & TABBCom::operator=(const TABBCom &tabbcom){
        if(!EsVacio()){
            this->~TABBCom();
        }
        this->Copiar(tabbcom);

        return (*this);
    }

    // Sobrecarga del operador igualdad
    bool TABBCom::operator==(const TABBCom &tabbcom){
        return (this->Inorden() == tabbcom.Inorden() ? true : false);
    }
    //Devuelve TRUE si es mayor que el item de dicho nodo
    bool TABBCom::EsMayor(const TComplejo &com){
        return (this->Raiz().Re() > com.Re()) ? true : false;
    }

    // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
    bool TABBCom::EsVacio() const{
        if (this->nodo)
		return false;
	else
		return true;
    }

    // Inserta el elemento en el árbol
    bool TABBCom::Insertar(const TComplejo &com){
        if(EsVacio()){
            this->nodo = new TNodoABB();
            this->nodo->item = com;
            return true;
        }

        if(this->EsMayor(com)){
            return this->nodo->de.Insertar(com);
        }
        else{
            return this->nodo->iz.Insertar(com);
        }
    }
    // Borra el elemento en el árbol
    bool TABBCom::Borrar(const TComplejo &com){
        if(Buscar(com)){
            if(this->Raiz() == com){
                this->~TABBCom();
                return true;
            }
            else if(Buscar(this->nodo->de.Raiz())){
                return this->Borrar(this->nodo->de.Raiz());
            }
            else if(Buscar(this->nodo->iz.Raiz())){
                return this->Borrar(this->nodo->iz.Raiz());
            }
        }
        return false;
    }

    // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
    bool TABBCom::Buscar(const TComplejo &tabbcom){
        if(EsVacio()) return false;
        if(this->Raiz() == tabbcom){
            return true;
        }
        else if(this->nodo->de.Buscar(tabbcom) || this->nodo->de.Buscar(tabbcom)){
            return true;
        }
        else{
            return false;
        }
    }

    // Devuelve el elemento en la raíz del árbol
    TComplejo TABBCom::Raiz() const{
        return this->nodo->item;
    }

    // Devuelve la altura del árbol (la altura de un árbol vacío es 0)
    int TABBCom::Altura(){
        return ((EsVacio() ? 0 : 1) + max(this->nodo->iz.Altura(), this->nodo->de.Altura()));
    }

    // Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
    int TABBCom::Nodos() const{
        if (this->nodo)
            return false;
        else
            return true;
    }

    // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
    int TABBCom::NodosHoja(){
        if(EsVacio()) return 0;

        if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){
            return 1;
        } 
        else {
            return this->nodo->de.NodosHoja() + this->nodo->iz.NodosHoja();
        }
    }

    // AUXILIAR : Devuelve el recorrido en inorden
    void TABBCom::InordenAux(TVectorCom &v, int &i) const{
        if(!this->EsVacio()){
            this->nodo->iz.InordenAux(v, i);
            i++;
            v[i] = Raiz();
            this->nodo->de.InordenAux(v, i);
        }
    }

    // Devuelve el recorrido en inorden
    TVectorCom TABBCom::Inorden() const{
        int i = 1;
        TVectorCom v(this->Nodos());
        this->InordenAux(v, i);
        return v;
    }

    // AUXILIAR : Devuelve el recorrido en preorden
    void TABBCom::PreordenAux(TVectorCom &v, int &i){
        if(!EsVacio()){
            i++;
            v[i] = Raiz();
            this->nodo->iz.PreordenAux(v, i);        
            this->nodo->de.PreordenAux(v, i);
        }    
    }

    // Devuelve el recorrido en preorden
    TVectorCom TABBCom::Preorden(){
        int i = 1;
        TVectorCom v (this->Nodos());
        this->PreordenAux(v, i);
        return v;
    }

    // AUXILIAR : Devuelve el recorrido en postorden
    void TABBCom::PostordenAux(TVectorCom &v, int &i){
        if(!EsVacio()){ 
            this->nodo->iz.PostordenAux(v, i);        
            this->nodo->de.PostordenAux(v, i);
            i++;
            v[i] = Raiz();
        }
    }

    // Devuelve el recorrido en postorden
    TVectorCom TABBCom::Postorden(){
        int i = 1;
        TVectorCom v(this->Nodos());
        this->PostordenAux(v, i);
        return v;
    }

    // Devuelve el recorrido en niveles
    TVectorCom TABBCom::Niveles(){
        int i = 1;
        queue<TABBCom> cola;
        TVectorCom v(this->Nodos());

        TABBCom abb = *this;
        cola.push(abb);
        
        while(!cola.empty()){
            v[i] = abb.nodo->item;
            abb = cola.front();
            
            if(!abb.nodo->iz.EsVacio())
                cola.push(abb.nodo->iz);

            if(!abb.nodo->de.EsVacio())
                cola.push(abb.nodo->de);
            i++;
        }
        return v;
    }
    
    // Sobrecarga del operador salida
    ostream & operator<<(ostream &s,const TABBCom &obj){
        TABBCom abb(obj);
        s << abb.Niveles();
        return s;
    }
