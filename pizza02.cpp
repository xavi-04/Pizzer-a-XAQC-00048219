#include <iostream>
#include <string>
#include <vector>
using namespace std;

string password = "struct";

struct mainDish{
    int pizza;
    int pasta;
    int lasgna;
}
typedef struct mainDish mainDishP;

struct drinks{
    int soda;
    int beer;
    int iceTea;
}
typedef struct iceTea iceTeaP;

struct starter{
    int garlicBread;
    int pizzaRolls;
    int cheeseSticks;
}
typedef struct starter starterP;


struct address{
    string settlement, municipality, departament;
    int houseNumber;
};
typedef struct address addressP;

void DeliveryOrders()
{
    dataP aux;
    cout << endl;
    cout << "Ingrese el nombre del cliente : ";
    getline(cin, aux.FullName);
    cin.ignore();

    cout << "Ingrese una dirección: ";
    getline(cin, aux.direction);
    cin.ignore();

    cout << "Ingrese un telefono: ";
    cin >> aux.phone;
    cin.ignore();

    
}

void RestaurantOrders()
{
    dataP aux;
    int PeoplePerTable;

    cout << endl;
    cout << "Ingrese el nombre del clienta que la reserva : ";
    getline(cin, aux.FullName);
    cin.ignore();

    cout << "Ingrese el número de personas por mesa: ";
    cin >> PeoplePerTable;
    cin.ignore();   
}

void precios()
{
    float pizza = 0, pasta = 0, lasgna = 0;
    float cheeseSticks = 0, pizzaRolls = 0, GarlicBread = 0;
    float soda = 0, beer = 0, iceTea = 0;
}

void WacthDeliveryOrders()
{

}

void WatchRestaurantOrders()
{
}

void platoPrincipal()
{
    int option = 0;
    MainDish aux;

    do
    {
        cout << "Escoja su plato principal:" << endl;
        cout << "\t1. Pizza\n\t2. Lasgana\n\t3. Pasta\n\t4. Salir";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "¿Cuantas pizzas desea ordenar?";
            cin >> aux.pizza;
            break;
        case 2:
            cout << "¿Cuantas lasganas desea ordenar?";
            cin >> aux.lasgna;
            break;
        case 3:
            cout << "¿Cuantas pastas desea ordenar?";
            cin >> aux.pasta;
            break;
        }
    } while (option != 4);
}

void entraditas()
{
    int option = 0;
    starterP aux;

    do
    {
        cout << "Escoja su entradita:" << endl;
        cout << "\t1. Orden Pan con ajo\n\t2. Orden de Pizza Rolls\n\t3. Orden de Palitos de queso\n\t4. Salir";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "¿Cuantas ordenes de pan con ajo desea ordenar?";
            cin >> aux.garlicBread;
            break;
        case 2:
            cout << "¿Cuantas ordenes de rollos de pizza desea ordenar?";
            cin >> aux.pizzaRolls;
            break;
        case 3:
            cout << "¿Cuantas ordenes de palitos de queso desea ordenar?";
            cin >> aux.cheeseSticks;
            break;
        }
    } while (option != 4);
}

void bebidas()
{
    int op = 0;
    drinksP aux;
    do
    {
        cout << "Escoja su bebida:" << endl;
        cout << "\t1. Soda\n\t2. Cerveza\n\t3. Té Helado\n\t4. Salir";
        cin >> op;
        cin.ignore();
        switch (op)
        {
        case 1:
            cout << "¿Cuantas sodas desea ordenar?";
            cin >> aux.soda;
            break;
        case 2:
            cout << "¿Cuantas cervezas desea ordenar?";
            cin >> aux.beer;
            break;
        case 3:
            cout << "¿Cuantos té helados desea ordenar?";
            cin >> aux.iceTea;
            break;
        }
    } while (op != 4);
}

void tipoDePago()
{
    char option;

    cout << "Escoja su bebida:" << endl;
    cout << "\t1. Tarjeta de credito\n\t2. Efectivo\n\t3. Salir";
    switch (option)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void EmployeMenu()
{
    int option = 0;

    do
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "\t1) Agregar orden a domicilio\n";
        cout << "\t2) Agregar orden a restaurante\n";
        cout << "\t3) Ver ordenes a domicilio\n";
        cout << "\t4) Ver ordenes en restaurante\n";
        cout << "\t5) Despachar ordenes a domicilio\n";
        cout << "\t6) Despachar ordenes a restaurante\n";
        cout << "\t7) Ver timepo promedio de espera domicilio\n";
        cout << "\t8) Calcular total de ventas\n";
        cout << "\t9) Cambiar de usuario\n";
        cout << "\t10) Salir\n";
        cout << "Su opcion: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case '1':
            DeliveryOrders();
            break;
        case '2':
            RestaurantOrders();
        case '3':
            SeeDeliveryOrders();
            break;
        case '4':
            SeeRestaurantOrders();
            break;
        case '5':
            
            break;
        case '6':
            
            break;
        case '7':
            
            break;
        case '8':
            
            break;
        case '9':
            
            break;
        }while(option != 10)
        cout << endl;
    } while (option != 'e');
}

void AdminMenu()
{
    int option = 0;

    do
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "\t1) Agregar orden a domicilio\n";
        cout << "\t2) Agregar orden a restaurante\n";
        cout << "\t3) Ver ordenes a domicilio\n";
        cout << "\t4) Ver ordenes en restaurante\n";
        cout << "\t5) Despachar ordenes a domicilio\n";
        cout << "\t6) Despachar ordenes a restaurante\n";
        cout << "\t7) Ver timepo promedio de espera domicilio\n";
        cout << "\t8) Cancelar orden\n";
        cout << "\t9) Calcular total de ventas\n";
        cout << "\t10) Cambiar de usuario\n";
        cout << "\t11) Salir\n";
        cout << "Su opcion: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 'a':
            DeliveryOrders();
            break;
        case 'b':
            RestaurantOrders();
            break;
        case 'c':
            SeeDeliveryOrders();
            break;
        case 'd':
            SeeRestaurantOrders();
            break;
        }
        cout << endl;
    } while (option != '11');
}

int main(void)
{
    string clave;
    char opcion;

    do
    {

        cout << "\nSeleccione su usuario: " << endl;
        cout << "\ta) Empleado\n\tb) Administrador\n\tc) Salir\n\t";
        cout << "\n Su opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 'a':
            EmployeMenu();
            break;

        case 'b':
            do
            {
                cout << "Ingrese la contraseña: ";
                cin >> clave;
                if (clave == password)
                {
                    AdminMenu();
                }
            } while (clave != password);
            break;
        }
    } while (opcion != 'c');

    return 0;
}
