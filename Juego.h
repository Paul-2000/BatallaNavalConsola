///#############################################################################
/// ARCHIVO             : Juego.h
/// AUTOR               : Antoni Briceño.
/// VERSION             : 0.52.
/// FECHA DE CREACION   : 17/11/2018.
/// ULTIMA ACTUALIZACION: 22/02/2019.
/// LICENCIA            : GPL (General Public License) - Version 3.
///=============================================================================
/// SISTEMA OPERATIVO   : Linux / Windows XP / Windows 7
/// IDE                 : Code::Blocks - 8.02 / 10.05 / 12.11 / 13.12
/// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
/// LICENCIA            : GPL (General Public License) - Version 3.
///=============================================================================
/// DESCRIPCION:
/// Este archivo contiene todas las funciones referentes al juego y su programación
///

///*****************************************************************************
///                             INCLUSIONES ESTANDAR
///=============================================================================

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <windows.h>
#include <cstring>
//#include <stdbool.h>
#include <string.h>
#include "Menus.h"

/// FUNCIONES DEFINIDAS:
///=========================================================================================|
///     NOMBRE                |  TIPO  |                    ACCION                          |
///===========================+========+====================================================|
/// ValidaInt()               |  bool  | Verifica si el ingreso es un numero.               |
///---------------------------+--------+----------------------------------------------------|
/// ValidarOpcion()           |  char  | verifica la opción ingresada por el usaurio.       |
///---------------------------+--------+----------------------------------------------------|
/// Eleccion_Nivel()          |  int   | verifica el ingreso del nivel, y devuelve el mismo.|
///---------------------------+--------+----------------------------------------------------|
/// MostrarMat()              |  void  | Muestra la matriz.                                 |
///                           |        | Param: 1 Muestra la parte Visible.                 |
///                           |        |        2 Muestra la parte Oculta.                  |
///---------------------------+--------+----------------------------------------------------|
/// IniMat()                  |  Void  | Inicializa la matriz que se da como pa-            |
///                           |        | rametro.                                           |
///---------------------------+--------+----------------------------------------------------|
/// TocaPared()               |  bool  | Verifica si en la coordenada dada un barco         |
///                           |        | podria llegar a tocar algunos de los extremos.     |
///---------------------------+--------+----------------------------------------------------|
/// TocaBarco()               |  bool  | Verifica si en la coordenada dada un barco         |
///                           |        | podria llegar a tocar algunos de los barcos        |
///                           |        | cargados (si es que hubo).                         |
///---------------------------+--------+----------------------------------------------------|
/// ColocarBarco()            |  void  | Coloca los barcos del juego.                       |
///---------------------------+--------+----------------------------------------------------|
/// CargarBarco()             |  void  | Genera coordenadas aleatorias y carga un barco.    |
///---------------------------+--------+----------------------------------------------------|
/// strToint   ()             |  int   | convierte un char en un int.   	                |
///---------------------------+--------+----------------------------------------------------|
/// Validacion()              |  int   | Realiza las validaciones sobre las coordenadas     |
///                           |        | ingresadas y retorna un codigo de error si es      |
///                           |        | que lo hubo                                        |
///---------------------------+--------+----------------------------------------------------|
/// Verificar_Tocado()        |  bool  | Verifica si la coordenada dada toco un barco sin   |
///                           |        | haber estado hundido                               |
///---------------------------+--------+----------------------------------------------------|
/// Escribir_Matriz()         |  void  | Escribe en la matriz visible una "T" tocado        |
///                           |        | una "H" Hundido, o una "A" agua, segun corresponda.|
///---------------------------+--------+----------------------------------------------------|
/// Barcos_Restantes()        |  void  | Carga en una matriz los barcos restantes por hundir|
///---------------------------+--------+----------------------------------------------------|
/// Valida_Ganador()          |  bool  | valida si hundio todos los barcos del juego.       |
///                           |        | 					                                |
///---------------------------+--------+----------------------------------------------------|
/// Pantalla()                |  void  | pantalla con todo el contenido del juego.          |
///                           |        | 					                                |
///===========================+========+====================================================|

