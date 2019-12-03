// farmasoft.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <Windows.h>
#include <stdio.h>
#include <sqlext.h>
#include <string>
#include <iostream>
#include <ctime>
#include <list>

using namespace std;

#include "DBManager.h"

#include "CCompra.hpp"
#include "CDateTime.hpp"
#include "CFarmacia.hpp"
#include "CMedCompra.hpp"
#include "CMedFarm.hpp"
#include "CMedicamento.hpp"
#include "CMedProv.hpp"
#include "CPos.hpp"
#include "CProveedor.hpp"
#include "CTransport.hpp"
#include "CVehiculo.hpp"
#include "CVenta.hpp"

using namespace std;

int main() 
{
	CDBManager DBManager;
	CFarmacia* farmacia;
	farmacia= DBManager.GetFarmacia(1);
	cout << "Si se imprime esto flipas\n" << endl;
	delete farmacia;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
