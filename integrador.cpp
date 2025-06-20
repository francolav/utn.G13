#include "integrador.h"

void registrarJugadores (Jugador &jugador1, Jugador &jugador2)
{
    string respuesta;
    do
    {
        system("cls");
        cout << "TREY\n--------------------------------------------------------\n";
        cout << "Antes de comenzar deben registrar sus nombres:\n";
        cout << "Ingrese el nombre del jugador numero 1: ";
        cin >> jugador1.nombre;
        cout << "Ingrese el nombre del jugador numero 2: ";
        cin >> jugador2.nombre;
        cout << " ¿Confirmar nombres? (S/N): ";
        cin >> respuesta;
        cout << endl;
    }
    while (respuesta == "N" || respuesta == "n");
}

void tomarCarta (Jugador &jugador)
{
    int carta = rand() % 15 + 50;
    int valor;

    if (carta < 56)
    {
        valor = 7;
    }
    else if (carta < 61)
    {

        valor = 8;
    }
    else
    {

        valor = 9;
    }

    jugador.carta = carta;
    jugador.puntosTiempo = valor;
    cout << "El jugador " << jugador.nombre << " ha tomado la carta: " << jugador.carta << endl;
    cout << "Los puntos de tiempo que le han tocado son: " << jugador.puntosTiempo << endl;
}


void turnoJugador  (Jugador &jugador)
{
    bool continuar = true;
    char respuesta;
    int cantidadDados;
    int dado [3], suma, contBugs = 0;
    int ronda = 1;

    while (jugador.puntosTiempo > 0 && continuar && jugador.turno == true && jugador.puntos != jugador.carta)
    {
        system("cls");
        cout << "--------------------------TREY------------------------------" << endl;
        cout << "TURNO DE " << jugador.nombre << endl;
        cout << "+---------------------------------+\n" ;
        cout << "| RONDA #" << ronda <<"------------------------|"<<endl;
        cout << "| PUNTOS DE LA RONDA: " << jugador.puntos <<"-----------|"<< endl;
        cout << "| LANZAMIENTO: #" << jugador.lanzamientos <<"-----------------|"<< endl;
        cout << "+---------------------------------+\n";

        cout << "                         TREY" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << jugador.nombre << ": " << jugador.puntos << " de " << jugador.carta << "    ";

        cout << "PT: " << jugador.puntosTiempo << " BUGS: " << jugador.bugs<< "       " << endl;



        if (jugador.lanzamientos > 1)
        {
            cout << " ¿Desea continuar lanzando? (Y/N): ";
            cin >> respuesta;
            if (respuesta == 'N' || respuesta == 'n')
            {
                continuar = false;
                break;
            }
        }

        if (jugador.puntosTiempo >= 2 | !continuar)
        {
            cout << " ¿Con cuantos dados desea lanzar? (2 o 3): ";
            cin >> cantidadDados;

            if (cantidadDados == 2)
            {
                jugador.puntosTiempo--;
            }
            else if (cantidadDados == 3)
            {
                jugador.puntosTiempo -= 2;
            }
            else
            {
                cout << "Opcion invalida.";
            }
        }
        else
        {
            cantidadDados = 2;
            jugador.puntosTiempo--;
        }

        // Lanzamiento de dados
        dado [0] = rand() % 6 + 1;
        dado [1] = rand() % 6 + 1;
        dado [2] = rand() % 6 + 1;

        cout << "Dados lanzados: ";
        if (cantidadDados == 2)
        {
            cout << dado [0] << " " << dado [1] << endl;
            suma = dado [0] + dado [1];
            for (int x = 0; x < 2; x ++)
            {
                if (dado [x] == 1)
                {
                    contBugs ++;
                }
            }
        }
        else
        {
            cout << dado [0] << " " << dado [1] << " " << dado [2] << endl;
            suma = dado [0] + dado [1] + dado [2];
            for (int x = 0; x < 3; x ++)
            {
                if (dado [x] == 1)
                {
                    contBugs ++;
                }
            }
        }


        contBugs;

        if (contBugs == 3)
        {
            jugador.puntosTiempo - 2;
            jugador.bugs + 3;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO Y PERDES DOS PUNTOS DE TIEMPO" << endl;
            jugador.turno = false;
        }
        else if (contBugs == 2 )
        {
            jugador.puntosTiempo -1;
            jugador.bugs +2;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO Y PERDES 1 PUNTO DE TIEMPO" << endl;
            jugador.turno = false;
        }
        else if (contBugs == 1)
        {
            jugador.bugs ++;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO " << endl;
            jugador.turno = false;
        }

        if (contBugs == 0)
        {

            jugador.puntos += suma;
        }
        jugador.lanzamientos++;
        ronda++;
        if (jugador.puntosTiempo == 0)
        {
            jugador.turno = false;
        }


        system("pause");
    }
}

