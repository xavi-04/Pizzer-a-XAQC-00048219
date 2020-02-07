#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string password = "struct";
int PerTable = 0;
int ordersCount = 0;

enum paymentType
{
    cash,
    card
};

struct address
{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainDish
{
    int pizza = 0, pasta = 0, lasagna = 0;
};
typedef struct mainDish mainDishP;

struct drinks
{
    int soda = 0, beer = 0, iceTea = 0;
};
typedef struct drinks Drinks;

struct starter
{
    int garlicBread = 0, pizzaRolls = 0, cheeseSticks = 0;
};
typedef struct starter Starter;

struct restaurant
{
    string reservationClient;
    mainDishP dishQ;
    Drinks drinksQ;
    Starter starterQ;
    paymentType payQ;
    float monto = 0, timeQ;
    int orderId = 0, orderNumber = 0;
};
typedef struct restaurant pRestaurant;

struct delivery
{
    string FullName;
    address deliveryAddress;
    int CellPhone, orderNumber = 0;
    mainDishP dishP;
    Drinks drinksP;
    Starter starterP;
    paymentType pay;
    vector<mainDish> dishT;
    vector<drinks> drinksT;
    vector<starter> starterT;
    float monto = 0, timeP;
};
typedef struct delivery Delivery;

vector<Delivery> deliveryP;
vector<pRestaurant> restaurantP;

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
void WaitTime(vector<Delivery> orders);
void WaitTime(vector<pRestaurant> restaurantP);
float recursiveSum(vector<Delivery>, int);
void CancelOrder();
void CalculateTotalSales();

int main()
{
    string passwordQ;
    char option;
    char aux;

    do
    {
        cout << "\n\t----------------------" << endl;
        cout << "\t***INICIO DE SESIÓN***" << endl;
        cout << "\t----------------------" << endl;
        cout << "\nSeleccione el usuario: " << endl;
        cout << "\ta) Empleado\n\tb) Administrador\n\tc) Salir\t";
        cout << "\nSu opción: ";
        cin >> option;

        switch (option)
        {
        case 'a':
            aux = EmployeMenu(aux);
            break;

        case 'b':
            do
            {
                cout << "Ingrese la contraseña: ";
                cin >> passwordQ;
                if (passwordQ == password)
                {
                    aux = AdminMenu(aux);
                }
            } while (passwordQ != password);
            break;
        }
    } while (option != 'c' && aux != 'c');

    return 0;
}

char EmployeMenu(char aux)
{
    int option = 0;
    bool continuar = true;

    do
    {
        cout << endl;
        cout << "\n-----------------------------------------------" << endl;
        cout << "***Sistema de despacho The Mamma Mia´s Pizza***" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "\n\t\t--------------" << endl;
        cout << "\t\tMenú Principal" << endl;
        cout << "\t\t--------------" << endl;
        cout << "\t1) Agregar orden a domicilio\n";
        cout << "\t2) Agregar orden a restaurante\n";
        cout << "\t3) Ver ordenes a domicilio\n";
        cout << "\t4) Ver ordenes en restaurante\n";
        cout << "\t5) Despachar ordenes a domicilio\n";
        cout << "\t6) Despachar ordenes a restaurante\n";
        cout << "\t7) Ver tiempo promedio de espera a domicilio\n";
        cout << "\t8) Ver tiempo promedio de espera en restuarante\n";
        cout << "\t9) Calcular total de ventas\n";
        cout << "\t10) Cambiar de usuario\n";
        cout << "\t11) Salir\n";
        cout << "\tSu opción: ";
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
            WaitTime(deliveryP);

            break;
        case 8:
            WaitTime(restaurantP);
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
            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
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
        cout << "\n-----------------------------------------------" << endl;
        cout << "***Sistema de despacho The Mamma Mia´s Pizza***" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "\n\\tt--------------" << endl;
        cout << "\t\tMenú Principal" << endl;
        cout << "\t\t--------------" << endl;
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
        cout << "\tSu opción: ";
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
            WaitTime(deliveryP);
            break;
        case 8:

            WaitTime(restaurantP);
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
            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (continuar);
}

void DeliveryOrders()
{
    ordersCount++;

    Delivery aux;
    aux.monto = 0;
    aux.orderNumber = ordersCount;
    bool continuar = true;
    int option = 0, option2 = 0, option3 = 0;
    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;

    cout << "\n-----------------------" << endl;
    cout << "***Datos del cliente***" << endl;
    cout << "-----------------------" << endl;
    cout << "\nNúmero de orden #" << aux.orderNumber << endl;
    cout << "Ingrese el nombre del cliente : ";
    cin.ignore();
    getline(cin, aux.FullName);

    cout << "Ingrese un teléfono: ";
    cin >> aux.CellPhone;
    cin.ignore();

    cout << "\n----------------------------" << endl;
    cout << "***Dirección del cliente***" << endl;
    cout << "----------------------------" << endl;

    cout << "Departamento: ";
    getline(cin, aux.deliveryAddress.department);

    cout << "Municipio: ";
    getline(cin, aux.deliveryAddress.municipality);

    cout << "Colonia: ";

    getline(cin, aux.deliveryAddress.settlement);

    cout << "No. de casa: ";
    cin >> aux.deliveryAddress.houseNumber;
    cin.ignore();
    cout << endl;

    do
    {
        continuar = true;
        cout << "\n--------------------" << endl;
        cout << "***Elija su orden***" << endl;
        cout << "--------------------" << endl;
        cout << "1. Plato Principal";
        cout << "\n2. Entraditas";
        cout << "\n3. Bebidas";
        cout << "\n4. Salir";
        cout << "\nOpción: ";
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
                cout << "\nOpción: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas pizzas desea ordenar?: ";
                    cin >> aux.dishP.pizza;
                    aux.monto = aux.monto + (pizza * aux.dishP.pizza);
                    break;
                case 2:
                    cout << "\n¿Cuantas pastas desea ordenar?: ";
                    cin >> aux.dishP.pasta;
                    aux.monto = aux.monto + (pasta * aux.dishP.pasta);
                    break;
                case 3:
                    cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                    cin >> aux.dishP.lasagna;
                    aux.monto = aux.monto + (lasagna * aux.dishP.lasagna);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
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
                cout << "\nOpción: ";
                cin >> option;
                cin.ignore();

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas ordenes de cheese sticks desea ordenar?: ";
                    cin >> aux.starterP.cheeseSticks;
                    aux.monto = aux.monto + (cheeseSticks * aux.starterP.cheeseSticks);
                    break;
                case 2:
                    cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                    cin >> aux.starterP.garlicBread;
                    aux.monto = aux.monto + (garlicBread * aux.starterP.garlicBread);
                    break;
                case 3:
                    cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                    cin >> aux.starterP.pizzaRolls;
                    aux.monto = aux.monto + (pizzaRolls * aux.starterP.pizzaRolls);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
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
                cout << "\nOpción: ";
                cin >> option;
                cin.ignore();

                switch (option)
                {
                case 1:
                    cout << "\n¿Cuantas cervezas desea ordenar?: ";
                    cin >> aux.drinksP.beer;
                    aux.monto = aux.monto + (beer * aux.drinksP.beer);
                    break;
                case 2:
                    cout << "\n¿Cuantas sodas desea ordenar?: ";
                    cin >> aux.drinksP.soda;
                    aux.monto = aux.monto + (soda * aux.drinksP.soda);
                    break;
                case 3:
                    cout << "\n¿Cuantos té helado desea ordenar?: ";
                    cin >> aux.drinksP.iceTea;
                    aux.monto = aux.monto + (iceTea * aux.drinksP.iceTea);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
                    break;
                }
            } while (continuar);
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
            break;
        }
    } while (option2 != 4);

