///#############################################################################
/// ARCHIVO             : Menus.h
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
/// Este archivo contiene todas las funciones referentes a las presentaciones en el juego.

#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED


///*****************************************************************************
///                             INCLUSIONES ESTANDAR
///=============================================================================

#include "Juego.h"
#include <windows.h>

///*****************************************************************************
///               ESPACIO DE NOMBRES DE LA LIBRERIA Presentacion.h
///=============================================================================
using namespace std;

/// FUNCIONES DEFINIDAS:
///=============================================================================================|
///     NOMBRE                    |  TIPO  |                    ACCION                          |
///===============================+========+====================================================|
/// void Presentacion_Inicial ()  |  void  | Muestra la presentacion inicial del juego          |
///-------------------------------+--------+----------------------------------------------------|
/// int Eleccion_Nivel ()         |  Void  | Consulta al usuario cual es la pantalla a jugar    |
///                               |        | Devuelve: la pantalla seleccionada                 |
///-------------------------------+--------+----------------------------------------------------|
/// void Texto_Pantalla(int *Fila,|  Void  | Muestra el texto de la pantalla del juego          |
///int *Columna, int i,           |        |                                                    |
/// int Vec_BR[4])                |        |                                                    |
///-------------------------------+--------+----------------------------------------------------|
/// int Valida_Salir ()           |  int   | Verifica si el usuario realmente quiere salir de   |
///                               |        | la pantalla del juego                              |
///                               |        |                                                    |
///-------------------------------+--------+----------------------------------------------------|
/// void GameOver(int Barcos_Rest)|  void  | Muestra el texto del GameOver                      |
///-------------------------------+--------+----------------------------------------------------|
/// void Pantalla_Ganador ()      |  void  | Muestra la pantalla cuando el usuario gana         |
///-------------------------------+--------+----------------------------------------------------|

///===========================================================================
/// FUNCION   : void Presentacion_Inicial ()
/// ACCION    : muestra la pantalla inicial del juego
/// PARAMETROS: -
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------

void Presentacion_Inicial ()
{
cout << "\tBBBBB      A   TTTTTTTTT   A     L     L         A" << endl;
cout << "\tB    B    A A      T      A A    L     L        A A" << endl;
cout << "\tBBBBB    A   A     T     A   A   L     L       A   A" << endl;
cout << "\tB    B  AAAAAAA    T    AAAAAAA  L     L      AAAAAAA" << endl;
cout << "\tBBBBB  A       A   T   A       A LLLLL LLLLL A       A" << endl;
cout << endl;
cout << "\t                       @" << endl;
cout << "\t                       @@" << endl;
cout << "\t                      @@@@" << endl;
cout << "\t                     @@||@@" << endl;
cout << "\t                    @@@||@@@" << endl;
cout << "\t                   @@@@||@@@@" << endl;
cout << "\t                  @@@@@||@@@@@" << endl;
cout << "\t 	         @@@@@@||@@@@@@" << endl;
cout << "\t                @@@@@@@||@@@@@@@" << endl;
cout << "\t               @@@@@@@@||@@@@@@@@" << endl;
cout << "\t              @@@@@@@@@||@@@@@@@@@" << endl;
cout << "\t 	     @@@@@@@@@@||@@@@@@@@@@" << endl;
cout << "\t 	    @@@@@@@@@@@||@@@@@@@@@@@" << endl;
cout << "\t           @@@@@@@@@@@@||@@@@@@@@@@@@" << endl;
cout << "\t          @@@@@@@@@@@@@||@@@@@@@@@@@@@" << endl;
cout << "\t 	 @@@@@@@@@@@@@@||@@@@@@@@@@@@@@" << endl;
cout << "\t 	@@@@@@@@@@@@@@@||@@@@@@@@@@@@@@@" << endl;
cout << "\t       @@@@@@@@@@@@@@@@||@@@@@@@@@@@@@@@@" << endl;
cout << "\t 	               ||                  " << endl;
cout << "\t 	     O         ||                   " << endl;
cout << "\t 	 #  /|-¬}      ||             ###########" << endl;
cout << "\t 	###  | ##      ||           ###########=======O " << endl;
cout << "\t       #####/\\ ##      ||           ###########=======O " << endl;
cout << "\t 	#########################################          " << endl;
cout << "\t 	  #####################################      " << endl;
cout << "\t           #################################      " << endl;
cout << "\t 	      #############################        " << endl;
cout << endl;
cout << "\t\tN   N     A   V       V   A     L" << endl;
cout << "\t\tNN  N    A A   V     V   A A    L" << endl;
cout << "\t\tN N N   A   A   V   V   A   A   L" << endl;
cout << "\t\tN  NN  AAAAAAA   V V   AAAAAAA  L"  << endl;
cout << "\t\tN   N A       A   V   A       A LLLLL" << endl;
    sys::msleep(3);
    sys::cls();
}

