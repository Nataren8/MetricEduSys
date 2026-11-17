#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante
{
    int carnet;
    string nombre;
    string apellido;
    float notas[3];
};

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

/*Funcion para guardar los datos del estudiante*/

void registrarEstudiante(Estudiante &e)
{
    cout << "Ingresa el carnet: " << endl;
    cin >> e.carnet;
    cout << "Ingresa el nombre: " << endl;
    cin >> e.nombre;
    cout << "Ingresa el apellido: " << endl;
    cin >> e.apellido;
    /*Bucle for para pedir notas y validar que estén entre 0 y 10*/
    for (int i = 0; i < 3; i++)
    {
        do
        {
            cout << "Ingrese la nota del registro " << i + 1 << endl;
            cin >> e.notas[i];
            if (e.notas[i] < 0 or e.notas[i] > 10)
            {
                cout << "ERROR! Ingrese un dato valido..." << endl;
            }
            else
            {
                cout << "Dato ingresado correctamente..." << endl;
            }
        } while (e.notas[i] < 0 or e.notas[i] > 10);
    }

    cout << "Todas los datos se han registrado correctamente" << endl;
}

/*Funcion para guardar los datos del estudiante en un archivo .txt*/

void guardarEstudiante(Estudiante e)
{
    ofstream archivo("estudiante.txt", ios::app);

    archivo << e.carnet << " ";
    archivo << e.nombre << " ";
    archivo << e.apellido << " ";

    for (int i = 0; i < 3; i++)
    {
        archivo << " " << e.notas[i];
    }

    archivo << endl;
    archivo.close();
}

int contarEvaluaciones()
{
    ifstream archivo("estudiante.txt");
    string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        contador += 3;
    }
    archivo.close();
    return contador;
}

float promedioEvaluaciones()
{
    ifstream archivo("estudiante.txt");
    Estudiante e;
    float suma = 0;
    int cantidad = 0;

    while (archivo >> e.carnet >> e.nombre >> e.apellido)
    {
        for (int i = 0; i < 3; i++)
        {
            archivo >> e.notas[i];
            suma += e.notas[i];
            cantidad++;
        }
    }
    
    archivo.close();

    if (cantidad == 0)
    {
        return 0;
    }

    return suma / cantidad;
}
int main()
{
    Estudiante alumno; // Variable para llamar el void Registrar Estudiante
    int opcion = 0;
    int evaluaciones;

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
            registrarEstudiante(alumno);
            guardarEstudiante(alumno);
            break;

        case 2:
            /*Funcion cuadro de honor*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 3:
            /*Funcion de Estadistica-Evaluaciones registradas*/
            evaluaciones = contarEvaluaciones();
            cout << "El total de evaluaciones registradas es: " << evaluaciones << endl;
            cout << "El promedio general es de: " << promedioEvaluaciones() << endl;
            break;

        case 4:
            /*Funcion del cuadro de honor*/
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