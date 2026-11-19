#include <iostream>

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
        cout << "\nIngrese los datos del estudiante: " << endl;

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

/*FUNCIÓN PARA REGISTRAR NOTAS*/
void registroNotas(Estudiante estudiantes[], int cantidadEstudiantes)
{

    int op = 0;

    do
    {

        for (int i = 0; i < cantidadEstudiantes; i++)
        {

            cout << "Estudiante" << "(" << i + 1 << ")";
            cout << "\nNombre del estudiante: " << estudiantes[i].nombres;
            cout << "\nApellidos del estudiante: " << estudiantes[i].apellidos;
            cout << "\nNombre del curso del estudiante: " << estudiantes[i].curso;
            cout << "\nCodigo del estudiante: " << estudiantes[i].identificador << endl;

            cout << "\nSi desea realizar un ingreso o actualizacion a la primera nota ingrese (1)";
            cout << "\nSi desea realizar un ingreso o actualizacion a la segunda nota ingrese (2)";
            cout << "\nSi desea realizar un ingreso o actualizacion a la tercera nota ingrese (3)";
            cout << "\nIngrese (4) si desea pasar hacia el siguiente estudiante" << endl;

            cin >> op;

            if (op == 1)
            {
                cout << "\nIngrese la primera nota: ";
                cin >> estudiantes[i].nota1;
            }
            else if (op == 2)
            {
                cout << "\nIngrese la segunda nota: ";
                cin >> estudiantes[i].nota2;
            }
            else if (op == 3)
            {
                cout << "\nIngrese la tercera nota: ";
                cin >> estudiantes[i].nota3;
            }
            else
            {

                cout << "\nMostrando siguiente estudiante: " << endl;
            }
        }

        cout << "\nPresione (4) si desea salir hacia el menu, presione enter si necesita hacer otros cambios" << endl;
        cin >> op;

        if (op == 4)
        {
            cout << "Regresando al menu....." << endl;
        }

    } while (op != 4);
}

/* FUNCIÓN PARA CALCULAR EL PROMEDIO DE LAS TRES NOTAS*/
float calcularPromedio(Estudiante est)
{
    return (est.nota1 + est.nota2 + est.nota3) / 3.0;
}

/* FUNCIÓN PARA MOSTRAR A TODOS LOS ESTUDIANTES REGISTRADOS */
void mostrarListadoGeneral(Estudiante estudiantes[], int cantidadEstudiantes)
{
    if (cantidadEstudiantes == 0)
    {
        cout << "\nNo hay estudiantes registrados en el sistema.\n";
        return;
    }

    cout << "\n--- LISTADO GENERAL DE ESTUDIANTES ---\n";
    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        float prom = calcularPromedio(estudiantes[i]);
        cout << "Codigo: " << estudiantes[i].identificador
             << " | Nombre: " << estudiantes[i].nombres << " " << estudiantes[i].apellidos
             << " | Curso: " << estudiantes[i].curso
             << " | Promedio: " << prom << endl;
    }
}

/* FUNCIÓN PARA ENCONTRAR A UN ESTUDIANTE */
void consultarExpediente(Estudiante estudiantes[], int cantidadEstudiantes)
{

    string codigoBuscar;
    
    if (cantidadEstudiantes == 0)
    {
        cout << "\nNo hay estudiantes registrados para consultar.\n";
        return;
    }

    cout << "\nIngrese el codigo (identificador) del estudiante a consultar: ";
    cin >> codigoBuscar;

    bool encontrado = false;

    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        if (estudiantes[i].identificador == codigoBuscar)
        {
            encontrado = true;
            float prom = calcularPromedio(estudiantes[i]);

            cout << "\n=== Expediente Academico ===\n";
            cout << "Codigo: " << estudiantes[i].identificador << endl;
            cout << "Nombre: " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << endl;
            cout << "Curso:  " << estudiantes[i].curso << endl;
            cout << "Calificaciones:\n";
            cout << " - Nota 1: " << estudiantes[i].nota1 << endl;
            cout << " - Nota 2: " << estudiantes[i].nota2 << endl;
            cout << " - Nota 3: " << estudiantes[i].nota3 << endl;

            cout << "Promedio Final: " << prom << endl;
            if (prom >= NOTA_MINIMA)
            {
                cout << "Estado: APROBADO\n";
            }
            else
            {
                cout << "Estado: REPROBADO\n";
            }
            break;
        }
        break;
    }

    if (!encontrado)
    {
        cout << "\nError: El codigo " << codigoBuscar << " no existe en el registro.\n";
    }
}

int main()
{
    Estudiante estudiantes[200]; // Esto solo es un valor quemado para la cantidad de estudiantes que podemos meter en la plataforma.
    int CantidadEstudiantes = 0;

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
            /*Funcion promedio de la clase*/

            break;

        case 6:
            /*Funcion de metricas de estudiantes aprobados y reprobados*/

            break;

        case 7:
            /*Funcion notas maximas y minimas registradas en el curso*/

            break;

        case 8:
            /*Funcion datos generales e individuales de cada estudiante/ y busqueda de
            cada estudiantes con identificador unico*/
            break;

        case 9:
        {
            // Visualizar datos individuales de cada estudiante
            int subOpcion = 0;
            cout << "\n--- CONSULTA DE DATOS ---\n";
            cout << "1. Ver listado general de todos los estudiantes\n";
            cout << "2. Consultar expediente individual por codigo\n";
            cout << "Elige una opcion: ";
            cin >> subOpcion;

            if (subOpcion == 1)
            {
                mostrarListadoGeneral(estudiantes, CantidadEstudiantes);
            }
            else if (subOpcion == 2)
            {
                consultarExpediente(estudiantes, CantidadEstudiantes);
            }
            else
            {
                cout << "\nOpcion no valida.\n";
            }
            break;
        }

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
