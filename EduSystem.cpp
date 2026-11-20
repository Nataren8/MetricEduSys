#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*ESTABLECEMOS LA NOTA MÍNIMA DE 6.0*/
const float NOTA_MINIMA = 6.0;

/*DATOS DEL ESTUDIANTE*/
struct Estudiante
{
    string nombres;
    string apellidos;
    string curso;
    string identificador;
    float nota1 = 0;
    float nota2 = 0;
    float nota3 = 0;
};

/*FUNCIÓN PARA MOSTRAR EL MENÚ*/
void mostrarMenu()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "¡Bienvenido a MetricEduSystem!" << endl;
    cout << "Ingresa el numero de opcion que necesitas realizar" << endl;
    cout << "(1) Registrar Estudiante" << endl;
    cout << "(2) Editar notas de estudiantes " << endl;
    cout << "(3) Visualizar Cuadro de honor " << endl;
    cout << "(4) Visualizar Estadisticas " << endl;
    cout << "(5) Visualizar Cuadro de honor " << endl;
    cout << "(6) Visualizar promedio de clases" << endl;
    cout << "(7) Visualizar metricas de estudiantes aprobados y reprobados " << endl;
    cout << "(8) Visualizar notas maximas y minimas registradas en el curso" << endl;
    cout << "(9) Visualizar datos individuales de cada estudiante " << endl;
    cout << "(10) Salir del sistema " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

/*FUNCIÓN PARA AGREGAR ESTUDIANTES*/
int registrarEstudiante(Estudiante estudiantes[], int cantidadEstudiantes)
{
    int regopcion = 0;

    do
    {
        cout << "-----------------------------" << endl;
        cout << "---REGISTRO DE ESTUDIANTES---" << endl;
        cout << "-----------------------------" << endl;

        cout << "\nIngrese el nombre del estudiante: ";
        getline(cin >> ws, estudiantes[cantidadEstudiantes].nombres);

        cout << "\nIngrese los apellidos del estudiante: ";
        getline(cin >> ws, estudiantes[cantidadEstudiantes].apellidos);

        cout << "\nIngrese el nombre del curso del estudiante: ";
        getline(cin >> ws, estudiantes[cantidadEstudiantes].curso);

        cout << "\nIngrese el codigo del estudiante: ";
        cin >> estudiantes[cantidadEstudiantes].identificador;

        cantidadEstudiantes = cantidadEstudiantes + 1;

        cout << "\nSi desea realizar el ingreso de otro estudiante presione (1), si desea volver al menu principal presione (0)" << endl;
        cin >> regopcion;

        if (regopcion < 0 || regopcion > 1)
        {
            cout << "\nIngreso incorrecto, se le redirigiendo hacia el menu......." << endl;
            regopcion = 0;
        }

    } while (regopcion != 0);

    return cantidadEstudiantes; // aqui retorno el valor de la cantidad de estudiantes para poder crear la siguiente funcion que sera de notas
}

/*FUNCIÓN PARA GUARDAR NOTAS*/
void guardarNotas(Estudiante estudiantes[], int cantidadEstudiantes)
{
    ofstream archivo("estudiantes.txt");

    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        archivo << estudiantes[i].identificador << " "
                << estudiantes[i].nombres << " "
                << estudiantes[i].apellidos << " "
                << estudiantes[i].curso << " "
                << estudiantes[i].nota1 << " "
                << estudiantes[i].nota2 << " "
                << estudiantes[i].nota3 << endl;
    }

    archivo.close();
}

/*FUNCIÓN PARA REGISTRAR NOTAS Y QUEDAN GUARDADAS EN ARCHIVO*/
void registroNotas(Estudiante estudiantes[], int cantidadEstudiantes)
{
    int opcionMenu = 0;

    do
    {

        for (int i = 0; i < cantidadEstudiantes; i++)
        {
            cout << "-----------------------------" << endl;
            cout << "------REGISTRO DE NOTAS------" << endl;
            cout << "-----------------------------" << endl;
            cout << "\nEstudiante" << "(" << i + 1 << ")";
            cout << "\nNombre del estudiante: " << estudiantes[i].nombres;
            cout << "\nApellidos del estudiante: " << estudiantes[i].apellidos;
            cout << "\nNombre del curso del estudiante: " << estudiantes[i].curso;
            cout << "\nCodigo del estudiante: " << estudiantes[i].identificador;
            cout << "\nSi desea realizar un ingreso o actualizacion a la primera nota ingrese (1)";
            cout << "\nSi desea realizar un ingreso o actualizacion a la segunda nota ingrese (2)";
            cout << "\nSi desea realizar un ingreso o actualizacion a la tercera nota ingrese (3)";
            cout << "\nIngrese (4) si desea pasar hacia el siguiente estudiante\n";

            cin >> opcionMenu;

            switch (opcionMenu)
            {

            case 1:
                cout << "Ingrese la primera nota: ";
                cin >> estudiantes[i].nota1;
                break;
            case 2:
                cout << "Ingrese la segunda nota: ";
                cin >> estudiantes[i].nota2;
                break;
            case 3:
                cout << "Ingrese la tercera nota: ";
                cin >> estudiantes[i].nota3;
                break;
            case 4:
                cout << "Pasando al siguiente estudiante...";
                break;
            default:
                cout << "Ingrese una opcion valida";
            }
        }

        cout << "\nIngrese la opcion [4] para volver al menu, u otro numero para hacer mas cambios" << endl;
        cin >> opcionMenu;

    } while (opcionMenu != 4);

    guardarNotas(estudiantes, cantidadEstudiantes);
    cout << "Cambios guardados. Regresando al menu..." << endl;
}

