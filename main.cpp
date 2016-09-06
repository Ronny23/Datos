// Implementacion del arbol binario de busqueda (Binary Search Tree (BST)), con el metodo de insertar

#include<iostream>

#include <chrono>

using namespace std;
//Definicion del nodo para el arbol binario de busqueda
struct BstNode {
	int dato;
	BstNode* izquierda;
	BstNode* derecha;
};

// Funcion para crear un nuevo nodo en el heap
BstNode* GetnuevoNodo(int dato) {
	BstNode* nuevoNodo = new BstNode();
	nuevoNodo->dato = dato;
	nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
	return nuevoNodo;
}

// Inserta datos en el BST, devuelve la dirección del nodo raíz
BstNode* Insertar(BstNode* raiz,int dato) {
	if(raiz == NULL) { // empty tree
		raiz = GetnuevoNodo(dato);
	}
	// si el dato a insertar es menor, lo insert en la izquierda del subarbol.
	else if(dato <= raiz->dato) {
		raiz->izquierda = Insertar(raiz->izquierda,dato);
	}
	// sino lo inserta a la derecha del subarbol
	else {
		raiz->derecha = Insertar(raiz->derecha,dato);
	}
	return raiz;
}


/* devuelve la diferencia de tiempo de "initiempo y endtiempo" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b){
    return
            (double)(a->tv_sec + (double)a->tv_usec/1000000) -
            (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main() {
    BstNode* raiz = NULL;  // Creating an empty tree
    int cantidad, numero;
    cout<<"Digite la cantidad de numeros a insertar en el BST: ";
    cin>>cantidad;

    srand(time(NULL));

    struct timeval iniTiempo, endTiempo;

    auto inicio = chrono::high_resolution_clock::now();
    for(int i=0;i<cantidad;i++){
        numero = 1+rand()%(101-1); //obtiene un numero aleatorio entre 1 y 10
        raiz = Insertar(raiz,numero);
    }
    auto ending = std::chrono::high_resolution_clock::now();
    std::cout
            << std::chrono::duration_cast<std::chrono::milliseconds>(ending-inicio).count() << "ns, con: "
            <<(cantidad) << " elementos" << std::endl;
    cout<< endl;


}