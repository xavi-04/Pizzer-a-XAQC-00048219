
int option2 = 0;

do
{
    cout << "\n***Elija su orden***" << endl;
    cout << "\n1. Plato Principal";
    cout << "\n2. Entraditas";
    cout << "\n3. Bebidas";
    cout << "\n4. Salir";
    cout << "\nOpcion: ";
    cin >> option2;
    cin.ignore;

    switch (option2)
    {
    case 1:
        cout << "\n---------------------" << endl;
        cout << "***Plato Principal***" << endl;
        cout << "---------------------" << endl;
     
     do
	{
		cout << "1. Pizza\n2. Pasta\n3. Lasagna\n4. Salir";
        cout << "\nOpcion: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "¿Cuantas pizzas desea ordenar?: ";
			cin >> aux1.pizza;
			break;
		case 2:
			cout << "¿Cuantas pastas desea ordenar?: ";
			cin >> aux1.pasta;
			break;
		case 3:
			cout << "¿Cuantas lasagnas desea ordenar?: ";
			cin >> aux1.lasagna;
			break;
		default: 
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
		}
	} while (option != 4);
        break;

    case 2:
        cout << "\n----------------" << endl;
    cout << "***Entraditas***" << endl;
    cout << "----------------" << endl;

     do
	{
		cout << "1. Cheese Sticks\n2. Pan con ajo\n 3. Pizza Rolls\n 4. Salir";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "¿Cuantas ordenes de cheese sticks desea ordenar?: ";
			cin >> aux2.cheeseSticks;
			break;
		case 2:
			cout << "¿Cuantas ordenes de pan con ajo desea ordenar?: ";
			cin >> aux2.garlicBread;
			break;
		case 3:
			cout << "¿Cuantas ordenas de pizza rolls desea ordenar?: ";
			cin >> aux2.pizzaRolls;
			break;
		default: 
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
		}
	} while (option != 4);
        break;
    case 3:
    cout << "\n-------------" << endl;
    cout << "***Bebidas***" << endl;
    cout << "-------------" << endl;
   
    do
	{
		cout << "1. Cervezas\n2. Sodas\n 3. Té helado\n 4. Salir";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "¿Cuantas cervezas desea ordenar?: ";
			cin >> aux3.beer;
			break;
		case 2:
			cout << "¿Cuantas sodas desea ordenar?: ";
			cin >> aux3.soda;
			break;
		case 3:
			cout << "¿Cuantos té helado desea ordenar?: ";
			cin >> aux3.iceTea;
			break;
		default: 
            cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
            break;
		}
	} while (option != 4);
        break;

    default:
        cout << "¡¡¡Dato erróneo!!!, intente de nuevo" << endl;
        break;
    }
} while (option2 != 4)

    