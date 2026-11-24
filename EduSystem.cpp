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
    float nota1 = 0.0;
    float nota2 = 0.0;
    float nota3 = 0.0;
    float promedio = 0.0;
};

/*FUNCIÓN PARA MOSTRAR EL MENÚ*/
void mostrarMenu()
{
    cout << "\n---------------------------------------------------------" << endl;
    cout << "¡Bienvenido a MetricEduSystem!" << endl;
    cout << "(1) Registrar Estudiante" << endl;
    cout << "(2) Editar notas de estudiantes " << endl;
    cout << "(3) Visualizar Cuadro de honor " << endl;
    cout << "(4) Visualizar promedio de cada estudiante " << endl;
    cout << "(5) Visualizar promedio de clases" << endl;
    cout << "(6) Visualizar metricas de estudiantes aprobados y reprobados " << endl;
    cout << "(7) Visualizar notas maximas y minimas registradas en el curso" << endl;
    cout << "(8) Visualizar datos individuales de cada estudiante " << endl;
    cout << "(9) Salir del sistema " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

int CuadroDeHonor(Estudiante estudiantes[], int cantidadEstudiantes)
{

    int cont = 0;

    for (int i = 0; i < cantidadEstudiantes; i++)
    {

        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3) / 3.0;
        cont++;
    }

    if (estudiantes[cont].promedio >= 9) // arreglar esto
    {
        cout << "\nEstudiantes honorificos con promedio de 9 o superior" << endl;
    }
    else
    {
        cout << "No hay estudiantes o ningun promedio llega a 9 o superior aun.";
    }

    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        if (estudiantes[i].promedio >= 9)
        {
            cout << "\n"
                 << estudiantes[i].nombres << " " << estudiantes[i].apellidos;
            cout << " || PROMEDIO: " << estudiantes[i].promedio << endl;
        }
    }

    return 0;
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

        if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo de estudiantes.txt para guardar." << endl;
        return;
    }

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
        if (cantidadEstudiantes == 0)
    {
        cout << "\nNo hay estudiantes registrados aun. Registre al menos uno primero." << endl;
        return; 
    }

    int opcionMenu = 0;
    float notaIngresada = 0.0;

    do
    {

        for (int i = 0; i < cantidadEstudiantes; i++)
        {
            cout << "\n-----------------------------" << endl;
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

            if (estudiantes[i].nota1 == 0)
                {
                    do
                    {
                        cout << "\nIngrese la primera nota (0.0 - 10.0): ";
                        cin >> notaIngresada;
                        if (notaIngresada < 0.0 || notaIngresada > 10.0)
                        {
                            cout << "Error: La nota debe estar entre 0.0 y 10.0. Intente de nuevo." << endl;
                        }
                    } while (notaIngresada < 0.0 || notaIngresada > 10.0);

                    estudiantes[i].nota1 = notaIngresada;
                }
                else
                {
                    cout << "\nError. La opcion elegida ya tiene una nota." << endl;
            }
            break;
            case 2:
            if (estudiantes[i].nota2 == 0)
                {
                    
                    do
                    {
                        cout << "\nIngrese la segunda nota (0.0 - 10.0): ";
                        cin >> notaIngresada;
                        if (notaIngresada < 0.0 || notaIngresada > 10.0)
                        {
                            cout << "Error: La nota debe estar entre 0.0 y 10.0. Intente de nuevo." << endl;
                        }
                    } while (notaIngresada < 0.0 || notaIngresada > 10.0);

                    estudiantes[i].nota2 = notaIngresada;
                }
                else
                {
                    cout << "\nError. La opcion elegida ya tiene una nota." << endl;
                }
            break;
            case 3:
            if (estudiantes[i].nota3 == 0){
                    do
                    {
                        cout << "\nIngrese la tercera nota (0.0 - 10.0): ";
                        cin >> notaIngresada;
                        if (notaIngresada < 0.0 || notaIngresada > 10.0)
                        {
                            cout << "Error: La nota debe estar entre 0.0 y 10.0. Intente de nuevo." << endl;
                        }
                    } while (notaIngresada < 0.0 || notaIngresada > 10.0);

                    estudiantes[i].nota3 = notaIngresada;
                }
                else
                {
                    cout << "\nError. La opcion elegida ya tiene una nota." << endl;
                }
            break;
            case 4:
                cout << "\nPasando al siguiente estudiante..." << endl;
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

    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
    }
    else
    {
        while (archivo >> estudiantes.identificador >> estudiantes.nombres >> estudiantes.apellidos >> estudiantes.nota1 >> estudiantes.nota2 >> estudiantes.nota3)
        {
            sumaNotas = estudiantes.nota1 + estudiantes.nota2 + estudiantes.nota3;
            promedioNotas = sumaNotas / 3;
            cout << estudiantes.nombres << " " << estudiantes.apellidos << " || PROMEDIO: " << promedioNotas << endl;
        }

        archivo.close();
    }
}

/* FUNCION PARA CALCULAR EL PROMEDIO DE LA CLASE */

void promedioClase()
{
    Estudiante estudiantes;
    float promedioNotas = 0;
    float sumaPromedios = 0;
    int cantidadEstudiantes = 0;
    float promedioGeneral = 0;

    ifstream archivo("estudiantes.txt");

    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
    }
    else
    {
        while (archivo >> estudiantes.identificador >> estudiantes.nombres >> estudiantes.apellidos >> estudiantes.nota1 >> estudiantes.nota2 >> estudiantes.nota3)
        {
            promedioNotas = (estudiantes.nota1 + estudiantes.nota2 + estudiantes.nota3) / 3;
            sumaPromedios += promedioNotas;
            cantidadEstudiantes++;
        }

        archivo.close();

        if (cantidadEstudiantes == 0)
        {
            cout << "No hay estudiantes registrados." << endl;
        }
        else
        {
            promedioGeneral = sumaPromedios / cantidadEstudiantes;
            cout << "La cantidad de estudiantes procesados es de: " << cantidadEstudiantes << endl;
            cout << "El promedio general de la clase es: " << promedioGeneral << endl;
        }
    }
}

