#include <iostream>
#include <string>
#include <vector>
using namespace std;

string password = "struct";
float monto = 0;
int PerTable = 0;
int orderNumber = 0;
enum paymentType
{
    cash,
    card
};

struct address
{
    string settlement;
    string municipality;
    string department;
    int houseNumber;
};

struct mainDish
{
    int pizza = 0;
    int pasta = 0;
    int lasagna = 0;
};
typedef struct mainDish mainDishP;

struct drinks
{
    int soda = 0;
    int beer = 0;
    int iceTea = 0;
};
typedef struct drinks Drinks;

struct starter
{
    int garlicBread = 0;
    int pizzaRolls = 0;
    int cheeseSticks = 0;
};
typedef struct starter Starter;

struct delivery
{
    string FullName;
    address deliveryAddress;
    int CellPhone;
    mainDishP dishP;
    Drinks drinksP;
    Starter starterP;
    paymentType pay;
};
typedef struct delivery Delivery;

vector<Delivery> orders;

char EmployeMenu(char aux);
char AdminMenu(char aux);
void DeliveryOrders();
void RestaurantOrders();
void WatchDeliveryOrders();
void WatchDelivery();
void WatchRestaurantOrders();
void WatchRestaurant();
void ServeDeliveryOrders();
void ServeRestaurantsOrders();
void WaitTimeDeliveryOrders();
void WaitTimeRestaurantsOrders();
void CancelOrder();
void CalculateTotalSales();

int main()
{
    string clave;
    char opcion;
    char aux;

    do
    {
        cout << "\nSeleccione su usuario: " << endl;
        cout << "\ta) Empleado\n\tb) Administrador\n\tc) Salir\t";
        cout << "\n Su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'a':
            aux = EmployeMenu(aux);
            break;

        case 'b':
            do
            {
                cout << "Ingrese la contraseña: ";
                cin >> clave;
                if (clave == password)
                {
                    aux = AdminMenu(aux);
                }
            } while (clave != password);
            break;
        }
    } while (opcion != 'c' && aux != 'c');

    return 0;
}

char EmployeMenu(char aux)
{
    int option = 0;
    bool continuar = true;

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
        cout << "\t7) Ver timepo promedio de espera a domicilio\n";
        cout << "\t8) Ver timepo promedio de espera en restuarante\n";
        cout << "\t9) Calcular total de ventas\n";
        cout << "\t10) Cambiar de usuario\n";
        cout << "\t11) Salir\n";
        cout << "Su opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            DeliveryOrders();
            break;
        case 2:
            RestaurantOrders();
        case 3:
            WatchDeliveryOrders();
            break;
        case 4:
            WatchRestaurantOrders();
            break;
        case 5:
            //ServeDeliveryOrders();
            break;
        case 6:
            //ServeRestaurantsOrders();
            break;
        case 7:
            //WaitTimeDeliveryOrders();
            break;
        case 8:
            //WaitTimeRestaurantsOrders();
            break;
        case 9:
            //CalculateTotalSales();
            break;
        case 10:
            continuar = false;
            break;
        case 11:
            return 'c';
            break;
        default:
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (continuar);
}

char AdminMenu(char aux)
{
    int option = 0;
    bool continuar = true;
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
        cout << "\t7) Ver tiempo promedio de espera a domicilio\n";
        cout << "\t8) Ver tiempo promedio de espera  en restaurante\n";
        cout << "\t9) Cancelar orden\n";
        cout << "\t10) Calcular total de ventas\n";
        cout << "\t11) Cambiar de usuario\n";
        cout << "\t12) Salir\n";
        cout << "Su opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            DeliveryOrders();
            break;
        case 2:
            RestaurantOrders();
        case 3:
            WatchDeliveryOrders();
            break;
        case 4:
            WatchRestaurantOrders();
            break;
        case 5:
            //ServeDeliveryOrders();
            break;
        case 6:
            //ServeRestaurantsOrders();
            break;
        case 7:
            //WaitTimeDeliveryOrders();
            break;
        case 8:
            //WaitTimeRestaurantsOrders();
            break;
        case 9:
            //CancelOrder();
            break;
        case 10:
            //CalculateTotalSales();
            break;

        case 11:
            continuar = false;
            break;

        case 12:
            return 'c';
            break;

        default:
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (continuar);
}

