#include <iostream>
using namespace std;

class estudiantes {
public:
    int dato;
    string nombres;
    estudiantes* siguiente;
    estudiantes(int dato,string nombres) {
        this->dato = dato;
        this->nombres = nombres;
        this->siguiente = nullptr;
    }
};

class asignatura {
public:
    int valor;
    string nombre;
    estudiantes* lista;
    asignatura* siguiente;
    asignatura* anterior;
    asignatura(int valor,string nombre) {
        this->valor = valor;
        this->nombre = nombre;
        this->lista = nullptr;
        this->siguiente = nullptr;
        this->anterior = nullptr;
        
    }
};

class Multilista {
public:
    asignatura* primero;
    Multilista() {
        this->primero = nullptr;
    }
    void insertar(int valor, int dato,string nombre, string nombres) {
        asignatura* objeto = buscar(valor);
        if (objeto == nullptr) {
            objeto = new asignatura(valor,nombre);
            objeto->lista = new estudiantes(dato,nombres);
            objeto->lista->siguiente = nullptr;
            objeto->lista->dato = dato;
            objeto->siguiente = primero;
            objeto->anterior = objeto;
            primero = objeto;
        }
        else {
            estudiantes* nuevo = new estudiantes(dato,nombre);
            nuevo->siguiente = objeto->lista;
            objeto->lista = nuevo;
        }
    }
    asignatura* buscar(int valor) {
        asignatura* actual = primero;
        while (actual != NULL) {
            if (actual->valor == valor) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return NULL;
    }
    void mostrar() {
        asignatura* actual = primero;
        while (actual != NULL) {
            cout << actual->nombre << endl;
            cout << actual->valor <<endl;
            
            estudiantes* nodo_actual = actual->lista;
            while (nodo_actual != NULL) {
                cout << nodo_actual->dato << endl;
                cout << nodo_actual->nombres<<endl;
                nodo_actual = nodo_actual->siguiente;
            }
            cout << endl;
            actual = actual->siguiente;
            
        }
    }
};

int main() {
    Multilista multilista;

    int opcion, valor;
    string nombre;
    int dato;
    string nombres;
    do {
        cout << "1. Insertar materia" << endl;
        cout << "2. incertar estudiante a una materia" << endl;
        cout << "3. Mostrar multilista" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:

            cout << "incerete el nombre de la materia" << endl;
            cin >> nombre;
            cout << "ingrese el codigo de la materia ";
            cin >> valor;
            multilista.insertar(valor, 0,nombre,nombres);
            break;
        case 2:
            cout << "ingrese el codigo de la materia a la que quiera asignar "<<endl;
            cin >> valor;
            cout << "ingrese ci del estudiante"<<endl;
            cin >> dato;
            cout << "ingrese el nombre del estudiante" << endl;
            cin >> nombres;
            multilista.insertar(valor, dato, "", nombres);
            break;
        case 3:
            multilista.mostrar();
            break;
        case 4:
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