///===========================================================================
/// FUNCION   : void Ayuda ()
/// ACCION    : muestra la ayuda del juego
/// PARAMETROS: NADA.
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void Ayuda ()
{
    sys::cls();
    cout << " ________________________________________________________________________________" << endl;
    cout << "|                                INSTRUCCIONES                                   |" << endl;
    cout << "|________________________________________________________________________________|" << endl;
    cout << "|                              LA BATALLA NAVAL:                                 |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - El juego consiste en hundir toda la flota contrincante, que esta distri-    |" << endl;
    cout << "|   buida en el tablero                                                          |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - El jugador debe indicar la coordenada a la cual desea atacar: un numero     |" << endl;
    cout << "|   entre 1 y 10 para la fila y un numero entre 1 y 10 para la columna.          |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Si en la coordenada ingresada no hay ningun barco se indicará que tocaste   |" << endl;
    cout << "|    agua con una 'A'.                                                           |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Si en la coordenada ingresada hay parte de un barco, entonces el barco fue  |" << endl;
    cout << "|  tocado y se vera una 'T'.                                                     |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Si en la coordenada ingresada hay un barco, o si tocaste un barco por com-  |" << endl;
    cout << "|    pleto, se vera el barco hundido con una o varias 'H'.                       |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                  NIVELES:                                      |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Hay dos niveles para elegir:.                                               |" << endl;
    cout << "|        - Nivel 1: Tendrás disponible 50 disparos.                              |" << endl;
    cout << "|        - Nivel 2: Tendrás disponible 25 disparos.                              |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                              TECLAS ESPECIALES:                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Para ver por unica vez la ubicacion de los barcos  por tres segundos in-    |" << endl;
    cout << "|     gresa las coordenadas 11:11                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Para ver las Instrucciones de Juego ingresa las coordenadas 12:12           |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - Para abandonar el Juego ingresa las coordenadas 0:0.                        |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|  - El juego finaliza al hundir todos los barcos o al agotar tus tiros.         |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                          ¡¡¡ BUENA SUERTE !!!                                  |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|________________________________________________________________________________|" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                      >> Para volver, presione ENTER <<                         |" << endl;
    cout << "|________________________________________________________________________________|" << endl;
    cin.get();

}
///===========================================================================
/// FUNCION   : void Texto_Pantalla(int *Fila, int *Columna, int i, int Vec_BR[4])
/// ACCION    : muestra la informacion refenrente a la pantalla del juego
/// PARAMETROS: Fila: fila seleccionada por el usuario
///             Columna seleccionada por el usaurio
///             cantidad de vueltas disponibles
///             Vec:BR vector con los barcos restantes
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void Texto_Pantalla(int *Fila, int *Columna, int i, int Vec_BR[4])
{
    sys::cls();
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);

    cout << " ____________________________________________      " << endl;
    cout <<  "|             Ingrese:                      |     " << endl;
    cout <<  "|                                           |     " << endl;
    cout <<  "|   0:0  Salir de la pantalla               |     " << endl;
    cout <<  "|  11:11 Visualizar barcos por 3 segundos   |     " << endl;
    cout <<  "|       (Atencion solo se permite una vez)  |     " << endl;
    cout <<  "|  12:12 Ayuda en Linea                     |     " << endl;
    cout <<  "|___________________________________________|     " << endl;
    cout <<  "|             Indicadores                   |     " << endl;
    cout <<  "|                                           |     " << endl;
    cout <<  "|  Tiros Disponibles " << i <<"                     |     " << endl;
    cout <<  "|  Barcos por hundir de 1: "<< Vec_BR[0] <<"                |     " << endl;
    cout <<  "|  Barcos por hundir de 2: "<< Vec_BR[1] <<"                |     " << endl;
    cout <<  "|  Barcos por hundir de 3: "<< Vec_BR[2] <<"                |     " << endl;
    cout <<  "|  Barcos por hundir de 4: "<< Vec_BR[3] <<"                |     " << endl;
    cout <<  "|___________________________________________|     " << endl;
    cout << "" << endl;

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),14);
}
///===========================================================================
/// FUNCION   : void IniMat(Casilla Mat[12][12])
/// ACCION    : Valida si el usuario quiere salir realmente
/// PARAMETROS:
/// DEVUELVE  : true si quiere salir
///              false si no quiere salir.
///----------------------------------------------------------------------
bool Valida_Salir ()
{
    int Opcion = 0;
    bool Opcion_Correcta = false;


    while (!Opcion_Correcta)
    {
        sys::cls();
        cout << " _____________________________________________________" << endl;
        cout << "|                      SALIR                          |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "|            Usted esta a punto de salir.             |" << endl;
        cout << "|                                                     |" << endl;
        cout << "|            ¿Esta seguro que desea salir?            |" << endl;
        cout << "| 1) Salir.                                           |" << endl;
        cout << "| 0) Volver.                                          |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "\tIngrese la opción deseada: ";cin >> Opcion;cout << "|" << endl;
        cout << "|_____________________________________________________|" << endl;

        cin.ignore();
        if (Opcion == 1)
        {
            Opcion_Correcta = true;
            return true;
        }
        if (Opcion == 0)
        {
            Opcion_Correcta = true;
            return false;
        }
        sys::cls();
        cout << "Usted ingresó una opción no valida, vuelva a intentarlo" << endl;
        cout << "Ingrese una tecla para continuar..." ;
        cin.get();
        cin.ignore();
    }
}
///===========================================================================
/// FUNCION   : void GameOver (int Barcos_Rest)
/// ACCION    : Muestra la pantalla de Gameover
/// PARAMETROS: Barcos restantes.
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void GameOver (int Barcos_Rest)
{
    Barcos_Rest = 10 - Barcos_Rest;
    sys::cls();
    cout << " _____________________________________________________" << endl;
    cout << "|                  GAME OVER                          |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "|      PERDISTE                                       |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|      Hundiste "<< Barcos_Rest <<"                                     |"<< endl;
    cout << "|                                                     |" << endl;
    cout << "|      GRACIAS POR JUGAR!!!                           |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << endl;

}
///===========================================================================
/// FUNCION   : void Pantalla_Ganador ()
/// ACCION    : Muestra la pantalla de ganador
/// PARAMETROS: -
/// DEVUELVE  : NADA.
///----------------------------------------------------------------------
void Pantalla_Ganador ()
{
    sys::cls();
    cout << " _____________________________________________________" << endl;
    cout << "|                  USTED HA GANADO                    |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "|                                                     |" << endl;
    cout << "|      Hundiste todos los barcos                      |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|      GRACIAS POR JUGAR!!!                           |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << endl;

}
void Despedida()
{
    sys::cls();
    system("color D3");
    cout << " _____________________________________________________" << endl;
    cout << "|                                                     |" << endl;
    cout << "|                   ¿TE ABURRISTE?                    |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|              ¡¡MUY BIEN HASTA PRONTO!!              |" << endl;
    cout << "|_____________________________________________________|" << endl;
    sys::msleep(2);
}

#endif // MENUS_H_INCLUDED