void DeliveryOrders()
{
    Delivery aux;
    bool continuar = true;
    orderNumber = orderNumber + 1;

    int option = 0, option2 = 0, option3 = 0;
    Delivery p;
    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;
    cout << "\nNúmero de orden #" << orderNumber << endl;
    cout << "Ingrese el nombre del cliente : ";
    cin.ignore();
    getline(cin, aux.FullName);

    cout << "Ingrese un telefono: ";
    cin.ignore();
    cin >> aux.CellPhone;

    cout << "\n----------------------------" << endl;
    cout << "***Dirección del cliente***" << endl;
    cout << "----------------------------" << endl;

    cout << "\nDepartamento: ";
    cin.ignore();
    getline(cin, aux.deliveryAddress.department);

    cout << "Municipio: ";
    cin.ignore();
    getline(cin, aux.deliveryAddress.municipality);

    cout << "Colonia: ";
    cin.ignore();
    getline(cin, aux.deliveryAddress.settlement);

    cout << "No. de casa: ";
    cin.ignore();
    cin >> aux.deliveryAddress.houseNumber;
    cout << endl;

    do
    {
        continuar = true;
        cout << "\n***Elija su orden***" << endl;
        cout << "\n1. Plato Principal";
        cout << "\n2. Entraditas";
        cout << "\n3. Bebidas";
        cout << "\n4. Salir";
        cout << "\nOpcion: ";
        cin >> option2;
        cin.ignore();

        switch (option2)
        {
        case 1:

            do
            {
                continuar = true;
                cout << "\n---------------------" << endl;
                cout << "***Plato Principal***" << endl;
                cout << "---------------------" << endl;

                cout << "1. Pizza\n2. Pasta\n3. Lasagna\n4. Salir";
                cout << "\nOpcion: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas pizzas desea ordenar?: ";
                    cin >> p.dishP.pizza;
                    monto = monto + (pizza * p.dishP.pizza);
                    break;
                case 2:
                    cout << "\n¿Cuantas pastas desea ordenar?: ";
                    cin >> p.dishP.pasta;
                    monto = monto + (pasta * p.dishP.pasta);
                    break;
                case 3:
                    cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                    cin >> p.dishP.lasagna;
                    monto = monto + (lasagna * p.dishP.lasagna);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                    break;
                }
            } while (continuar);
            break;

        case 2:

            do
            {
                continuar = true;
                cout << "\n----------------" << endl;
                cout << "***Entraditas***" << endl;
                cout << "----------------" << endl;

                cout << "1. Cheese Sticks\n2. Pan con ajo\n3. Pizza Rolls\n4. Salir";
                cout << "\nOpcion: ";
                cin >> option;
                cin.ignore();

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas ordenes de cheese sticks desea ordenar?: ";
                    cin >> p.starterP.cheeseSticks;
                    monto = monto + (cheeseSticks * p.starterP.cheeseSticks);
                    break;
                case 2:
                    cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                    cin >> p.starterP.garlicBread;
                    monto = monto + (garlicBread * p.starterP.garlicBread);
                    break;
                case 3:
                    cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                    cin >> p.starterP.pizzaRolls;
                    monto = monto + (pizzaRolls * p.starterP.pizzaRolls);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                    break;
                }
            } while (continuar);
            break;
        case 3:

            do
            {
                continuar = true;
                cout << "\n-------------" << endl;
                cout << "***Bebidas***" << endl;
                cout << "-------------" << endl;

                cout << "1. Cervezas\n2. Sodas\n3. Té helado\n4. Salir";
                cout << "\nOpcion: ";
                cin >> option;
                cin.ignore();

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas cervezas desea ordenar?: ";
                    cin >> p.drinksP.beer;
                    monto = monto + (beer * p.drinksP.beer);
                    break;
                case 2:
                    cout << "\n¿Cuantas sodas desea ordenar?: ";
                    cin >> p.drinksP.soda;
                    monto = monto + (soda * p.drinksP.soda);
                    break;
                case 3:
                    cout << "\n¿Cuantos té helado desea ordenar?: ";
                    cin >> p.drinksP.iceTea;
                    monto = monto + (iceTea * p.drinksP.iceTea);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                    break;
                }
            } while (continuar);
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
        }
    } while (option2 != 4);

    cout << "Monto total: $" << monto << " dólares";

    cout << "\n\n***Ingrese un método de pago***" << endl;
    cout << "\n1. Efectivo\n2. Tarjeta de crédito";
    cout << "\nOpcion: ";
    cin >> option3;
    cin.ignore();
    orders.push_back(p);
}