void mostrarEstadoJugadores  (const Jugador &j1, const Jugador &j2)
{
    cout << j1.nombre << ": " << j1.puntos <<" puntos " << "de  " << j1.carta << "| PT: " << j1.puntosTiempo << " | BUGS: " << j1.bugs << endl;
    cout << j2.nombre << ": " << j2.puntos << " puntos " << "de  " << j2.carta << "| PT: " << j2.puntosTiempo << " | BUGS: " << j2.bugs << endl;
}


void turnoJugador  (Jugador2 &jugador2)
{
    bool continuar = true;
    char respuesta;
    int cantidadDados;
    int dado [3], suma, contBugs = 0;
    int ronda = 1;

    while (jugador2.puntosTiempo > 0 && continuar && jugador2.turno == true && jugador2.puntos != jugador2.carta)
    {
        system("cls");
        cout << "--------------------------TREY------------------------------" << endl;
        cout << "TURNO DE " << jugador2.nombre << endl;
        cout << "+---------------------------------+\n" ;
        cout << "| RONDA #" << ronda <<"------------------------|"<<endl;
        cout << "| PUNTOS DE LA RONDA: " << jugador2.puntos <<"-----------|"<< endl;
        cout << "| LANZAMIENTO: #" << jugador2.lanzamientos <<"-----------------|"<< endl;
        cout << "+---------------------------------+\n";

        cout << "                         TREY" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << jugador2.nombre << ": " << jugador2.puntos << " de " << jugador2.carta << "    ";

        cout << "PT: " << jugador2.puntosTiempo << " BUGS: " << jugador2.bugs<< "       " << endl;



        if (jugador2.lanzamientos > 1)
        {
            cout << " ¿Desea continuar lanzando? (Y/N): ";
            cin >> respuesta;
            if (respuesta == 'N' || respuesta == 'n')
            {
                continuar = false;
                break;
            }
        }

        if (jugador2.puntosTiempo >= 2 | !continuar)
        {
            cout << " ¿Con cuantos dados desea lanzar? (2 o 3): ";
            cin >> cantidadDados;

            if (cantidadDados == 2)
            {
                jugador2.puntosTiempo--;
            }
            else if (cantidadDados == 3)
            {
                jugador2.puntosTiempo -= 2;
            }
            else
            {
                cout << "Opcion invalida.";
            }
        }
        else
        {
            cantidadDados = 2;
            jugador2.puntosTiempo--;
        }

        // Lanzamiento de dados
        dado [0] = rand() % 6 + 1;
        dado [1] = rand() % 6 + 1;
        dado [2] = rand() % 6 + 1;

        cout << "Dados lanzados: ";
        if (cantidadDados == 2)
        {
            cout << dado [0] << " " << dado [1] << endl;
            suma = dado [0] + dado [1];
            for (int x = 0; x < 2; x ++)
            {
                if (dado [x] == 1)
                {
                    contBugs ++;
                }
            }
        }
        else
        {
            cout << dado [0] << " " << dado [1] << " " << dado [2] << endl;
            suma = dado [0] + dado [1] + dado [2];
            for (int x = 0; x < 3; x ++)
            {
                if (dado [x] == 1)
                {
                    contBugs ++;
                }
            }
        }


        contBugs;

        if (contBugs == 3)
        {
            jugador2.puntosTiempo - 2;
            jugador2.bugs + 3;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO Y PERDES DOS PUNTOS DE TIEMPO" << endl;
            jugador2.turno = false;
        }
        else if (contBugs == 2 )
        {
            jugador2.puntosTiempo -1;
            jugador2.bugs +2;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO Y PERDES 1 PUNTO DE TIEMPO" << endl;
            jugador2.turno = false;
        }
        else if (contBugs == 1)
        {
            jugador2.bugs ++;
            cout << "OBTUVISTE:  " << contBugs << "BUGS, PERDES EL TURNO " << endl;
            jugador2.turno = false;
        }

        if (contBugs == 0)
        {

            jugador2.puntos += suma;
        }
        jugador2.lanzamientos++;
        ronda++;

        if (jugador2.puntosTiempo == 0)
        {
            jugador2.turno = false;
        }

        system("pause");
    }
}
