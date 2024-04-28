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

    Nodo() : datos(NULL), siguiente(NULL) {}
    Nodo(Persona* datos) : datos(datos), siguiente(NULL) {}
};

class Lista {
private:
    Nodo* inicio;
    int contador;
    Nodo* iterador;

public:
    Lista() : inicio(NULL), contador(0), iterador(NULL) {}

    void agregar(Persona* datos);
    bool buscar(string criterio, string valor, string& resultado);
    bool eliminar(int registro);
    bool modificar(int registro, Persona* nuevosDatos);
    int contar();
    void mostrar();


    void iterador_mostrar();
    void iterador_first();
    void iterador_last();
    void iterador_next();
    void iterador_prev();
    void iterador_getItem();
};

void Lista::agregar(Persona *datos) {
    Nodo* nuevo = new Nodo(datos);
    if (inicio == NULL) {
        inicio = nuevo;
    }
    else {
        Nodo* temp = inicio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    contador++;
}

bool Lista::buscar(string criterio, string valor, string& resultado) {
    Nodo* temp = inicio;
    while (temp != NULL) {
        if (criterio == "nombre" && temp->datos->nombre == valor) {
            resultado = "Nodo encontrado:\nNombre: " + temp->datos->nombre + "\nApellido: " + temp->datos->apellido + "\nRegistro: " + to_string(temp->datos->registro) + "\nEdad: " + to_string(temp->datos->edad) + "\n";
            return true;
        }
        else if (criterio == "registro" && temp->datos->registro == stoi(valor)) {
            resultado = "Nodo encontrado:\nNombre: " + temp->datos->nombre + "\nApellido: " + temp->datos->apellido + "\nRegistro: " + to_string(temp->datos->registro) + "\nEdad: " + to_string(temp->datos->edad) + "\n";
            return true;
        }
        temp = temp->siguiente;
    }
    resultado = "Nodo no encontrado.\n";
    return false;
}

bool Lista::eliminar(int registro) {
    Nodo* actual = inicio;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->datos->registro == registro) {
            if (anterior == NULL) {
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
    while (temp != NULL) {
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
    while (temp != NULL) {
        cout << temp->datos->nombre;
        cout << "Nombre: " << temp->datos->nombre << endl;
        cout << "Apellido: " << temp->datos->apellido << endl;
        cout << "Registro: " << temp->datos->registro << endl;
        cout << "Edad: " << temp->datos->edad << endl;
        cout << "Direccion del nodo: " << temp << endl;
        if (temp == iterador) {
            cout << "(Nodo actual)" << endl;
        }
        cout << "Direccion del siguiente nodo: " << temp->siguiente << endl << endl;
        temp = temp->siguiente;
    }
}

void Lista::iterador_mostrar() {
    if (iterador != NULL) {
        cout << "Valor del nodo actual:\n";
        cout << "Nombre: " << iterador->datos->nombre << endl;
        cout << "Apellido: " << iterador->datos->apellido << endl;
        cout << "Registro: " << iterador->datos->registro << endl;
        cout << "Edad: " << iterador->datos->edad << endl << endl;
    }
    else {
        cout << "El iterador no apunta a ningun nodo." << endl << endl;
    }
}

void Lista::iterador_first() {
    iterador = inicio;
}

void Lista::iterador_last() {
    Nodo* temp = inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    iterador = temp;
}

void Lista::iterador_next() {
    if (iterador != NULL && iterador->siguiente != NULL) {
        iterador = iterador->siguiente;
    }
}

void Lista::iterador_prev() {
    if (iterador != NULL && iterador != inicio) {
        Nodo* temp = inicio;
        while (temp->siguiente != iterador) {
            temp = temp->siguiente;
        }
        iterador = temp;
    }
}

void Lista::iterador_getItem() {
    if (iterador != NULL) {
        // No imprime desde la clase, solo devuelve el puntero
    }
}

int main() {

    Lista lista;
    char opcion;

    lista.agregar(new Persona("juan", "lopez", 22100190, 21));
    lista.agregar(new Persona("pedro", "lopez", 22100191, 21));
    lista.agregar(new Persona("valentino", "lopez", 22100192, 21));


    while (true) {
        cout << "Lista simple brad" << endl;
        cout << "a. Agregar nodo" << endl;
        cout << "b. Buscar" << endl;
        cout << "c. Eliminacion" << endl;
        cout << "d. Modificacion" << endl;
        cout << "e. Contar" << endl;
        cout << "f. Mostrar" << endl;
        cout << "g. Iterador" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        if (opcion == 'a'){
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
                cout << "Nodo no encontrado." << endl << endl;
            }
        }
        if (opcion == 'c') {
            int registro;
            cout << "Ingrese el numero de registro del nodo a eliminar: ";
            cin >> registro;
            if (lista.eliminar(registro)) {
                cout << "Nodo eliminado exitosamente." << endl << endl;
            }
            else {
                cout << "Nodo no encontrado." << endl << endl;
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
                cout << "Nodo modificado exitosamente." << endl << endl;
            }
            else {
                cout << "Nodo no encontrado." << endl << endl;
            }
        }
        if (opcion == 'e') {
            cout << "Cantidad de nodos en la lista: " << lista.contar() << endl << endl;
            break;
        }
        if (opcion == 'f') {
            lista.mostrar();
        }

        if (opcion == 'g') {
            char opcionIterador;
            do {
                cout << "Seleccione una opcion del iterador:" << endl;
                cout << "a. Mostrar" << endl;
                cout << "b. First" << endl;
                cout << "c. Last" << endl;
                cout << "d. Next" << endl;
                cout << "e. Prev" << endl;
                cout << "f. getItem" << endl;
                cout << "0. Volver al menu principal" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionIterador;

                switch (opcionIterador) {
                case 'a':
                    lista.iterador_mostrar();
                    break;

                case 'b':
                    lista.iterador_first();
                    cout << "Iterador movido al primer nodo." << endl << endl;
                    break;

                case 'c':
                    lista.iterador_last();
                    cout << "Iterador movido al ultimo nodo." << endl << endl;
                    break;

                case 'd':
                    lista.iterador_next();
                    break;

                case 'e':
                    lista.iterador_prev();
                    break;

                case 'f':
                    lista.iterador_getItem();
                    break;

                case '0':
                    cout << "Volviendo al menu principal." << endl;
                    break;

                default:
                    cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
                    break;
                }
            } while (opcionIterador != '0');
            break;
        }
    }
}