void RestaurantOrders()
{
    Delivery aux;
    bool continuar = true;
    int option = 0, option2 = 0, option3 = 0;
    Delivery p;
    orderNumber = orderNumber + 1;
    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;

    cout << "\nNúmero de orden #" << orderNumber << endl;
    cout << "Ingrese el nombre de la reserva : ";
    cin.ignore();
    getline(cin, aux.FullName);

    do
    {

        cout << "Cuantas personas por mesa: ";
        cin >> PerTable;

        continuar = true;
        if (PerTable <= 5)
        {
            do
            {
                continuar = true;
                cout << "\n***Elija su orden***" << endl;
                cout << "\n1. Plato Principal";
                cout << "\n2. Entraditas";
                cout << "\n3. Bebidas";
                cout << "\n4. Salir";
                cout << "\nOpcion: ";
                cin >> option2;
                cin.ignore();

                switch (option2)
                {
                case 1:

                    do
                    {
                        continuar = true;
                        cout << "\n---------------------" << endl;
                        cout << "***Plato Principal***" << endl;
                        cout << "---------------------" << endl;

                        cout << "1. Pizza\n2. Pasta\n3. Lasagna\n4. Salir";
                        cout << "\nOpcion: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas pizzas desea ordenar?: ";
                            cin >> p.dishP.pizza;
                            monto = monto + (pizza * p.dishP.pizza);
                            break;
                        case 2:
                            cout << "\n¿Cuantas pastas desea ordenar?: ";
                            cin >> p.dishP.pasta;
                            monto = monto + (pasta * p.dishP.pasta);
                            break;
                        case 3:
                            cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                            cin >> p.dishP.lasagna;
                            monto = monto + (lasagna * p.dishP.lasagna);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                            break;
                        }
                    } while (continuar);
                    break;

                case 2:

                    do
                    {
                        continuar = true;
                        cout << "\n----------------" << endl;
                        cout << "***Entraditas***" << endl;
                        cout << "----------------" << endl;

                        cout << "1. Cheese Sticks\n2. Pan con ajo\n3. Pizza Rolls\n4. Salir";
                        cout << "\nOpcion: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas ordenes de cheese sticks desea ordenar?: ";
                            cin >> p.starterP.cheeseSticks;
                            monto = monto + (cheeseSticks * p.starterP.cheeseSticks);
                            break;
                        case 2:
                            cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                            cin >> p.starterP.garlicBread;
                            monto = monto + (garlicBread * p.starterP.garlicBread);
                            break;
                        case 3:
                            cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                            cin >> p.starterP.pizzaRolls;
                            monto = monto + (pizzaRolls * p.starterP.pizzaRolls);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                            break;
                        }
                    } while (continuar);
                    break;
                case 3:

                    do
                    {
                        continuar = true;
                        cout << "\n-------------" << endl;
                        cout << "***Bebidas***" << endl;
                        cout << "-------------" << endl;

                        cout << "1. Cervezas\n2. Sodas\n3. Té helado\n4. Salir";
                        cout << "\nOpcion: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas cervezas desea ordenar?: ";
                            cin >> p.drinksP.beer;
                            monto = monto + (beer * p.drinksP.beer);
                            break;
                        case 2:
                            cout << "\n¿Cuantas sodas desea ordenar?: ";
                            cin >> p.drinksP.soda;
                            monto = monto + (soda * p.drinksP.soda);
                            break;
                        case 3:
                            cout << "\n¿Cuantos té helado desea ordenar?: ";
                            cin >> p.drinksP.iceTea;
                            monto = monto + (iceTea * p.drinksP.iceTea);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                            break;
                        }
                    } while (continuar);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
                    break;
                }
            } while (option2 != 4);

            cout << "Monto total: $" << monto << " dólares";

            cout << "\n\n***Ingrese un método de pago***" << endl;
            cout << "\n1. Efectivo\n2. Tarjeta de crédito";
            cout << "\nOpcion: ";
            cin >> option3;
            cin.ignore();
            orders.push_back(p);
        }
        else
        {
            cout << "Máximo 5 personas" << endl;
        }
    } while (continuar);
}

