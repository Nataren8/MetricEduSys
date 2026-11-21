#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*CONSTANTE CON LA NOTA MÍNIMA DE 6.0*/
const float NOTA_MINIMA = 6.0;

/*DATOS DEL ESTUDIANTE*/
struct Estudiante
{
    string nombres;
    string apellidos;
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
    cout << "(1) Registrar Estudiante" << endl;
    cout << "(2) Editar notas de estudiantes " << endl;
    cout << "(3) Visualizar Cuadro de honor " << endl;
    cout << "(4) Visualizar Estadisticas " << endl;
    cout << "(5) Visualizar promedio de cada estudiante " << endl;
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
                cout << "Pasando al siguiente estudiante..." << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
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

    while (archivo >> estudiantes.identificador >> estudiantes.nombres >> estudiantes.apellidos >> estudiantes.nota1 >> estudiantes.nota2 >> estudiantes.nota3)
    {
        sumaNotas = estudiantes.nota1 + estudiantes.nota2 + estudiantes.nota3;
        promedioNotas = sumaNotas / 3;
        cout << estudiantes.nombres << " " << estudiantes.apellidos << " || PROMEDIO: " << promedioNotas << endl;
    }

    archivo.close();
}

/* FUNCIÓN PARA MOSTRAR LA CANTIDAD DE ESTUDIANTES APROBADOS Y REPROBADOS */
void metricasAprobados()
{
    Estudiante estudiante;
    float promedioNotas = 0;
    int aprobados = 0;
    int reprobados = 0;

    ifstream archivo("estudiantes.txt");

    while (archivo >> estudiante.identificador >> estudiante.nombres >> estudiante.apellidos >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3)
    {
        promedioNotas = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3;

        if (promedioNotas >= NOTA_MINIMA)
        {
            aprobados++;
        }
        else
        {
            reprobados++;
        }
    }

    archivo.close();

    int total = aprobados + reprobados;

    if (total == 0)
    {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "-----------------------------" << endl;
    cout << "--APROBADOS Y REPROBADOS--" << endl;
    cout << "-----------------------------" << endl;
    cout << "Total de estudiantes: " << total << endl;
    cout << "Aprobados:  " << aprobados << " (" << aprobados * 100.0 / total << "%)" << endl;
    cout << "Reprobados: " << reprobados << " (" << reprobados * 100.0 / total << "%)" << endl;
}

/* FUNCIÓN PARA MOSTRAR EL PROMEDIO MÁS ALTO Y EL MÁS BAJO DEL CURSO */

void promedioMaximo()
{
    Estudiante estudiante;
    float promedioNotas = 0;
    float promedioMaximo = -0.1;
    string nombreEstudiante;

    ifstream archivo("estudiantes.txt");

    while (archivo >> estudiante.identificador >> estudiante.nombres >> estudiante.apellidos >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3)
    {
        promedioNotas = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3;

        if (promedioNotas > promedioMaximo)
        {
            promedioMaximo = promedioNotas;
            nombreEstudiante = estudiante.nombres + " " + estudiante.apellidos;
        }
    }

    archivo.close();
    cout << "El promedio mas alto es: " << promedioMaximo << " del alumno: " << nombreEstudiante << endl;
}

void promedioMinimo()
{
    Estudiante estudiante;
    float promedioNotas = 0;
    float promedioMinimo = 10.1;
    string nombreEstudiante;

    ifstream archivo("estudiantes.txt");

    while (archivo >> estudiante.identificador >> estudiante.nombres >> estudiante.apellidos >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3)
    {
        promedioNotas = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3;

        if (promedioNotas < promedioMinimo)
        {
            promedioMinimo = promedioNotas;
            nombreEstudiante = estudiante.nombres + " " + estudiante.apellidos;
        }
    }

    archivo.close();
    cout << "El promedio mas bajo es: " << promedioMinimo <<  " del alumno: " << nombreEstudiante << endl;
}

/* FUNCIÓN PARA CARGAR LOS ESTUDIANTES GUARDADOS EN EL ARCHIVO AL INICIAR EL PROGRAMA */
int cargarEstudiantes(Estudiante estudiantes[])
{
    int cantidad = 0;
    ifstream archivo("estudiantes.txt");

    while (cantidad < 200 && archivo >> estudiantes[cantidad].identificador >> estudiantes[cantidad].nombres >> estudiantes[cantidad].apellidos >> estudiantes[cantidad].nota1 >> estudiantes[cantidad].nota2 >> estudiantes[cantidad].nota3)
    {
        cantidad++;
    }

    archivo.close();
    return cantidad;
}

int main()
{
    Estudiante estudiantes[200];
    int CantidadEstudiantes = cargarEstudiantes(estudiantes); // recupera lo que ya estaba guardado

    int opcion = 0;

    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            CantidadEstudiantes = registrarEstudiante(estudiantes, CantidadEstudiantes);
            guardarNotas(estudiantes, CantidadEstudiantes); // guarda a los nuevos estudiantes en el archivo
            cout << "\ncantidad de estudiantes:  " << CantidadEstudiantes << endl;
            break;

        case 2:

            registroNotas(estudiantes, CantidadEstudiantes);
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            calcularPromedio();
            break;

        case 6:
            cout << "Trabajando en ello..." << endl;
            break;

        case 7:
            metricasAprobados();
            break;

        case 8:
            promedioMaximo();
            promedioMinimo();
            break;

        case 9:
            break;

        case 10:
            cout << "Saliendo del sistema....." << endl;
            break;

        default:
            cout << "Opcion no valida, ingrese un numero del 1 al 10" << endl;
        }

    } while (opcion != 10);

    return 0;
}
