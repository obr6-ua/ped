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
        if (this != &tabbcom) {
            this->~TABBCom();
            this->Copiar(tabbcom);
        }

        return *this;
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
        if(this->Buscar(com)) return false;

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
        // if(Buscar(com)){
        //     if(this->Raiz() == com){
        //         this->~TABBCom();
        //         return true;
        //     }
        //     else if(Buscar(this->nodo->de.Raiz())){
        //         return this->Borrar(this->nodo->de.Raiz());
        //     }
        //     else if(Buscar(this->nodo->iz.Raiz())){
        //         return this->Borrar(this->nodo->iz.Raiz());
        //     }
        // }
        // return false;
        bool borrado = false;

	if (this->Buscar(com)) {
		if (this->nodo->item == com) {
			if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {
				delete nodo;
				nodo = NULL;

				borrado = true;
			} else {
				if (this->nodo->iz.EsVacio() || this->nodo->de.EsVacio()) {
					if (this->nodo->iz.EsVacio()) { //Sin subarbol izq
						TNodoABB *aux;

						aux = nodo;
						nodo = nodo->de.nodo;
						aux->de.nodo = NULL;
						delete aux;
						aux = NULL;

						borrado = true;
					} else { //Sin subarbol der
						TNodoABB *aux;

						aux = nodo;
						nodo = nodo->iz.nodo;
						aux->iz.nodo = NULL;
						delete aux;
						aux = NULL;

						borrado = true;
					}
				} else { //Cuando tiene dos subarboles hijo.
					this->Sustituir();

					borrado = true;
				}
			}

			borrado = true;
		} else {
			if (this->EsMayor(com))
				borrado = this->nodo->de.Borrar(com);
			else
				borrado = this->nodo->iz.Borrar(com);
		}
	}

	return borrado;
    }

    void TABBCom::Sustituir() {
        TNodoABB *anterior, *posterior, *actual;

        actual = this->nodo;
        posterior = this->nodo->iz.nodo; //Tenemos que sustituir por algun nodo del subarbol iz
        anterior = this->nodo;

        if (posterior->de.EsVacio()) { //No hay subarbol der por lo tanto este es el mayor.
            actual->item = posterior->item;
            actual->iz.nodo = posterior->iz.nodo;
        } else { //Buscamos iterativamente el mayor de la ezquierda (estara en una hoja lo mas a la derecha posible).
            while (!posterior->de.EsVacio()) {
                anterior = posterior;
                posterior = posterior->de.nodo;
            }

            anterior->de.nodo = posterior->iz.nodo;
            actual->item = posterior->item;
        }
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
		return EsVacio() == true ? 0 : (1 + nodo->de.Nodos() + nodo->iz.Nodos());
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
        if (!this->EsVacio()) {
            if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){
                //Lo añado al vector y acabo recur
                v[i] = this->nodo->item;
                i++;
            } else {
                this->nodo->iz.InordenAux(v, i);
                v[i] = this->nodo->item;
                i++;
                this->nodo->de.InordenAux(v, i);
            }
        }
    }

    // Devuelve el recorrido en inorden
    TVectorCom TABBCom::Inorden() const
    {
        // Posición en el vector que almacena el recorrido 
        int posicion = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos 
        TVectorCom v(Nodos());
        InordenAux(v, posicion);
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