/* FUNCIÓN PARA MOSTRAR LA CANTIDAD DE ESTUDIANTES APROBADOS Y REPROBADOS */
void metricasAprobados()
{
    Estudiante estudiante;
    float promedioNotas = 0;
    int aprobados = 0;
    int reprobados = 0;

    ifstream archivo("estudiantes.txt");
    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
        return;
    }
    else
    {
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
    }

    archivo.close();

    int total = aprobados + reprobados;

    if (total == 0)
    {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n-----------------------------" << endl;
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

    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
    }
    else
    {
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
}

void promedioMinimo()
{
    Estudiante estudiante;
    float promedioNotas = 0;
    float promedioMinimo = 10.1;
    string nombreEstudiante;

    ifstream archivo("estudiantes.txt");

    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
    }
    else
    {
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
        cout << "El promedio mas bajo es: " << promedioMinimo << " del alumno: " << nombreEstudiante << endl;
    }
}

/* FUNCIÓN PARA CARGAR LOS ESTUDIANTES GUARDADOS EN EL ARCHIVO AL INICIAR EL PROGRAMA */
int cargarEstudiantes(Estudiante estudiantes[])
{
    int cantidad = 0;
    ifstream archivo("estudiantes.txt");

    if (!archivo.is_open())
    {
        cout << "No se puedo abrir el archivo de estudiantes.txt" << endl;
        return 0;
    }
    else
    {
        while (cantidad < 200 && archivo >> estudiantes[cantidad].identificador >> estudiantes[cantidad].nombres >> estudiantes[cantidad].apellidos >> estudiantes[cantidad].nota1 >> estudiantes[cantidad].nota2 >> estudiantes[cantidad].nota3)
        {
            cantidad++;
        }

        archivo.close();
        return cantidad;
    }
}

void BusquedaCodigo(Estudiante estudiantes[], int cantidadEstudiantes)
{ // faltan retoques de la busquedacodigo

    string BusquedaCod;
    int encont = 0;

    // falta un do while a este para que sea mejor.
    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        cout << "\nEstudiante : " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << " || " << "Codigo: " << estudiantes[i].identificador << endl;
    }

    do
    {
        cout << "\nIngresa el codigo del estudiante que desea solicitar su informacion: " << endl;
        cin >> BusquedaCod;
        for (int i = 0; i < cantidadEstudiantes; i++)
        {

            if (estudiantes[i].identificador == BusquedaCod)
            {
                encont = 1;
                cout << "\n-----------------------------" << endl;
                cout << "------Informacion estudiantil------" << endl;
                cout << "-----------------------------" << endl;
                cout << "\nEstudiante" << "(" << i + 1 << ")";
                cout << "\nNombre del estudiante: " << estudiantes[i].nombres;
                cout << "\nApellidos del estudiante: " << estudiantes[i].apellidos;
                cout << "\nCodigo del estudiante: " << estudiantes[i].identificador;
                cout << "\nNota 1 : " << estudiantes[i].nota1;
                cout << "\nNota 2 : " << estudiantes[i].nota2;
                cout << "\nNota 3 : " << estudiantes[i].nota3;
                cout << "\nPromedio: " << estudiantes[i].promedio;
                break;
            }
        }

        if (encont != 1)
        {
            cout << "\nEl codigo: " << BusquedaCod << " No existe, intenta con un codigo existente" << endl;
        }
        cout << "\n----------------------------------------------------------------------------------" << endl;
        cout << "\nSi desea volver a intentarlo presione (0), si desea volver al menu presione 1" << endl;
        cin >> encont;

    } while (encont != 1);
}

int main()
{
    Estudiante estudiantes[200];
    int CantidadEstudiantes = cargarEstudiantes(estudiantes);

    int opcion = 0;

    do
    {

        cargarEstudiantes(estudiantes); // chicos esto lo agregue por que es imposible que el programa pueda leer el archivo sin llamar a la funcion,
        // aqui la llama en cada iteracion del do while ya que es cuando se agrega un estudiante y etc, y al terminar de agregarlo lo vuelve a leer de manera rapida
        // asi que esto esta arreglado.

        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            CantidadEstudiantes = registrarEstudiante(estudiantes, CantidadEstudiantes);
            guardarNotas(estudiantes, CantidadEstudiantes);
            cout << "\ncantidad de estudiantes:  " << CantidadEstudiantes << endl;
            break;

        case 2:

            registroNotas(estudiantes, CantidadEstudiantes);
            break;

        case 3:
            CuadroDeHonor(estudiantes, CantidadEstudiantes);
            break;

        case 4:
            calcularPromedio();
            break;

        case 5:
            promedioClase();
            break;

        case 6:
            metricasAprobados();
            break;

        case 7:
            promedioMaximo();
            promedioMinimo();
            break;

        case 8:
            BusquedaCodigo(estudiantes, CantidadEstudiantes);
            break;

        case 9:
            cout << "Saliendo del sistema....." << endl;
            break;

        default:
            cout << "Opcion no valida, ingrese un numero del 1 al 10" << endl;
        }

    } while (opcion != 9);

    return 0;
}
