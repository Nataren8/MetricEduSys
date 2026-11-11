#include <iostream>

/*Ricardo y camilo, les dejare comentarios para que logren entender
a profundidad*/

/*v1/


using namespace std;

int main(){

    
int opcion = 0;


do
{ 

    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"¡Bienvenido a MetricEduSystem!"<<endl;
    cout<<"Ingresa el numero de opcion que necesitas realizar"<<endl;
    cout<<"(1) Registrar Estudiante"<<endl;
    cout<<"(2) Visualizar Cuadro de honor "<<endl;
    cout<<"(3) Visualizar Estadisticas "<<endl;
    cout<<"(4) Visualizar Cuadro de honor "<<endl;
    cout<<"(5) Visualizar promedio de clases"<<endl;
    cout<<"(6) Visualizar metricas de estudiantes aprobados y reprobados "<<endl;
    cout<<"(7) Visualizar notas maximas y minimas registradas en el curso"<<endl;
    cout<<"(8) Visualizar datos individuales de cada estudiante "<<endl;
    cout<<"(9) Salir del sistema "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<endl;

    cin>>opcion;


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
            cout<<"Saliendo del sistema....."<<endl;
        break;

    } 

    if (opcion > 9)
    {
        cout<<endl;
        cout<<"Ingresa una opcion valida..."<<endl;
        cout<<endl;
    }
    
} while (opcion != 9 );
    
    return 0;
}