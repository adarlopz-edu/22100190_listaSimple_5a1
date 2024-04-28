#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    string apellido;
    int registro;
    int edad;

    // constructor
    Persona(string nombre, string apellido, int registro, int edad) : nombre(nombre), apellido(apellido), registro(registro), edad(edad) {}
};

class Nodo {
public:
    Persona* datos;
    Nodo* siguiente;

    //constructores
    Nodo() : datos(nullptr), siguiente(nullptr) {}
    Nodo(Persona* datos) : datos(datos), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* inicio;
    int contador;
    Nodo* iterador;

public:
    //constructor
    Lista() : inicio(nullptr), contador(0), iterador(nullptr) {}

    //todas las funciones principales
    void agregar(Persona* datos);
    bool buscar(string criterio, string valor, string& resultado);
    bool eliminar(int registro);
    bool modificar(int registro, Persona* nuevosDatos);
    int contar();
    void mostrar();

    //funciones del iterador
    void iterador_mostrar();
    void iterador_first();
    void iterador_last();
    void iterador_next();
    void iterador_prev();
    Nodo* iterador_getItem();
};

void Lista::agregar(Persona* datos) {
    Nodo* nuevo = new Nodo(datos);
    if (inicio == nullptr) {
        inicio = nuevo;
    }
    else {
        Nodo* temp = inicio;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    contador++;
}

bool Lista::buscar(string criterio, string valor, string& resultado) {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        if (criterio == "nombre" && temp->datos->nombre == valor) {
            resultado = "Nombre: " + temp->datos->nombre + "\nApellido: " + temp->datos->apellido + "\nRegistro: " + to_string(temp->datos->registro) + "\nEdad: " + to_string(temp->datos->edad) + "\n";
            return true;
        }
        else if (criterio == "registro" && temp->datos->registro == stoi(valor)) {
            resultado = "Nombre: " + temp->datos->nombre + "\nApellido: " + temp->datos->apellido + "\nRegistro: " + to_string(temp->datos->registro) + "\nEdad: " + to_string(temp->datos->edad) + "\n";
            return true;
        }
        temp = temp->siguiente;
    }
    resultado = "No hay un nodo con ese registro\n";
    return false;
}