    cout << "\nMonto total: $" << aux.monto << " dólares";

    cout << "\n\n-------------------------------" << endl;
    cout << "***Ingrese un método de pago***" << endl;
    cout << "-------------------------------" << endl;
    cout << "\n1. Efectivo\n2. Tarjeta de crédito";
    cout << "\nOpción: ";
    cin >> option3;

    if (option3 == 1)
        aux.pay = cash;
    else
    {
        aux.pay = card;
    }

    aux.timeP = ((aux.dishP.pasta * 1.5 + aux.dishP.pizza * 1.5 + aux.dishP.lasagna * 1.5) +
                 (aux.starterP.cheeseSticks * 1.10 + aux.starterP.garlicBread * 1.10 + aux.starterP.pizzaRolls * 1.10) +
                 (aux.drinksP.beer * 1.35 + aux.drinksP.soda * 1.35 + aux.drinksP.iceTea * 1.35) +
                 15);
    cout << "\nEl tiempo de espera de la orden del cliente es: " << aux.timeP << " minutos" << endl;

    deliveryP.push_back(aux);
    cout << endl;
}

void RestaurantOrders()
{
    pRestaurant aux;
    aux.monto = 0;
    ordersCount++;
    aux.orderNumber = ordersCount;
    aux.orderId = 0;
    bool continuar = true;
    int option = 0, option2 = 0, option3 = 0;

    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;

    cout << "\n-------------------------------------" << endl;
    cout << "***Datos de la reserva del cliente***" << endl;
    cout << "-------------------------------------" << endl;
    cout << "\nNúmero de orden #" << aux.orderId << endl;
    cout << "Ingrese el nombre de la reserva: ";
    cin.ignore();
    getline(cin, aux.reservationClient);

    do
    {

        cout << "¿Cuantas personas por mesason en total?: ";
        cin >> PerTable;

        continuar = true;
        if (PerTable <= 5)
        {
            do
            {
                continuar = true;
                cout << "\n--------------------" << endl;
                cout << "***Elija su orden***" << endl;
                cout << "--------------------" << endl;
                cout << "\n1. Plato Principal";
                cout << "\n2. Entraditas";
                cout << "\n3. Bebidas";
                cout << "\n4. Salir";
                cout << "\nOpción: ";
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
                        cout << "\nOpción: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas pizzas desea ordenar?: ";
                            cin >> aux.dishQ.pizza;
                            aux.monto = aux.monto + (pizza * aux.dishQ.pizza);
                            break;
                        case 2:
                            cout << "\n¿Cuantas pastas desea ordenar?: ";
                            cin >> aux.dishQ.pasta;
                            aux.monto = aux.monto + (pasta * aux.dishQ.pasta);
                            break;
                        case 3:
                            cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                            cin >> aux.dishQ.lasagna;
                            aux.monto = aux.monto + (lasagna * aux.dishQ.lasagna);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
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
                        cout << "\nOpción: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas ordenes de cheese sticks desea ordenar?: ";
                            cin >> aux.starterQ.cheeseSticks;
                            aux.monto = aux.monto + (cheeseSticks * aux.starterQ.cheeseSticks);
                            break;
                        case 2:
                            cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                            cin >> aux.starterQ.garlicBread;
                            aux.monto = aux.monto + (garlicBread * aux.starterQ.garlicBread);
                            break;
                        case 3:
                            cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                            cin >> aux.starterQ.pizzaRolls;
                            aux.monto = aux.monto + (pizzaRolls * aux.starterQ.pizzaRolls);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
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
                        cout << "\nOpción: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "\n¿Cuantas cervezas desea ordenar?: ";
                            cin >> aux.drinksQ.beer;
                            aux.monto = aux.monto + (beer * aux.drinksQ.beer);
                            break;
                        case 2:
                            cout << "\n¿Cuantas sodas desea ordenar?: ";
                            cin >> aux.drinksQ.soda;
                            aux.monto = aux.monto + (soda * aux.drinksQ.soda);
                            break;
                        case 3:
                            cout << "\n¿Cuantos té helado desea ordenar?: ";
                            cin >> aux.drinksQ.iceTea;
                            aux.monto = aux.monto + (iceTea * aux.drinksQ.iceTea);
                            break;
                        case 4:
                            continuar = false;
                            break;
                        default:
                            cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
                            break;
                        }
                    } while (continuar);
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    cout << "¡¡¡Opción inexistente!!!, intente de nuevo" << endl;
                    break;
                }
            } while (option2 != 4);

            cout << "\nMonto total: $" << aux.monto << " dólares";

            cout << "\n\n-------------------------------" << endl;
            cout << "***Ingrese un método de pago***" << endl;
            cout << "-------------------------------" << endl;
            cout << "\n1. Efectivo\n2. Tarjeta de crédito";
            cout << "\nOpción: ";
            cin >> option3;
            if (option3 == 1)
                aux.payQ = cash;
            else
            {
                aux.payQ = card;
            }
            cin.ignore();
        }
        else
        {
            cout << "Máximo 5 personas por mesa" << endl;
        }
    } while (continuar);

    aux.timeQ = ((aux.dishQ.pasta * 1.5 + aux.dishQ.pizza * 1.5 + aux.dishQ.lasagna * 1.5) + (aux.starterQ.cheeseSticks * 1.10 + aux.starterQ.garlicBread * 1.10 + aux.starterQ.pizzaRolls * 1.10) + (aux.drinksQ.beer * 1.35 + aux.drinksQ.soda * 1.35 + aux.drinksQ.iceTea * 1.35) + 15);
    cout << "\nEl tiempo de espera de la orden del cliente es: " << aux.timeQ << " minutos" << endl;

    restaurantP.push_back(aux);
    cout << endl;
}

