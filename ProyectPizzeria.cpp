#include <iostream>
#include <string>

using namespace std;

struct Pizzeria
{
    string nombre;
    string pedido;
    string entrada;
    string direccion;
    int telefono;
};


float promedio(){


};

int main()
{
    struct Pizzeria domicilio;

    cout << "Digite su nombre: ";
    cin >> domicilio.nombre;
    cin.ignore();
    getline (cin, domicilio.nombre);

    cout << "Digite su pedido entre las opciones pizza, ensalada o pasta: ";
    cin >> domicilio.pedido;
    cin.ignore();
    getline (cin, domicilio.pedido);

    cout << "Digite su entrada entre Alitas o una orden de nachos: ";
    cin >> domicilio.entrada;
    cin.ignore();
    getline (cin, domicilio.entrada);

    cout << "Digite la dirección de su domicilio: ";
    cin >> domicilio.direccion;
    cin.ignore();
    getline (cin, domicilio.direccion);

    cout << "Digite su número de telefono: ";
    cin >> domicilio.telefono;
    cin.ignore();
    
    return 0;
}