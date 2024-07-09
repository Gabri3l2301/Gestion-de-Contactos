#include <iostream>
#include <windows.h>
using namespace std;

const int MAX_CONTACTOS = 100;

struct contactoEmail {
    string nombre;
    string sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};

void agregarContacto(contactoEmail contactos[], int &numContactos) {
    if (numContactos < MAX_CONTACTOS) {
        contactoEmail nuevo;
        cout << "Ingrese nombre completo: ";
        cin.ignore();
        getline(cin, nuevo.nombre);
        cout << "Ingrese sexo: ";
        getline(cin, nuevo.sexo);
        cout << "Ingrese edad: ";
        cin >> nuevo.edad;
        cout << "Ingrese teléfono: ";
        cin.ignore();
        getline(cin, nuevo.telefono);
        cout << "Ingrese email: ";
        getline(cin, nuevo.email);
        cout << "Ingrese nacionalidad: ";
        getline(cin, nuevo.nacionalidad);
        
        contactos[numContactos] = nuevo;
        numContactos++;

        cout << "Contacto agregado exitosamente.\n";
    } else {
        cout << "La lista de contactos está llena. No se pueden agregar más contactos.\n";
    }
}

void eliminarContacto(contactoEmail contactos[], int &numContactos) {
}

void mostrarContactos(const contactoEmail contactos[], int numContactos) {
}

void mostrarContactosPorServidor(contactoEmail contactos[], int numContactos) {
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    contactoEmail contactos[MAX_CONTACTOS];
    int numContactos = 0;
    char opcion;

    do {
        cout << "a) Agregar un contacto\nb) Eliminar un contacto\nc) Mostrar listado general de contactos\nd) Mostrar listado de contactos ordenado por servidor de correo\ne) Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 'a':
                agregarContacto(contactos, numContactos);
                break;
            case 'b':
                eliminarContacto(contactos, numContactos);
                break;
            case 'c':
                mostrarContactos(contactos, numContactos);
                break;
            case 'd':
                mostrarContactosPorServidor(contactos, numContactos);
                break;
            case 'e':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 'e');

    return 0;
}