void WatchDelivery(Delivery aux)
{
    cout << endl;
    cout << "-------------------------------";
    cout << "\n***Datos del cliente***";
    cout << "\nNúmero de orden: #" << aux.orderNumber;
    cout << "\nNombre del cliente: " << aux.FullName;
    cout << "\nDepartamento: " << aux.deliveryAddress.department;
    cout << "\nMunicipio: " << aux.deliveryAddress.municipality;
    cout << "\nColonia: " << aux.deliveryAddress.settlement;
    cout << "\nNo. de casa: " << aux.deliveryAddress.houseNumber;
    cout << "\n***Orden del cliente***\n";
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
        cout << "Orden de cheese Sticks: " << aux.starterP.cheeseSticks << endl;
    }
    if (aux.starterP.garlicBread != 0)
    {
        cout << "Orden de pan con ajo: " << aux.starterP.garlicBread << endl;
    }
    if (aux.starterP.pizzaRolls != 0)
    {
        cout << "Orden de pizza Rolls: " << aux.starterP.pizzaRolls << endl;
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
    cout << "\nMonto total: $" << aux.monto << " dólares" << endl;

    cout << "Tipo de pago: ";
    switch (aux.pay)
    {
    case cash:
        cout << "Efectivo" << endl;
        break;
    case card:
        cout << "Tarjeta de crédito" << endl;
        break;
    }
    cout << "-------------------------------";
}