/* FUNCIÓN PARA CALCULAR EL PROMEDIO DE CADA ESTUDIANTE */

void calcularPromedio()
{
    Estudiante estudiantes;
    float promedioNotas = 0;
    float sumaNotas = 0;

    ifstream archivo("estudiantes.txt");

    while (archivo >> estudiantes.identificador >> estudiantes.nombres >> estudiantes.apellidos >> estudiantes.curso >> estudiantes.nota1 >> estudiantes.nota2 >> estudiantes.nota3)
    {
        sumaNotas = estudiantes.nota1 + estudiantes.nota2 + estudiantes.nota3;
        promedioNotas = sumaNotas / 3;
        cout << estudiantes.nombres << " " << estudiantes.apellidos << " || PROMEDIO: " << promedioNotas << endl;
    }

    archivo.close();
}

int main()
{
    Estudiante estudiantes[200]; // Esto solo es un valor quemado para la cantidad de estudiantes que podemos meter en la plataforma.
    int CantidadEstudiantes = 0;

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
            //
            CantidadEstudiantes = registrarEstudiante(estudiantes, CantidadEstudiantes);
            /*esto nada mas lo cree para que puedan ver si de verdad guardaba la cantidad y no tiraba error*/
            cout << "\ncantidad de estudiantes:  " << CantidadEstudiantes << endl;

            /*Esto lo cree para poder observar si, podia mostrarlos los estudiantes o si tenia error, despues lo metemos en funcion xd.
            cout<<"\nEstudiantes registrados: "<<endl;


            for(int i = 0; i < CantidadEstudiantes; i++){

            cout<<"\nEstudiante "<<"("<<i + 1<<")"<<endl;
            cout << "\nNombre del estudiante: "<<estudiantes[i].nombres;
            cout << "\nApellidos del estudiante: "<<estudiantes[i].apellidos;
            cout << "\nNombre del curso del estudiante: "<<estudiantes[i].curso;
            cout << "\nCodigo del estudiante: "<<estudiantes[i].identificador<<endl;
            cout<< endl;
            }*/

            break;

        case 2:

            registroNotas(estudiantes, CantidadEstudiantes);

            /* este bloque de codigo es para mostrar la informacion completa de los estudiantes y sus notas, de aqui se pueden basar para hacer las partes de notas
            individuales y etc.

            for(int i = 0; i < CantidadEstudiantes; i++){

             cout<<"\nEstudiante "<<"("<<i + 1<<")"<<endl;
             cout << "\nNombre del estudiante: "<<estudiantes[i].nombres;
             cout << "\nApellidos del estudiante: "<<estudiantes[i].apellidos;
             cout << "\nNombre del curso del estudiante: "<<estudiantes[i].curso;
             cout << "\nCodigo del estudiante: "<<estudiantes[i].identificador<<endl;
             cout << "\nNota 1: "<<estudiantes[i].nota1<<endl;
             cout << "\nNota 2: "<<estudiantes[i].nota2<<endl;
             cout << "\nNota 3: "<<estudiantes[i].nota3<<endl;
             cout<< endl;
             }*/

            break;

        case 3:

            /*cuadro de honor */

            break;

        case 4:
            /*Funcion de estadisticas*/

            break;

        case 5:
            calcularPromedio();
            break;

        case 6:
            /*Funcion de metricas de estudiantes aprobados y reprobados*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 7:
            /*Funcion notas maximas y minimas registradas en el curso*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 8:
            /*Funcion datos generales e individuales de cada estudiante/ y busqueda de
            cada estudiantes con identificador unico*/
            cout << "Trabajando en ello..." << endl;
            break;

        case 9:
            break;

        case 10:
            cout << "Saliendo del sistema....." << endl;
            break;
        }

        if (opcion > 10 || opcion < 1)
        {
            cout << endl;
            cout << "Ingresa una opcion valida..." << endl;
            cout << endl;
        }

    } while (opcion != 10);

    return 0;
}
