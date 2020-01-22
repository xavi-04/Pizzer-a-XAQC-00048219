#include <iostream>
#include <string>

#define PASSWORD "struct"

using namespace std;

struct address
{
    string settlement, municipality, departament;
    int houseNumber;
};

enum mainDish
{
    pizza,
    pasta,
    lasgna
};
enum drink
{
    beer,
    soda,
    tea
};
enum starter
{
    GarlickBread,
    pizzaRolls,
    cheeseSticks
};
enum paymentType
{
    cash,
    card
};

struct mainInfo
{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymentType pay;
    //plato principal
    //entrada
    //bebdida
    //tipo de pago

    int idOrder;
    float total;
};

struct delivery
{
    address deliveryAddress;
    int cellPhone;
    mainInfo deliveryInfo;
};

struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};

bool isAdmin = false;
int idOrder;
bool loginUser(void);

int main(void)
{
    delivery* dArray = NULL;
    houseOrder* dArray = NULL;
    int option = 0;
    if (loginUser())
        return 0;

        do{
            printMenu(); cin >> option;
            cin.ignore();
        }

    return 0;
}

bool loginUser(void)
{
    string enterPass = " ";
    char option;
    cout << " Inicio de sesión " << endl;
    cout << " A - Administrador " << endl;
    cout << " E - Empleado " << endl;
    cout << " Su opcion: \t";
    cin >> option;

    switch (option)
    {
    case 'a':
    case 'A':
        cout << " Digite la contraseña: ";
        cin >> enterPass;
        if (enterPass.compare(PASSWORD) == 0)
        {
            isAdmin = true;
            return true;
        }
        else
        {
            cout << " Contraseña incorrecta" << endl;
        }

        break;

    case 'e':
    case 'E':
        isAdmin = false;
        return true;
        break;
    }
    return false;
}

void printMenu(void){
    cout << " SISTEMA DE DESPACHO PIZZERIA XXXXXXXXXXXXX " << endl;
    cout << " 1. Agregar ordenes a domicilio " << endl;
    cout << " 2. Agregar ordenes en restaurante " << endl;
    cout << " 3. Ver ordenes a domicilio " << endl;
    cout << " 4. ver ordenes en restaurante " << endl;
    cout << " Su opcion:\t";
 

}

void adOrder(delivery* array){
    int size = 0;
    cout << " Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new delivery[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre:\t";getline(cin, array[i].deliveryInfo.name);
        cout << " Dirección: " << endl;
        cout << "Colonia:\t";getline(cin, array[i].deliveryAddress.settlement);
         cout << "Municipio:\t";getline(cin, array[i].deliveryAddress.municipality);
          cout << "Departamento:\t";getline(cin, array[i].deliveryAddress.departament);
           cout << "No. Casa:\t"; cin >> array[i].deliveryAddress.houseNumber;
           cin.ignore();

           cout << "Plato principal" << endl;
           cout << " 1. Pizza" << endl;
           cout << " 2. Pasta" << endl;
           cout << " 3. Lasgna" << endl;
           cout << " 1. Pizza" << endl;
           cout << " Su opcion:\t"; cin >> aux;

           if(aux == 1)
           array[1].deliveryInfo.pDish = pizza;
           else if( aux == 2)
           array[i].deliveryInfo.pDish = pasta;
           else
           array[i].deliveryInfo.pDish = lasgna;

           array[i].deliveryInfo.p.Dish;


            cout << "monto: ";cin >> array[i].deliveryInfo.total;
            cin.ignore();
            cout << "Telefono: "; cin >> array[i].cellPhone;
            cin.ignore();





    }
}

void addOrder(houseOrder* array){

}

void searchByName(delivery* array, int size){
    bool userExists = false;
    string aux = " ";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].deliveryInfo.name) == 0){
            userExists = true;
        }
    }
    (userExists) ? cout << "NOexiste el usuario" : cout << " ";
}

void searchByName(houseOrder* array, int size){
    bool userExists = false;
    string aux = " ";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].houseInfo.name) == 0){
            userExists = true;
        }
    }
    (userExists) ? cout << "NOexiste el usuario" : cout << " ";
}