void WatchDeliveryOrders()
{
    for (int i = 0; i < deliveryP.size(); i++)
    {
        WatchDelivery(deliveryP[i]);
    }
}

void WatchRestaurant(pRestaurant aux)
{
    cout << endl;
    cout << "\n-------------------------------";
    cout << "\n***Datos del cliente***";
    cout << "\nNúmero de orden: #" << aux.orderId;
    cout << "\nNombre del cliente: " << aux.reservationClient;
    cout << "\nPersonas por mesa: " << PerTable << endl;
    cout << "***Orden del cliente***\n";
    if (aux.dishQ.pizza != 0)
    {
        cout << "Pizza: " << aux.dishQ.pizza << endl;
    }
    if (aux.dishQ.pasta != 0)
    {
        cout << "Pasta: " << aux.dishQ.pasta << endl;
    }
    if (aux.dishQ.lasagna != 0)
    {
        cout << "Lasagna: " << aux.dishQ.lasagna << endl;
    }
    if (aux.starterQ.cheeseSticks != 0)
    {
        cout << "Orden de cheese Sticks: " << aux.starterQ.cheeseSticks << endl;
    }
    if (aux.starterQ.garlicBread != 0)
    {
        cout << "Orden de pan con ajo: " << aux.starterQ.garlicBread << endl;
    }
    if (aux.starterQ.pizzaRolls != 0)
    {
        cout << "Orden de pizza Rolls: " << aux.starterQ.pizzaRolls << endl;
    }
    if (aux.drinksQ.beer != 0)
    {
        cout << "Cerveza: " << aux.drinksQ.beer << endl;
    }
    if (aux.drinksQ.soda != 0)
    {
        cout << "Soda: " << aux.drinksQ.soda << endl;
    }
    if (aux.drinksQ.iceTea != 0)
    {
        cout << "Té helado: " << aux.drinksQ.iceTea << endl;
    }
    cout << "\nMonto total: $" << aux.monto << " dólares" << endl;
    cout << "Tipo de pago: ";
    switch (aux.payQ)
    {
    case cash:
        cout << "Efectivo" << endl;
        break;
    case card:
        cout << "Tarjeta de crédito" << endl;
        break;
    }
}

