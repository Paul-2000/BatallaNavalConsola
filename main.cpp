///#############################################################################
/// ARCHIVO             : main.extension
/// AUTOR/ES            : Antoni Briceño
/// VERSION             : 0.52.
/// FECHA DE CREACION   : 17/11/2018.
/// ULTIMA ACTUALIZACION: 22/02/2019.
/// LICENCIA            : GPL (General Public License) - Version 3.
///
///  **************************************************************************
///  * El software libre no es una cuestion economica sino una cuestion etica *
///  **************************************************************************
///
/// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
/// los terminos de la Licencia Publica General de GNU  tal como se publica por
/// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
/// eleccion) cualquier version posterior.
///
/// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
/// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
/// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
///
/// Vea la Licencia Publica General GNU para mas detalles.
///
/// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
/// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
/// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

///=============================================================================
/// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
/// IDE                 : Code::Blocks - 8.02 / 10.05
/// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
/// LICENCIA            : GPL (General Public License) - Version 3.
///=============================================================================
/// DESCRIPCION:
///              Breve explicacion sobre el contenido del archivo.
///
////////////////////////////////////////////////////////////////////////////////

///*****************************************************************************
///                       CONFIGURACION MULTIPLATAFORMA
///=============================================================================
/// COMPILACION EN WINDOWS
///-----------------------------------------------------------------------------
/// Si este programa se va a compilar en Windows, descomente las tres lineas
/// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
///-----------------------------------------------------------------------------
#ifndef _WIN32
  # define _WIN32
#endif

///=============================================================================
/// COMPILACION EN LINUX
///-----------------------------------------------------------------------------
/// Si este programa se va a compilar en Linux, descomente las tres lineas
/// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
///-----------------------------------------------------------------------------
///#ifndef _LINUX
///  # define _LINUX
///#endif

///*****************************************************************************
///                             INCLUSIONES ESTANDAR
///=============================================================================
#include <iostream> /// Libreria de flujos de  Entrada/Salida  que contiene  los
                    /// objetos cin, cout y endl.

#include <cstdlib>  /// Libreria estandar que contiene la funcion exit().

///*****************************************************************************
///                             INCLUSIONES PERSONALES
///=============================================================================
#include "CSYSTEM/csystem.h" /// Libreria para multiplataforma.

#include "Juego.h" /// Libreria de todas las funciones del juego.

#include "Menus.h" /// Libreria donde estan los menus del juego.
///==============================================================================
/// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
///------------------------------------------------------------------------------
using namespace std;


///==============================================================================
/// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
///------------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "spanish");
    int Nivel = 0;
    char Opcion;
    bool salir = false;
    Casilla Mat[12][12] ;
    sys::randomize();

    Presentacion_Inicial();
    sys::msleep(1);


    while (!salir)
    {
        sys::cls();

        cout << " _____________________________________________________________" << endl;
        cout << "|                      BATALLA NAVAL                          |" << endl;
        cout << "|_____________________________________________________________|" << endl;
        cout << "|                                                             |" << endl;
        cout << "|         J.JUGAR                                             |" << endl;
        cout << "|         A.AYUDA                                             |" << endl;
        cout << "|         S.SALIR                                             |" << endl;
        cout << "|                                                             |" << endl;
        cout << "|_____________________________________________________________|" << endl;


        Opcion = ValidarOpcion("Ingrese una opción: ","opción no valida");



        switch(Opcion)
        {
        case 'J':
        case 'j':
        {
            CargarBarcos(Mat);

            Nivel = Eleccion_Nivel();
            sys::cls();
            Pantalla(Mat,Nivel);

        }
        break;
        case 'A':
        case 'a':
        {
            Ayuda();
        }
        break;
        case 'S':
        case 's':
        {
            salir = true;
            Despedida();
        }
        break;
        default:
        {
            sys::cls();
            cout << "Ingrese una opción valida" << endl;
            cout << "presione una tecla para continuar..."<< endl;
            cin.get();
        }
        }
    }


    ///--------------------------------------------------------------------------
    /// FIN DE LA FUNCION main() SIN ERRORES.
    ///--------------------------------------------------------------------------
    return 0;
}

///=============================================================================
///                            FIN DE ARCHIVO
///#############################################################################

