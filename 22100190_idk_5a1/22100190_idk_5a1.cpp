#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    string apellido;
    int registro;
    int edad;

    Persona() {}
    Persona(string nombre, string apellido, int registro, int edad) : nombre(nombre), apellido(apellido), registro(registro), edad(edad) {}
};

class Nodo {
public:
    Persona* datos;
    Nodo* siguiente;

    Nodo() : datos(nullptr), siguiente(nullptr) {}
    Nodo(Persona* datos) : datos(datos), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* inicio;
    int contador;
    Nodo* iterador;

public:
    Lista() : inicio(nullptr), contador(0), iterador(nullptr) {}

    void agregar(Persona* datos);
    void mostrar();
    bool buscar(string criterio, string valor);
    bool eliminar(int registro);
    bool modificar(int registro, Persona* nuevosDatos);
    int contar();
    void iterador_mostrar();
    void iterador_first();
    void iterador_last();
    void iterador_next();
    void iterador_prev();
    void iterador_getItem();
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

void Lista::mostrar() {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->datos->nombre << endl;
        cout << "Apellido: " << temp->datos->apellido << endl;
        cout << "Registro: " << temp->datos->registro << endl;
        cout << "Edad: " << temp->datos->edad << endl << endl;
        temp = temp->siguiente;
    }
}

bool Lista::buscar(string criterio, string valor) {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        if (criterio == "nombre" && temp->datos->nombre == valor) {
            cout << "Nodo encontrado:" << endl;
            cout << "Nombre: " << temp->datos->nombre << endl;
            cout << "Apellido: " << temp->datos->apellido << endl;
            cout << "Registro: " << temp->datos->registro << endl;
            cout << "Edad: " << temp->datos->edad << endl << endl;
            return true;
        }
        else if (criterio == "registro" && temp->datos->registro == stoi(valor)) {
            cout << "Nodo encontrado:" << endl;
            cout << "Nombre: " << temp->datos->nombre << endl;
            cout << "Apellido: " << temp->datos->apellido << endl;
            cout << "Registro: " << temp->datos->registro << endl;
            cout << "Edad: " << temp->datos->edad << endl << endl;
            return true;
        }
        temp = temp->siguiente;
    }
    cout << "Nodo no encontrado." << endl << endl;
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

void Lista::iterador_mostrar() {
    if (iterador != nullptr) {
        cout << "Iterador actual:" << endl;
        cout << "Nombre: " << iterador->datos->nombre << endl;
        cout << "Apellido: " << iterador->datos->apellido << endl;
        cout << "Registro: " << iterador->datos->registro << endl;
        cout << "Edad: " << iterador->datos->edad << endl << endl;
    }
    else {
        cout << "El iterador no apunta a ningún nodo." << endl << endl;
    }
}

void Lista::iterador_first() {
    iterador = inicio;
}

void Lista::iterador_last() {
    Nodo* temp = inicio;
    while (temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    iterador = temp;
}

void Lista::iterador_next() {
    if (iterador != nullptr && iterador->siguiente != nullptr) {
        iterador = iterador->siguiente;
    }
    else {
        cout << "No hay siguiente nodo." << endl << endl;
    }
}

void Lista::iterador_prev() {
    if (iterador != nullptr && iterador != inicio) {
        Nodo* temp = inicio;
        while (temp->siguiente != iterador) {
            temp = temp->siguiente;
        }
        iterador = temp;
    }
    else {
        cout << "No hay nodo anterior." << endl << endl;
    }
}

void Lista::iterador_getItem() {
    if (iterador != nullptr) {
        cout << "Dirección de memoria del nodo actual: " << iterador << endl << endl;
    }
    else {
        cout << "El iterador no apunta a ningún nodo." << endl << endl;
    }
}

int main() {
    Lista lista;

    char opcion;

    do {
        // Menú de opciones
        cout << "Seleccione una opción:" << endl;
        cout << "a. Agregar nodo" << endl;
        cout << "b. Buscar" << endl;
        cout << "c. Eliminación" << endl;
        cout << "d. Modificación" << endl;
        cout << "e. Contar" << endl;
        cout << "f. Mostrar" << endl;
        cout << "g. Iterador" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
        case 'a': {
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
            cout << "Nodo agregado exitosamente." << endl << endl;
            break;
        }
        case 'b': {
            string criterio, valor;
            cout << "Seleccione el criterio de búsqueda (nombre o registro): ";
            cin >> criterio;
            cout << "Ingrese el valor a buscar: ";
            cin >> valor;
            lista.buscar(criterio, valor);
            break;
        }
        case 'c': {
            int registro;
            cout << "Ingrese el número de registro del nodo a eliminar: ";
            cin >> registro;
            if (lista.eliminar(registro)) {
                cout << "Nodo eliminado exitosamente." << endl << endl;
            }
            else {
                cout << "Nodo no encontrado." << endl << endl;
            }
            break;
        }
        case 'd': {
            int registro;
            string nombre, apellido;
            int edad;
            cout << "Ingrese el número de registro del nodo a modificar: ";
            cin >> registro;
            cout << "Ingrese el nuevo nombre: ";
            cin >> nombre;
            cout << "Ingrese el nuevo apellido: ";
            cin >> apellido;
            cout << "Ingrese la nueva edad: ";
            cin >> edad;
            if (lista.modificar(registro, new Persona(nombre, apellido, registro, edad))) {
                cout << "Nodo modificado exitosamente." << endl << endl;
            }
            else {
                cout << "Nodo no encontrado." << endl << endl;
            }
            break;
        }
        case 'e': {
            cout << "Cantidad de nodos en la lista: " << lista.contar() << endl << endl;
            break;
        }
        case 'f': {
            cout << "Lista completa:" << endl;
            lista.mostrar();
            break;
        }
        case 'g': {
            char opcionIterador;
            do {
                cout << "Seleccione una opción del iterador:" << endl;
                cout << "a. Mostrar" << endl;
                cout << "b. First" << endl;
                cout << "c. Last" << endl;
                cout << "d. Next" << endl;
                cout << "e. Prev" << endl;
                cout << "f. getItem" << endl;
                cout << "0. Volver al menú principal" << endl;
                cout << "Ingrese su opción: ";
                cin >> opcionIterador;

                switch (opcionIterador) {
                case 'a': {
                    lista.iterador_mostrar();
                    break;
                }
                case 'b': {
                    lista.iterador_first();
                    cout << "Iterador movido al primer nodo." << endl << endl;
                    break;
                }
                case 'c': {
                    lista.iterador_last();
                    cout << "Iterador movido al último nodo." << endl << endl;
                    break;
                }
                case 'd': {
                    lista.iterador_next();
                    break;
                }
                case 'e': {
                    lista.iterador_prev();
                    break;
                }
                case 'f': {
                    lista.iterador_getItem();
                    break;
                }
                case '0': {
                    cout << "Volviendo al menú principal." << endl;
                    break;
                }
                default: {
                    cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                    break;
                }
                }
            } while (opcionIterador != '0');
            break;
        }
        case '0': {
            cout << "Saliendo del programa." << endl;
            break;
        }
        default: {
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
        }
    } while (opcion != '0');

    return 0;
}
