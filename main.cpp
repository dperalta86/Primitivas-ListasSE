#include <iostream>
using namespace std;

struct NodoListaSE {
    int info;
    NodoListaSE* sgte = nullptr;
};

void insertarNodoAlPrincipio(NodoListaSE*& lista, int dato);
void insertarNodoAlFinal(NodoListaSE*& lista, int dato);
void mostrarLista(NodoListaSE* lista);
void borrarPrimero(NodoListaSE*& lista);
void borrarUltimo(NodoListaSE*& lista);

int main() {
    NodoListaSE* lista = nullptr;

    cout << " ### Carga inicial de la lista ###" << endl << endl;
    insertarNodoAlPrincipio(lista, 98);
    insertarNodoAlPrincipio(lista, 97);
    insertarNodoAlPrincipio(lista, 96);
    insertarNodoAlFinal(lista, 121);
    insertarNodoAlFinal(lista, 122);
    insertarNodoAlFinal(lista, 123);
    mostrarLista(lista);

    cout << "Borro primer elemento de la lista..." << endl;
    borrarPrimero(lista);
    mostrarLista(lista);

    cout << "Borro ultimo elemento de la lista.." << endl;
    borrarUltimo(lista);
    mostrarLista(lista);

    return 0;
}

void insertarNodoAlPrincipio(NodoListaSE*& lista, int dato) {
    NodoListaSE* aux;
    aux = lista;
    lista = new NodoListaSE();
    lista->info = dato;
    lista->sgte = aux;
    return;
}

void insertarNodoAlFinal(NodoListaSE*& lista, int dato) {
    NodoListaSE* aux = nullptr;
    if(!lista) {
        lista = new NodoListaSE ();
        lista->info = dato;
        lista->sgte = nullptr;
    }
    else {
        aux = lista;
        while (aux->sgte != nullptr)
            aux = aux->sgte;
        aux->sgte = new NodoListaSE();
        aux = aux->sgte;
        aux->info = dato;
        aux->sgte = nullptr;
    }
    return;
}

void borrarPrimero(NodoListaSE*& lista) {
    if (lista != nullptr) {
        NodoListaSE* aux = lista;
        lista = lista->sgte; //Acá SI necesito modificar puntero inicial!
        delete aux;
    }
    return;
}

void borrarUltimo(NodoListaSE*& lista) {
    NodoListaSE* ultimo = lista;
    NodoListaSE* anterior = nullptr;
    if(lista!=nullptr) {
        while (ultimo->sgte) {
            anterior = ultimo;
            ultimo = ultimo->sgte;
        }
        if(ultimo != lista) {
            delete ultimo;
            anterior->sgte = nullptr;
        }
        else
            borrarPrimero(lista);
    }
    return;
}

void mostrarLista(NodoListaSE* lista) {
    if (!lista) {
        cout << " La lista está vacia..." << endl;
        return;
    }
    while (lista) // Recorro la lista, porque es una copia del puntero
    {
        cout << "Nodo en la dirección: " << lista << ", con valor en campo Info: " << lista->info <<endl;
        lista = lista->sgte;
    }
    return;
}
