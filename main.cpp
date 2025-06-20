#include <iostream>
#include <ctime>
#include "integrador.h"
 #include <clocale>

using namespace std;
setlocale(LC_ALL, "spanish");

int main()
{
    srand (time (NULL));

    Jugador jugador1, jugador2;
    int opcion;

    while (true)
    {

        // Mostrar el menú
        system ("cls");

        cout << "===== TREY =====" << endl;
        cout << R"(

          (o_o)
         <)   )╯
         /|   |
        /_|___|
       /______\
     _|________|_
    |  [_c++_]   |
    |   ______   |
    |  |      |  |
    |__|______|__|
   [______________]
    )" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "--------------------" << endl;
        cout << "0 -  Salir" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        switch(opcion)
        {
        case 1:

            registrarJugadores (jugador1, jugador2);

            tomarCarta (jugador1);

            tomarCarta (jugador2);

            system ("pause");

            system ("cls");

            mostrarEstadoJugadores  (jugador1, jugador2);
            system ("pause");

            while (jugador1.puntosTiempo != 0 || jugador2.puntosTiempo != 0)
            {
                if (jugador1.turno)
                {
                    turnoJugador (jugador1);

                }
                else
                {
                    turnoJugador (jugador2);

                }

            }

            if (jugador1.turno)
            {
                turnoJugador (jugador1);

            }
            else
            {
                turnoJugador (jugador2);

            }


            mostrarEstadoJugadores  (jugador1, jugador2);
            system ("pause");



            break;

        case 2:
            system ("cls");
            cout << "Has seleccionado la Opción 2." << endl;
            system ("pause");
            break;
        case 3:
            system ("cls");
            cout << "Has seleccionado la Opción 3." << endl;
            system ("pause");
            break;
        case 0:
            return 0;
            break;
        default:
            system ("cls");
            cout << "Opción no válida. Intente de nuevo." << endl;
            system ("pause");
        }


    }
}


