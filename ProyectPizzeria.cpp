#include <iostream>
#include <string>
#include <queue>
using namespace std;

string contrasena = "struct";

queue<string> unaCola;

void listDom()
{
    for (int i = 0; i <= unaCola.size(); i++)
    {
        cout << "Nombre del cliente: " << unaCola.front() << endl;
        unaCola.pop();
    }
}

int entregaDomicilio()
{
    string name, direction;
    int phone;

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, direction);
    unaCola.push(name);
}

void menuEmpleado()
{
    char option;

    do
    {
        cout << "Menu" << endl;
        cout << "\ta) Agregar pedido a domicilio\n\tb) Agregar encargo a restaurante\n\tc) Ver pedidos a domicilio\n\td) Ver encargos en el restaurante\n\te) Salir";
        cout << "\nSu opcion: ";
        cin >> option;

        switch (option)
        {
        case 'a':
            entregaDomicilio();
            break;
        case 'c':
            listDom();
            break;
        }
        cout << endl;
    } while (option != 'e');
}

void menuAdmin()
{
    char option;

    do
    {
        cout << "Menu" << endl;
        cout << "\ta) Agregar pedido a domicilio\n\tb) Agregar encargo a restaurante\n\tc) Ver pedidos a domicilio\n\td) Ver encargos en el restaurante\n\te) Ver total de venta\n\tf) Borrar ordenes\n\tg) Salir ";
        cout << "\n\tSu opcion: ";
        cin >> option;

        switch (option)
        {
        case 'a':
            entregaDomicilio();
            break;
        case 'c':
            listDom();
            break;
        }
        cout << endl;
    } while (option != 'g');
}

int main()
{
    string clave;
    char opcion;

    do
    {

        cout << "Selecciones su cargo: " << endl;
        cout << "\ta) Empleado\n\tb) Administrador";
        cout << "\n\tSu opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 'a':
            menuEmpleado();
            break;

        case 'b':
            do
            {
                cout << "Ingrese la contraseña: ";
                cin >> clave;
                if (clave == contrasena)
                {
                    menuAdmin();
                }
            } while (clave != contrasena);

            break;
        }
    } while (opcion != 'c');

    return 0;
}