void WatchRestaurantOrders()
{
    for (int i = 0; i < restaurantP.size(); i++)
    {
        WatchRestaurant(restaurantP[i]);
    }
}

void ServeDeliveryOrders()
{
}

void ServeRestaurantsOrders()
{
}

void WaitTime(vector<Delivery> deliveryP) //sobrecarga
{
    float sum = recursiveSum(deliveryP, 0);

    cout << "\n-------------------------------------------------------------------------" << endl;
    cout << "El tiempo total de espera de las ordenes en el restaurante es: " << ceil(sum) << " minutos" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

float recursiveSum(vector<Delivery> deliveryP, int indice)
{
    if (indice < deliveryP.size())
    {
        float indivTime = ((deliveryP[indice].dishP.pasta * 1.5 + deliveryP[indice].dishP.pizza * 1.5 + deliveryP[indice].dishP.lasagna * 1.5) +
                           (deliveryP[indice].starterP.cheeseSticks * 1.10 + deliveryP[indice].starterP.garlicBread * 1.10 + deliveryP[indice].starterP.pizzaRolls * 1.10) +
                           (deliveryP[indice].drinksP.beer * 1.35 + deliveryP[indice].drinksP.soda * 1.35 + deliveryP[indice].drinksP.iceTea * 1.35) +
                           15);
        return indivTime + recursiveSum(deliveryP, indice + 1);
    }
    else
    {
        return 0;
    }
}

void WaitTime(vector<pRestaurant> restaurantP) //sobrecarga
{
    float sum = recursiveSum(restaurantP, 0);

    cout << "\n-------------------------------------------------------------------------" << endl;
    cout << "El tiempo total de espera de las ordenes en el restaurante es: " << ceil(sum) << " minutos" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}
float recursiveSum(vector<pRestaurant> restaurantP, int indice)
{
    if (indice < restaurantP.size())
    {
        float indivTime = ((restaurantP[indice].dishQ.pasta * 1.5 + restaurantP[indice].dishQ.pizza * 1.5 + restaurantP[indice].dishQ.lasagna * 1.5) +
                           (restaurantP[indice].starterQ.cheeseSticks * 1.10 + restaurantP[indice].starterQ.garlicBread * 1.10 + restaurantP[indice].starterQ.pizzaRolls * 1.10) +
                           (restaurantP[indice].drinksQ.beer * 1.35 + restaurantP[indice].drinksQ.soda * 1.35 + restaurantP[indice].drinksQ.iceTea * 1.35) +
                           15);
        return indivTime + recursiveSum(restaurantP, indice + 1);
    }
    else
    {
        return 0;
    }
}

void CancelOrder()
{
}

void CalculateTotalSales()
{
}