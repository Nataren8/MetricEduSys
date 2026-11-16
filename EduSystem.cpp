#include <iostream>
#include <fstream>

using namespace std;

/*Ricardo y camilo, les dejare comentarios para que logren entender a profundidad*/

void mostrarMenu()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "¡Bienvenido a MetricEduSystem!" << endl;
    cout << "Ingresa el numero de opcion que necesitas realizar" << endl;
    cout << "(1) Registrar Estudiante" << endl;
    cout << "(2) Visualizar Cuadro de honor " << endl;
    cout << "(3) Visualizar Estadisticas " << endl;
    cout << "(4) Visualizar Cuadro de honor " << endl;
    cout << "(5) Visualizar promedio de clases" << endl;
    cout << "(6) Visualizar metricas de estudiantes aprobados y reprobados " << endl;
    cout << "(7) Visualizar notas maximas y minimas registradas en el curso" << endl;
    cout << "(8) Visualizar datos individuales de cada estudiante " << endl;
    cout << "(9) Salir del sistema " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

int main()
{

    /*Ricardo: Voy a agregar unas variables para empezar a probar las estadísticas */
    const int num_notas = 3; /*Vamos a probar registrando 3 notas*/
    float notas[num_notas];
    float sumatoria_notas;
    int opcion = 0;

    do
    {
        mostrarMenu();
        cin >> opcion;
        /*para cada caso, le utilizaremos para las diferentes funciones, se puede editar
        en caso de que existan mas funciones.*/
        switch (opcion)
        {
        case 1:
            /*Funcion registro de estudiantes*/

            break;

        case 2:
            /*Funcion cuadro de honor*/

            break;

        case 3:
            for (int i = 0; i < num_notas; i++)
            {
                do
                {
                    cout << "Registre la nota " << i + 1 << ": ";
                    cin >> notas[i];

                    if (notas[i] > 10 or notas[i] < 0)
                    {
                        cout << "Ingrese una nota valida (entre 0 y 10)" << endl;
                    }

                } while (notas[i] > 10 or notas[i] < 0);

                sumatoria_notas += notas[i];
            }
            cout << "El promedio total de notas es: " << sumatoria_notas / num_notas << endl;
            break;

        case 4:
            cout << "Trabajando en ello..." << endl;
            break;

        case 5:
            /*Funcion de metricas de estudiantes aprobados y reprobados*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 6:
            /*Funcion notas maximas y minimas registradas en el curso*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 7:
            /*Funcion datos generales e individuales de cada estudiante/ y busqueda de
            cada estudiantes con identificador unico*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 8:
            /*Funcion cuadro de honor*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 9:
            cout << "Saliendo del sistema....." << endl;
            break;
        }

        if (opcion > 9)
        {
            cout << endl;
            cout << "Ingresa una opcion valida..." << endl;
            cout << endl;
        }

    } while (opcion != 9);

    return 0;
}