struct Casilla
{
    int Oculto;
    int Fila;
    int Col;
    int Dir;
    char Visible;
};

///*****************************************************************************
///               ESPACIO DE NOMBRES DE LA LIBRERIA Presentacion.h
///=============================================================================
using namespace std;

//===========================================================================
/// FUNCION   : bool ValidaInt(char Numero[1])
/// ACCION    : Verifica si lo que ingreso el usuario es un numero y no un char
/// PARAMETROS: Char Numero: char para validar si es un numero
/// DEVUELVE  : True si es un numero, false si no es un numero.
///----------------------------------------------------------------------
bool ValidaInt(char Numero[2])
{
    int Numero2;

    for(int i=0; i<strlen(Numero); i++)
    {
        Numero2 = Numero[i];
        if(Numero2>=48&&Numero2<=57)
        {
            return true;
        }
    }

    return false;
}
///===========================================================================
/// FUNCION   : char ValidarOpcion (char *Mensaje, char *MensajeError)
/// ACCION    : Verifica el ingreso del usuario
/// PARAMETROS: Matriz de tipo estructura
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
char ValidarOpcion (char *Mensaje, char *MensajeError)
{
    char Result, Ingreso[3];
    bool IngresoValido = false;
    do
    {
        cout << Mensaje;
        sys::getline(Ingreso,3);
        if (strlen(Ingreso)==1)
        {
            IngresoValido = true;
        }
        else
        {
            cout << MensajeError;
            cin.get();
        }
    }while (!IngresoValido);
    Result = Ingreso[0];
    return Result;
}
///===========================================================================
/// FUNCION   : int Eleccion_Nivel ()
/// ACCION    : verifica la eleccion de la pantalla
/// PARAMETROS: -
/// DEVUELVE  : el nivel seleccionado
///----------------------------------------------------------------------
int Eleccion_Nivel ()
{
    bool Salir = false;
    char Nivel;

    while (!Salir)
    {
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11);
        sys::cls();
        cout << " _____________________________________________________" << endl;
        cout << "|               Selección del nivel                   |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "|                                                     |" << endl;
        cout << "|  ¿Que nivel desea jugar?                            |" << endl;
        cout << "|                                                     |" << endl;
        cout << "|  A - Nivel 1  -   Serás Grumete (50 disparos)       |" << endl;
        cout << "|                                                     |" << endl;
        cout << "|  B - Nivel 2  -   Serás Almirante (25 disparos)     |" << endl;
        cout << "|_____________________________________________________|" << endl;

        Nivel = ValidarOpcion("Ingrese una opción: ","opción no valida");;

        if (Nivel == 'A' || Nivel == 'a')
        {
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
            cout << endl;
            cout << endl;
            cout << "\t\tUsted ingresó la opción Grumete." << endl;
            cout << "\t\t¡Que se divierta!";
            sys::msleep(2);

            Salir = true;
            return 1;
        }
        else
        {
            if (Nivel == 'B' || Nivel == 'b')
            {
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
                cout << endl;
                cout << endl;
                cout << "\t\tUsted ingreso la opción Almirante." << endl;
                cout << "\t\t¡Que se divierta!";
                sys::msleep(2);

                Salir = true;
                return 2;
            }
            else
            {

                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
                cout << endl;
                cout << endl;
                cout << "\t\tUsted Ingresó una opción incorrecta." << endl;
                cout << "\t\tIngrese una tecla para continuar...";
                cin.get();
                cin.ignore();
            }
        }

    }
}
///===========================================================================
/// FUNCION   : void MostrarMat(Casilla Mat[12][12], int Opcion)
/// ACCION    : Muestra la Matriz de tipo estructura
/// PARAMETROS: int Opcion: 0 Muestra la matriz oculta
///                         1 Muestra la matriz visible
///             casilla Matriz
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void MostrarMat(Casilla Mat[12][12], int Opcion)
{

    if(Opcion == 0)
    {
        cout << "     1  2  3  4  5  6  7  8  9  10"<< endl;
        for (int f =1; f < 11 ; f++)
        {
            cout <<endl << "-------------------------------------" << endl;
            if(f != 10)
            {

                cout << f << "  ";
            }
            else
            {
                cout << f << " ";
            }
            cout << "| " ;

            for (int c=1; c<11; c++)
            {

                if(Mat[f][c].Oculto != 0 )
                {
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),11);
                }
                cout << Mat[f][c].Oculto << "  "  ;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),3);
            }
            cout << " |" ;
        }
        cout <<endl << "-------------------------------------" ;
    }
    else
    {
        cout << "   1  2  3  4  5  6  7  8  9 10"<< endl;
        for (int f =1; f < 11 ; f++)
        {
            if(f != 10)
            {

                cout << f << "  ";
            }
            else
            {
                cout << f << " ";
            }
            for (int c=1; c<11; c++)
            {
                cout << Mat[f][c].Visible << "  "  ;
            }
            cout << endl;
        }
    }