void WatchDelivery(Delivery aux)
{
    cout << endl;
    cout << "\n---Datos del cliente---";
    cout << "\nNúmero de orden: #" << orderNumber;
    cout << "\nNombre del cliente: " << aux.FullName;
    cout << "\nDepartamento: " << aux.deliveryAddress.department;
    cout << "\nMunicipio: " << aux.deliveryAddress.municipality;
    cout << "\nColonia: " << aux.deliveryAddress.settlement;
    cout << "\nNo. de casa: " << aux.deliveryAddress.houseNumber;
    cout << "\n---Orden del cliente---\n";
    if (aux.dishP.pizza != 0)
    {
        cout << "Pizza: " << aux.dishP.pizza << endl;
    }
    if (aux.dishP.pasta != 0)
    {
        cout << "Pasta: " << aux.dishP.pasta << endl;
    }
    if (aux.dishP.lasagna != 0)
    {
        cout << "Lasagna: " << aux.dishP.lasagna << endl;
    }
    if (aux.starterP.cheeseSticks != 0)
    {
        cout << "Ordenes de cheese Sticks: " << aux.starterP.cheeseSticks << endl;
    }
    if (aux.starterP.garlicBread != 0)
    {
        cout << "Ordenes de pan con ajo: " << aux.starterP.garlicBread << endl;
    }
    if (aux.starterP.pizzaRolls != 0)
    {
        cout << "Ordenes de pizza Rolls: " << aux.starterP.pizzaRolls << endl;
    }
    if (aux.drinksP.beer != 0)
    {
        cout << "Cerveza: " << aux.drinksP.beer << endl;
    }
    if (aux.drinksP.soda != 0)
    {
        cout << "Soda: " << aux.drinksP.soda << endl;
    }
    if (aux.drinksP.iceTea != 0)
    {
        cout << "Té helado: " << aux.drinksP.iceTea << endl;
    }
    cout << "Monto total: $" << monto << " dólares" << endl;

    cout << "Tipo de pago: ";
    switch(aux.pay)
    {
        case cash: cout << "Efectivo" << endl;
        break;
        case card: cout << "Tarjeta de crédito" << endl;
        break;
    }

}

void WatchDeliveryOrders()
{
    for (int i = 0; i < orders.size(); i++)
    {
        WatchDelivery(orders[i]);
    }
}

void WatchRestaurant(Delivery aux)
{
    cout << endl;
    cout << "\n---Datos del cliente---";
    cout << "\nNúmero de orden: #" << orderNumber;
    cout << "\nNombre del cliente: " << aux.FullName;
    cout << "\nDepartamento: " << aux.deliveryAddress.department;
    cout << "\nMunicipio: " << aux.deliveryAddress.municipality;
    cout << "\nColonia: " << aux.deliveryAddress.settlement;
    cout << "\nNo. de casa: " << aux.deliveryAddress.houseNumber;
    cout << "\n---Orden del cliente---\n";
    if (aux.dishP.pizza != 0)
    {
        cout << "Pizza: " << aux.dishP.pizza << endl;
    }
    if (aux.dishP.pasta != 0)
    {
        cout << "Pasta: " << aux.dishP.pasta << endl;
    }
    if (aux.dishP.lasagna != 0)
    {
        cout << "Lasagna: " << aux.dishP.lasagna << endl;
    }
    if (aux.starterP.cheeseSticks != 0)
    {
        cout << "Ordenes de cheese Sticks: " << aux.starterP.cheeseSticks << endl;
    }
    if (aux.starterP.garlicBread != 0)
    {
        cout << "Ordenes de pan con ajo: " << aux.starterP.garlicBread << endl;
    }
    if (aux.starterP.pizzaRolls != 0)
    {
        cout << "Ordenes de pizza Rolls: " << aux.starterP.pizzaRolls << endl;
    }
    if (aux.drinksP.beer != 0)
    {
        cout << "Cerveza: " << aux.drinksP.beer << endl;
    }
    if (aux.drinksP.soda != 0)
    {
        cout << "Soda: " << aux.drinksP.soda << endl;
    }
    if (aux.drinksP.iceTea != 0)
    {
        cout << "Té helado: " << aux.drinksP.iceTea << endl;
    }
    cout << "Monto total: $" << monto << " dólares" << endl;
    cout << "Tipo de pago: ";
    switch(aux.pay)
    {
        case cash: cout << "Efectivo" << endl;
        break;
        case card: cout << "Tarjeta de crédito" << endl;
        break;
    }

    cout << "Personas por mesa: " << PerTable << endl;
}

void WatchRestaurantOrders()
{
    for (int i = 0; i < orders.size(); i++)
    {
        WatchRestaurant(orders[i]);
    }
}

void ServeDeliveryOrders()
{
}

void ServeRestaurantsOrders()
{
}

void WaitTimeDeliveryOrders() //sobrecarga
{
}
void WaitTimeRestaurantsOrders() //sobrecarga
{
}

void CancelOrder()
{
}

void CalculateTotalSales()
{
}
