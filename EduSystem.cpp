#include <iostream>

using namespace std;

/*Ricardo y camilo, les dejare comentarios para que logren entender
a profundidad   */

struct Estudiante
{
    string nombres;
    string apellidos;  
    string curso;  
    string identificador;
    float nota1;
    float nota2;
    float nota3;
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

//esta funcion es para el registro de estudiantes lo separare con la inscripcion de las notas por que no tiene mucho sentido ingresar notas
//si solo se ingresa al estudiante, por eso cree un contador de cantidad de estudiantes para despues crear el de las notas y no perder las posicion que toma en el arreglo.
int registrarEstudiante(Estudiante estudiantes[], int cantidadEstudiantes)
{
    int regopcion = 0;  
    
   do{
        //la insercion de datos en el struct, la tome con do while en vez de un for ya que, para que su funcionalidad fuera mejor, le preguntaba si necesita ingresar mas de una
        //estudiante o puede regresar al menu y hacerlo despues y no arruina el contador ya que lo guarda en variable.
        //en los getline tuve que agregar el ws por que al elegir una opcion del menu dejaba un salto de linea que no me dejaba escribir
        //los datos de los estudiantes.

            cout << "\nIngrese los datos del estudiante: "<<endl;

            cout << "\nIngrese el nombre del estudiante: ";
            getline(cin >> ws, estudiantes[cantidadEstudiantes].nombres);

            cout << "\nIngrese los apellidos del estudiante: ";
            getline(cin >> ws, estudiantes[cantidadEstudiantes].apellidos);

            cout << "\nIngrese el nombre del curso del estudiante: ";
            getline(cin >> ws, estudiantes[cantidadEstudiantes].curso);

            cout << "\nIngrese el codigo del estudiante: ";
            cin>>estudiantes[cantidadEstudiantes].identificador;

            cantidadEstudiantes = cantidadEstudiantes + 1;
        //cada que termina un ingreso de un estudiante el contador guarda a 1 estudiante mas dentro de su variable.

        cout<<"\nSi desea realizar el ingreso de otro estudiante presione (1), si desea volver al menu principal presione (0)"<<endl;
        cin>>regopcion;

        if (regopcion < 0 || regopcion > 1)
        {
            cout << "\nIngreso incorrecto, se le redirigiendo hacia el menu......."<<endl;
            regopcion = 0;
        }
        


    } while(regopcion != 0);


    return cantidadEstudiantes; //aqui retorno el valor de la cantidad de estudiantes para poder crear la siguiente funcion que sera de notas

}




int main()
{
    Estudiante estudiantes[200];//Esto solo es un valor quemado para la cantidad de estudiantes que podemos meter en la plataforma.
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
            cout << "\ncantidad de estudiantes:  "<< CantidadEstudiantes<<endl;

            //Esto lo cree para poder observar si, podia mostrarlos los estudiantes o si tenia error, despues lo metemos en funcion xd.
            cout<<"\nEstudiantes registrados: "<<endl;


            for(int i = 0; i < CantidadEstudiantes; i++){

            cout<<"\nEstudiante "<<"("<<i + 1<<")"<<endl;
            cout << "\nNombre del estudiante: "<<estudiantes[i].nombres;
            cout << "\nApellidos del estudiante: "<<estudiantes[i].apellidos;
            cout << "\nNombre del curso del estudiante: "<<estudiantes[i].curso;
            cout << "\nCodigo del estudiante: "<<estudiantes[i].identificador<<endl;
            cout<< endl;
            }


            break;

        case 2:
            
            /*cuadro de honor */


            break;

        case 3:
            /*Funcion de estadisticas*/

            break;

        case 4:
            /*Funcion promedio de la clase*/

            break;

        case 5:
            /*Funcion de metricas de estudiantes aprobados y reprobados*/

            break;

        case 6:
            /*Funcion notas maximas y minimas registradas en el curso*/

            break;

        case 7:
            /*Funcion datos generales e individuales de cada estudiante/ y busqueda de
            cada estudiantes con identificador unico*/
            break;

        case 8:
            /*Funcion cuadro de honor*/
            break;

        case 9:
            cout << "Saliendo del sistema....." << endl;
            break;
        }

        if (opcion > 9 || opcion < 1 )
        {
            cout << endl;
            cout << "Ingresa una opcion valida..." << endl;
            cout << endl;
        }

    } while (opcion != 9);

    return 0;
}