///===========================================================================
/// FUNCION   : void IniMat(Casilla Mat[12][12])
/// ACCION    : Inicializa la Matriz de tipo estructura
/// PARAMETROS: Matriz de tipo estructura
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
}
void IniMat(Casilla Mat[12][12])
{
    for (int f =0; f < 12 ; f++)
    {
        for (int c=0; c<12; c++)
        {
            Mat[f][c].Oculto = 0;
            Mat[f][c].Visible = '*';
        }
    }
}
///===========================================================================
/// FUNCION   : bool TocaPared (int Fila,int Col, int Dir, int Tam)
/// ACCION    : Verifica si la coordenada para el barco dado toca las paredes laterales de la matriz
/// PARAMETROS: int Fila: Fila de la posicion del barco
///             int Col: Columna de la posicion del barco
///             int Dir: sentido en el que debe ir ubicado el barco
///             int Tam: Tamaño del barco
/// DEVUELVE  : bool.
///----------------------------------------------------------------------
bool TocaPared (int Fila,int Col, int Dir, int Tam)
{
    int Suma = 0;
    //0 Horizontal, 1 Vertical
    if ( Dir == 0)
    {
        Suma = Tam + Col;
        if (Suma < 11)
        {
            return false;
        }
    }
    else
    {
        Suma = Tam + Fila;
        if (Suma < 11)
        {
            return false;
        }
    }

    return true;
}
///===========================================================================
/// FUNCION   : bool TocaBarco (Casilla Mat[12][12],int Fila, int Col, int Dir, int Tam)
/// ACCION    : Verifica si la coordenada para el barco dado toca otro barco ya posicionado
/// PARAMETROS: Casilla Matriz: Matriz del juego
///             int Fila: Fila de la posicion del barco
///             int Col: Columna de la posicion del barco
///             int Dir: sentido en el que debe ir ubicado el barco
///             int Tam: Tamaño del barco
/// DEVUELVE  : bool.
///----------------------------------------------------------------------
bool TocaBarco (Casilla Mat[12][12],int Fila, int Col, int Dir, int Tam)
{
    int  MaxCol = 0, MinCol = 0, MaxFila = 0, MinFila = 0;
    //0 Horizontal , 1 Vertical
    if(Dir == 0)
    {
        MinCol = Col - 1 ;
        MaxCol = (Col + Tam) ;
        MinFila = Fila - 1;
        MaxFila = Fila + 1;

        for (int e=MinFila; e <= MaxFila; e++)
        {
            for(int f=MinCol; f <= MaxCol; f++)
            {

                if(Mat[e][f].Oculto != 0)
                {
                    return true;
                }
            }
        }
    }
    else //Vertical
    {
        MinCol = Col - 1 ;
        MaxCol = Col + 1 ;
        MinFila = Fila - 1;
        MaxFila = (Fila + Tam);

        for (int r=MinFila; r <= MaxFila; r++)
        {
            for(int t=MinCol; t <= MaxCol; t++)
            {
                if(Mat[r][t].Oculto != 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
///===========================================================================
/// FUNCION   : void ColocarBarco (Casilla Mat[12][12],int Fila, int Col, int Dir, int Tam)
/// ACCION    : Coloca barcos del juego
/// PARAMETROS: Casilla Matriz: Matriz del juego
///             int Fila: Fila de la posicion del barco
///             int Col: Columna de la posicion del barco
///             int Dir: sentido en el que debe ir ubicado el barco
///             int Tam: Tamaño del barco
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void ColocarBarco (Casilla Mat[12][12],int Fila, int Col, int Dir, int Tam)
{

    int MaxCol = 0, MaxFila = 0;

    if(Dir == 0)
    {
        MaxCol = (Col + Tam)-1;

        for (int v=Col; v <= MaxCol; v++)
        {
            Mat[Fila][v].Oculto = Tam;
            Mat[Fila][v].Fila = Fila;
            Mat[Fila][v].Col = Col;
            Mat[Fila][v].Dir = Dir;
        }
    }
    else
    {
        MaxFila = (Fila + Tam) -1 ;

        for (int x=Fila; x <= MaxFila; x++)
        {

            Mat[x][Col].Oculto = Tam;
            Mat[x][Col].Fila = Fila;
            Mat[x][Col].Col = Col;
            Mat[x][Col].Dir = Dir;
        }
    }
}
///===========================================================================
/// FUNCION   : void CargarBarco (Casilla Mat[12][12], int Tam)
/// ACCION    : genera una coordenada aleatoria para verificar si es posible colocar un barco
/// PARAMETROS: Casilla Matriz: Matriz del juego
///             int Tam: Tamaño del barco
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void CargarBarco (Casilla Mat[12][12], int Tam)
{
    int Fila,Col,Dir;
    do
    {
        Fila = sys::random(10)+1;
        Col = sys::random(10)+1;
        Dir = sys::random(2);

    }while ( TocaPared(Fila,Col,Dir,Tam) || TocaBarco(Mat,Fila,Col,Dir,Tam));

    ColocarBarco (Mat,Fila,Col,Dir,Tam);
}
///===========================================================================
/// FUNCION   : void CargarBarcos (Casilla Mat[12][12])
/// ACCION    : Carga los barcos del juego
/// PARAMETROS: Casilla Matriz: Matriz del juego
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void CargarBarcos (Casilla Mat[12][12])
{
    IniMat(Mat);

    CargarBarco(Mat,4);
    CargarBarco(Mat,3);
    CargarBarco(Mat,3);
    CargarBarco(Mat,2);
    CargarBarco(Mat,2);
    CargarBarco(Mat,2);
    CargarBarco(Mat,1);
    CargarBarco(Mat,1);
    CargarBarco(Mat,1);
    CargarBarco(Mat,1);
}
int strToInt (char *Cadena)
{
    int Resultado=0, i=0, Caracter=0, len = 0;
    len = strlen(Cadena)-1 ;

    while (Cadena[i] != '\0')
    {
        Caracter = Cadena[i] -48 ;

        for (int e=0; e<len; e++)
        {
            Caracter = 10 * (Caracter);
        }

        Resultado += Caracter;

        len--;
        i++;
    }

    return Resultado;
}
///===========================================================================
/// FUNCION   : int Validacion (int Fila, int Columna)
/// ACCION    : Realiza las validaciones sobre las coordenadas ingresadas, y retorna un codigo de error si es que lo hubo.
/// PARAMETROS: int Fila: Fila ingresada por el usuario
///             int Columna: Columna ingresada por el usuario
/// DEVUELVE  : 11 --> si quiere mostrar la matriz.
///             12 --> si quiere ver la ayuda del sistema
///             0 --> si quiere salir del juego
///             1 --> si las coordenadas son correctas para mostrar una posicion
///             2 --> si las coordenadas no son correctas
///----------------------------------------------------------------------
int Validacion (int Fila, int Columna)
{


    if (Fila == 12 && Columna == 12)
    {
        return 12;
    }
    if (Fila == 11 && Columna == 11)
    {
        return 11;
    }
    if (Columna== 0 && Fila == 0)
    {
        return 0;
    }
    if(Fila >= 1 && Fila <= 10 && Columna >= 1 && Columna <= 10)
    {
        return 1;
    }

    return 2;
}
///===========================================================================
/// FUNCION   : bool Verificar_Tocado(Casilla Mat[12][12], int Fila, int Columna)
/// ACCION    : Verifica si la coordenada toco un barco o agua
/// PARAMETROS: Casilla Matriz: Matriz del juego
///             Fila: Fila ingresada por el usuario
///             Columna: columna ingresada por el usuario
/// DEVUELVE  : false si no toco un barco.
///             true si toco un barco.
///----------------------------------------------------------------------
bool Verificar_Tocado(Casilla Mat[12][12], int Fila, int Columna)
{
    if (Mat[Fila][Columna].Oculto == 0 || Mat[Fila][Columna].Visible == 'T' || Mat[Fila][Columna].Visible == 'H')
    {
        return false;
    }
    else
    {
        return true;
    }
}


///===========================================================================
/// FUNCION   : void Escribir_Matriz (Casilla Mat[12][12],int Fila, int Columna,int &Barcos_Restantes, int Vec_BR[4])
/// ACCION    : Escribe en la matriz dependiendo de si toco o hundio un barco
/// PARAMETROS: Casilla Matriz: matriz del juego
///             int Fila: fila seleccionada por el usuario
///             int columna: columna ingresada por el usuario
///             int &Barcos_Restantes: modifica si hundio un barco
///             int Vec_BR: Vector de barcos restantes, modifica si hundio un barco
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void Escribir_Matriz (Casilla Mat[12][12],int Fila, int Columna,int &Barcos_Restantes, int Vec_BR[4])
{
    int Hasta = 0,Cont = 0,Desde = 0 ;

    Mat[Fila][Columna].Visible = 'T';

    if (Mat[Fila][Columna].Dir == 0)
    {
        Desde = Mat[Fila][Columna].Col;
        Hasta = Mat[Fila][Columna].Oculto + Mat[Fila][Columna].Col;
        for (int c=Desde; c < Hasta; c++ )
        {
            if(Mat[Fila][c].Visible == 'T')
            {
                Cont ++;
            }
        }

        if (Cont == Mat[Fila][Columna].Oculto)
        {
            for (int z=Desde; z < Hasta; z++ )
            {
                Mat[Fila][z].Visible = 'H';
            }
            Barcos_Restantes--;
            Vec_BR[Mat[Fila][Columna].Oculto - 1]--;
        }
    }
    else
    {
        Desde =  Mat[Fila][Columna].Fila;
        Hasta = Mat[Fila][Columna].Oculto +  Mat[Fila][Columna].Fila;


        for (int a=Desde; a < Hasta; a++ )
        {
            if(Mat[a][Columna].Visible == 'T')
            {
                Cont ++;
            }
        }
        if (Cont == Mat[Fila][Columna].Oculto)
        {
            for (int b=Desde; b < Hasta; b++ )
            {
                Mat[b][Columna].Visible = 'H';
            }
            Barcos_Restantes--;
            Vec_BR[Mat[Fila][Columna].Oculto - 1]--;
        }

    }
}

///===========================================================================
/// FUNCION   : void Barcos_Restantes (int Vec[3])
/// ACCION    : inicializa un vector con los barcos por hundir
/// PARAMETROS: int Vec[3]: vector donde se cargan los barcos restantes
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void Barcos_Restantes (int Vec[4])
{
    Vec[0] = 4;
    Vec[1] = 3;
    Vec[2] = 2;
    Vec[3] = 1;
}
///===========================================================================
/// FUNCION   : bool Valida_Ganador (int Vec[3])
/// ACCION    : Verifica si hundio todos los barcos del tablero
/// PARAMETROS: int Vec[3]: vector con los barcos restantes
/// DEVUELVE  : true si gano.
///             false si no gano
///----------------------------------------------------------------------
bool Valida_Ganador (int Vec[4])
{
    for (int a=0; a<4; a++)
    {
        if(Vec[a]!=0)
        {
            return false;
        }
    }

    return true;
}


///===========================================================================
/// FUNCION   : void Pantalla(Casilla Mat[12][12], int Pantalla)
/// ACCION    : Pantalla del juego
/// PARAMETROS: Casilla Mat[12][12]: matriz del juego
///             int Pantalla: pantalla seleccionada por el usuario
/// DEVUELVE  : NADA.
///---------------------------------------------------------------------------
void Pantalla(Casilla Mat[12][12], int Pantalla)
{

    int Disparos = 0,Fila = 0, Columna = 0,Cod_Val, Total_BR = 10, Vec_BR [4],i = 0;
    char Fchar[3], Cchar[3];

    bool Tocado = false, Flash = false, Salir = false, Ganador = false, ColOK = false, FilOK = false;

    Barcos_Restantes(Vec_BR);
    if (Pantalla == 1)
    {
        Disparos = 50;
    }
    else
    {
        Disparos = 25;
    }

    for (int x=Disparos; x>0; x--)
    {
        Texto_Pantalla(&Fila,&Columna,x,Vec_BR);
        //SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
        MostrarMat(Mat,1);

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);

        cout << "Ingrese la fila: " ;
        sys::getline(Fchar,2);

        cout << "Ingrese la Columna: " ;
        sys::getline(Cchar,2);

        if (ValidaInt(Fchar)&&ValidaInt(Cchar))
        {

            Fila = strToInt(Fchar);
            Columna = strToInt(Cchar);

            Cod_Val = Validacion(Fila,Columna);

            if(Cod_Val == 2)
            {
                cout << "" << endl;
                cout << "Usted Ingresó una coordenada incorrecta" << endl;
                cin.get();
                cin.ignore();
                x++;
            }
            if(Cod_Val == 0)
            {
                Salir = Valida_Salir();
                x++;
                if(Salir == true)
                {
                    GameOver(Total_BR);
                    MostrarMat(Mat,0);
                    x = 0;
                }

            }
            if (Cod_Val == 11)
            {
                if(Flash == false)
                {
                    sys::cls();
                    MostrarMat(Mat,0);
                    sys::msleep(3);
                    x++;
                    Flash = true;
                }
                else
                {
                    cout << "" << endl;
                    cout << "El tablero ya ha sido mostrado" << endl;
                    cin.get();
                    cin.ignore();
                    x++;
                }
            }
            if (Cod_Val == 12)
            {
                sys::cls();
                Ayuda();
                x++;
            }
            if (Cod_Val == 1)
            {
                Tocado = Verificar_Tocado(Mat,Fila,Columna);

                if (Tocado == true)
                {

                    Escribir_Matriz(Mat,Fila,Columna,Total_BR,Vec_BR);
                    Ganador = Valida_Ganador(Vec_BR);
                        if(Ganador == true)
                            {
                                Pantalla_Ganador();
                                MostrarMat(Mat,0);
                                cin.get();
                                x = 0;
                            }
                }
                else
                {
                    if(Mat[Fila][Columna].Visible != 'T' && Mat[Fila][Columna].Visible != 'H')
                    {
                        Mat[Fila][Columna].Visible = 'A';
                    }
                }
            }

        }
        else
        {
            cout << "Ingrese solo números";
            i++;
            cin.get();

        }

    }
    if (!Ganador)
    {
        GameOver(Total_BR);
        MostrarMat(Mat,0);
        cin.get();
        cin.ignore();
    }

}
#endif // JUEGO_H_INCLUDED