bool Lista::eliminar(int registro) {
    Nodo* actual = inicio;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->datos->registro == registro) {
            if (anterior == nullptr) {
                inicio = actual->siguiente;
            }
            else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual->datos;
            delete actual;
            contador--;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

bool Lista::modificar(int registro, Persona* nuevosDatos) {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        if (temp->datos->registro == registro) {
            temp->datos->nombre = nuevosDatos->nombre;
            temp->datos->apellido = nuevosDatos->apellido;
            temp->datos->edad = nuevosDatos->edad;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

int Lista::contar() {
    return contador;
}

void Lista::mostrar() {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->datos->nombre << endl;
        cout << "Apellido: " << temp->datos->apellido << endl;
        cout << "Registro: " << temp->datos->registro << endl;
        cout << "Edad: " << temp->datos->edad << endl;
        cout << "Direccion del nodo: " << temp << endl;
        cout << "Direccion del siguiente nodo: " << temp->siguiente << endl << endl;
        temp = temp->siguiente;
    }
}

void Lista::iterador_mostrar() {
    if (iterador != nullptr) {
        cout << "Nodo actual" << endl;
        cout << "Nombre: " << iterador->datos->nombre << endl;
        cout << "Apellido: " << iterador->datos->apellido << endl;
        cout << "Registro: " << iterador->datos->registro << endl;
        cout << "Edad: " << iterador->datos->edad << endl << endl;
    }
    else {
        cout << "El iterador no apunta a nada" << endl << endl;
    }
}

void Lista::iterador_first() {
    //mueve el iterador al primer nodo de la lista
    iterador = inicio;
}

void Lista::iterador_last() {
    //mueve iterador al ultimo nodo de la lista
    Nodo* temp = inicio;
    while (temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    iterador = temp;
}

void Lista::iterador_next() {
    //mueve el iterador al siguiente nodo de la lista
    if (iterador != nullptr && iterador->siguiente != nullptr) {
        iterador = iterador->siguiente;
    }
}

void Lista::iterador_prev() {
    //mueve el iterador al nodo anterior de la lista
    if (iterador != nullptr && iterador != inicio) {
        Nodo* temp = inicio;
        while (temp->siguiente != iterador) {
            temp = temp->siguiente;
        }
        iterador = temp;
    }
}

Nodo* Lista::iterador_getItem() {
    //obtiene el nodo que apunta el iterador
    return iterador;
}

int main() {
    Lista lista;
    char opcion;

    lista.agregar(new Persona("juan", "lopez", 22100190, 21));
    lista.agregar(new Persona("pedro", "lopez", 22100191, 21));
    lista.agregar(new Persona("valentino", "lopez", 22100192, 21));

    //menu
    while (true) {
        cout << endl << "Lista simple brad" << endl << endl;
        cout << "a. Agregar nodo" << endl;
        cout << "b. Buscar" << endl;
        cout << "c. Eliminacion" << endl;
        cout << "d. Modificacion" << endl;
        cout << "e. Contar" << endl;
        cout << "f. Mostrar" << endl;
        cout << "g. Iterador" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 'a') {
            string nombre, apellido;
            int registro, edad;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese el registro: ";
            cin >> registro;
            cout << "Ingrese la edad: ";
            cin >> edad;
            lista.agregar(new Persona(nombre, apellido, registro, edad));
        }
        if (opcion == 'b') {
            string criterio, valor;
            string resultado;
            cout << "Seleccione el criterio de busqueda (nombre o registro): ";
            cin >> criterio;
            cout << "Ingrese el valor a buscar: ";
            cin >> valor;
            if (lista.buscar(criterio, valor, resultado)) {
                cout << resultado;
            }
            else {
                cout << "Nodo no encontrado" << endl << endl;
            }
        }
        if (opcion == 'c') {
            int registro;
            cout << "Ingrese el numero de registro del nodo a eliminar: ";
            cin >> registro;
            if (lista.eliminar(registro)) {
                cout << "Nodo eliminado exitosamente" << endl << endl;
            }
            else {
                cout << "Nodo no encontrado" << endl << endl;
            }
        }
        if (opcion == 'd') {
            int registro;
            string nombre, apellido;
            int edad;
            cout << "Ingrese el numero de registro del nodo a modificar: ";
            cin >> registro;
            cout << "Ingrese el nuevo nombre: ";
            cin >> nombre;
            cout << "Ingrese el nuevo apellido: ";
            cin >> apellido;
            cout << "Ingrese la nueva edad: ";
            cin >> edad;
            if (lista.modificar(registro, new Persona(nombre, apellido, registro, edad))) {
                cout << "Nodo modificado exitosamente" << endl << endl;
            }
            else {
                cout << "Nodo no encontrado" << endl << endl;
            }
        }
        if (opcion == 'e') {
            cout << "Cantidad de nodos en la lista: " << lista.contar() << endl << endl;
        }
        if (opcion == 'f') {
            lista.mostrar();
        }

        if (opcion == 'g') {
            //submenu
            char opcionIterador;
            do {
                cout << endl << "Submenu Iterador: " << endl;
                cout << "a. Mostrar" << endl;
                cout << "b. First" << endl;
                cout << "c. Last" << endl;
                cout << "d. Next" << endl;
                cout << "e. Prev" << endl;
                cout << "f. getItem" << endl;
                cout << "g. Volver al menu principal" << endl;
                cout << endl << "Ingrese una opcion: ";
                cin >> opcionIterador;

                switch (opcionIterador) {
                case 'a':
                    lista.iterador_mostrar();
                    break;

                case 'b':
                    lista.iterador_first();
                    cout << "Iterador movido al primer nodo" << endl << endl;
                    break;

                case 'c':
                    lista.iterador_last();
                    cout << "Iterador movido al ultimo nodo" << endl << endl;
                    break;

                case 'd':
                    lista.iterador_next();
                    break;

                case 'e':
                    lista.iterador_prev();
                    break;

                case 'f':
                {
                    Nodo* nodo_actual = lista.iterador_getItem();
                    if (nodo_actual != nullptr) {
                        cout << "Direccion de memoria del nodo actual: " << nodo_actual << endl;
                    }
                    else {
                        cout << "El iterador no apunta a ningun nodo" << endl << endl;
                    }
                }
                break;

                case 'g':
                    //vuelve al menu principal
                    break;

                default:
                    cout << "Opcion no valida" << endl;
                    break;
                }
            } while (opcionIterador != 'g');
        }
    }
}
