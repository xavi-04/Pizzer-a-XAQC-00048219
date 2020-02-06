#include <iostream>
#include <string>
#include <cmath>
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

struct restaurant{
    string reserva;    
    mainDishP dishQ;
    Drinks drinksQ;
    Starter starterQ;
    paymentType payQ;
    float timeQ; 
};
typedef struct restaurant pRestaurant;

struct delivery
{
    string FullName;
    address deliveryAddress;
    int CellPhone;
    mainDishP dishP;
    Drinks drinksP;
    Starter starterP;
    paymentType pay;
    vector<mainDish> dishT;
    vector<drinks> drinksT;
    vector<starter> starterT;
    float timeP;
};
typedef struct delivery Delivery;

vector<Delivery> orders;
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
        cout << "Menú Principal" << endl;
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
        cout << "\tSu opcion: ";
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
            WaitTime(orders);

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
        cout << "Menú Principal" << endl;
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
        cout << "\tSu opcion: ";
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
            WaitTime(orders);
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
    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;
    cout << "\nNúmero de orden #" << orderNumber << endl;
    cout << "Ingrese el nombre del cliente : ";
    cin.ignore();
    getline(cin, aux.FullName);

    cout << "Ingrese un telefono: ";
    cin >> aux.CellPhone;
    cin.ignore();

    cout << "\n----------------------------" << endl;
    cout << "***Dirección del cliente***" << endl;
    cout << "----------------------------" << endl;

    cout << "\nDepartamento: ";
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
                    cin >> aux.dishP.pizza;
                    monto = monto + (pizza * aux.dishP.pizza);
                    break;
                case 2:
                    cout << "\n¿Cuantas pastas desea ordenar?: ";
                    cin >> aux.dishP.pasta;
                    monto = monto + (pasta * aux.dishP.pasta);
                    break;
                case 3:
                    cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                    cin >> aux.dishP.lasagna;
                    monto = monto + (lasagna * aux.dishP.lasagna);
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
                    cin >> aux.starterP.cheeseSticks;
                    monto = monto + (cheeseSticks * aux.starterP.cheeseSticks);
                    break;
                case 2:
                    cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                    cin >> aux.starterP.garlicBread;
                    monto = monto + (garlicBread * aux.starterP.garlicBread);
                    break;
                case 3:
                    cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                    cin >> aux.starterP.pizzaRolls;
                    monto = monto + (pizzaRolls * aux.starterP.pizzaRolls);
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
                    cin >> aux.drinksP.beer;
                    monto = monto + (beer * aux.drinksP.beer);
                    break;
                case 2:
                    cout << "\n¿Cuantas sodas desea ordenar?: ";
                    cin >> aux.drinksP.soda;
                    monto = monto + (soda * aux.drinksP.soda);
                    break;
                case 3:
                    cout << "\n¿Cuantos té helado desea ordenar?: ";
                    cin >> aux.drinksP.iceTea;
                    monto = monto + (iceTea * aux.drinksP.iceTea);
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
    
    if(option3 == 1)
    aux.pay = cash;
    else{
        aux.pay = card;
    }

    aux.timeP = ((aux.dishP.pasta * 1.5, aux.dishP.pizza * 1.5, aux.dishP.lasagna * 1.5) + (aux.starterP.cheeseSticks * 1.10, aux.starterP.garlicBread * 1.10, aux.starterP.pizzaRolls * 1.10) + (aux.drinksP.beer * 1.35, aux.drinksP.soda * 1.35, aux.drinksP.iceTea * 1.35) + 15);
    cout << "El tiempo de espera de la orden del cliente es: " << aux.timeP << "minutos" << endl; 

    orders.push_back(aux);
    cout << endl;

}

void RestaurantOrders()
{
    pRestaurant aux;
    bool continuar = true;
    int option = 0, option2 = 0, option3 = 0;
    orderNumber = orderNumber + 1;
    float pizza = 13.99, pasta = 5.55, lasagna = 6.25, beer = 1.99, soda = 0.95, iceTea = 1.15, pizzaRolls = 4.99, cheeseSticks = 3.75, garlicBread = 3.99;

    cout << "\nNúmero de orden #" << orderNumber << endl;
    cout << "Ingrese el nombre de la reserva: ";
    cin.ignore();
    getline(cin, aux.reserva);

    do
    {

        cout << "¿Cuantas personas por mesa: ";
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
                            cin >> aux.dishQ.pizza;
                            monto = monto + (pizza * aux.dishQ.pizza);
                            break;
                        case 2:
                            cout << "\n¿Cuantas pastas desea ordenar?: ";
                            cin >> aux.dishQ.pasta;
                            monto = monto + (pasta * aux.dishQ.pasta);
                            break;
                        case 3:
                            cout << "\n¿Cuantas lasagnas desea ordenar?: ";
                            cin >> aux.dishQ.lasagna;
                            monto = monto + (lasagna * aux.dishQ.lasagna);
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
                            cin >> aux.starterQ.cheeseSticks;
                            monto = monto + (cheeseSticks * aux.starterQ.cheeseSticks);
                            break;
                        case 2:
                            cout << "\n¿Cuantas ordenes de pan con ajo desea ordenar?: ";
                            cin >> aux.starterQ.garlicBread;
                            monto = monto + (garlicBread * aux.starterQ.garlicBread);
                            break;
                        case 3:
                            cout << "\n¿Cuantas ordenas de pizza rolls desea ordenar?: ";
                            cin >> aux.starterQ.pizzaRolls;
                            monto = monto + (pizzaRolls * aux.starterQ.pizzaRolls);
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
                            cin >> aux.drinksQ.beer;
                            monto = monto + (beer * aux.drinksQ.beer);
                            break;
                        case 2:
                            cout << "\n¿Cuantas sodas desea ordenar?: ";
                            cin >> aux.drinksQ.soda;
                            monto = monto + (soda * aux.drinksQ.soda);
                            break;
                        case 3:
                            cout << "\n¿Cuantos té helado desea ordenar?: ";
                            cin >> aux.drinksQ.iceTea;
                            monto = monto + (iceTea * aux.drinksQ.iceTea);
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
            if(option3 == 1)
            aux.payQ = cash;
            else{
            aux.payQ = card;
    }
            cin.ignore();
            restaurantP.push_back(aux);
            
        }
        else
        {
            cout << "Máximo 5 personas por mesa" << endl;
        }
    } while (continuar);


    aux.timeQ = ((aux.dishQ.pasta * 1.5, aux.dishQ.pizza * 1.5, aux.dishQ.lasagna * 1.5) + (aux.starterQ.cheeseSticks * 1.10, aux.starterQ.garlicBread * 1.10, aux.starterQ.pizzaRolls * 1.10) + (aux.drinksQ.beer * 1.35, aux.drinksQ.soda * 1.35, aux.drinksQ.iceTea * 1.35) + 15);
    cout << "El tiempo de espera de la orden del cliente es: " << aux.timeQ << "minutos" << endl; 

    restaurantP.push_back(aux);
    cout << endl;
}

void WatchDelivery(Delivery aux)
{
    cout << endl;
    cout << "-------------------------------";
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
    cout << "\nMonto total: $" << monto << " dólares" << endl;

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
}

void WatchDeliveryOrders()
{
    for (int i = 0; i < orders.size(); i++)
    {
        WatchDelivery(orders[i]);
    }
}

void WatchRestaurant(pRestaurant aux)
{
    cout << endl;
    cout << "-------------------------------";
    cout << "\n---Datos del cliente---";
    cout << "\nNúmero de orden: #" << orderNumber;
    cout << "\nNombre del cliente: " << aux.reserva;
    cout << "\nPersonas por mesa: " << PerTable << endl;
    cout << "---Orden del cliente---\n";
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
        cout << "Ordenes de cheese Sticks: " << aux.starterQ.cheeseSticks << endl;
    }
    if (aux.starterQ.garlicBread != 0)
    {
        cout << "Ordenes de pan con ajo: " << aux.starterQ.garlicBread << endl;
    }
    if (aux.starterQ.pizzaRolls != 0)
    {
        cout << "Ordenes de pizza Rolls: " << aux.starterQ.pizzaRolls << endl;
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
    cout << "\nMonto total: $" << monto << " dólares" << endl;
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

void WaitTime(vector<Delivery> orders) //sobrecarga
{
    float sum = 0, result;
    Delivery aux;

    for(Delivery aux : orders){
     sum += ((aux.dishP.pasta * 1.5, aux.dishP.pizza * 1.5, aux.dishP.lasagna * 1.5) + (aux.starterP.cheeseSticks * 1.10, aux.starterP.garlicBread * 1.10, aux.starterP.pizzaRolls * 1.10) + (aux.drinksP.beer * 1.35, aux.drinksP.soda * 1.35, aux.drinksP.iceTea * 1.35) + 15);
    }
    result = ceil(sum);
    cout << "\nEl tiempo total de espera de las ordenes es: " << sum << " minutos" << endl; 

}

void WaitTime(vector<pRestaurant> restaurantP) //sobrecarga
{
   float sum = 0, result;
   pRestaurant aux;

    for(pRestaurant aux : restaurantP){
     sum += ((aux.dishQ.pasta * 1.5, aux.dishQ.pizza * 1.5, aux.dishQ.lasagna * 1.5) + (aux.starterQ.cheeseSticks * 1.10, aux.starterQ.garlicBread * 1.10, aux.starterQ.pizzaRolls * 1.10) + (aux.drinksQ.beer * 1.35, aux.drinksQ.soda * 1.35, aux.drinksQ.iceTea * 1.35) + 15);
    }
    result = ceil(sum);
    cout << "\nEl tiempo total de espera de las ordenes es: " << result << " minutos" << endl; 
}

void CancelOrder()
{
}

void CalculateTotalSales()
{
}