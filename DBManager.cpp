#include "DBManager.h"
#include <Windows.h>
#include <stdio.h>
#include <sqlext.h>
#include <string>
#include <iostream>
#include <ctime>
#include <list>

using namespace std;

//#include "CCompra.hpp"
//#include "CDateTime.hpp"
//#include "CFarmacia.hpp"
//#include "CMedCompra.hpp"
//#include "CMedFarm.hpp"
//#include "CMedicamento.hpp"
//#include "CMedProv.hpp"
//#include "CPos.hpp"
//#include "CProveedor.hpp"
//#include "CTransport.hpp"
//#include "CVehiculo.hpp"
//#include "CVenta.hpp"


// CONECTAR CON MYSQL
CDBManager::CDBManager() {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	// We want ODBC 3 support
	ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	if (ret == SQL_SUCCESS) {
		// Allocate a connection handle
		SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
		/*wchar_t w_connection[100];
		string connection = ("DSN=MySQLCon;");
		MultiByteToWideChar(CP_UTF8, 0, connection.c_str(), -1, w_connection, 100);*/
		// stablish connection. ODBC DSN configuration is required
		ret = SQLDriverConnect(dbc, NULL, (SQLCHAR*) "DSN=MySQLCon", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
		ret = SQLSetConnectAttr(dbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)FALSE, 0);
		if (ret != SQL_SUCCESS) {
			// you can get the error in the message string.
			cout << "Connection failed\n";
			SQLWCHAR status[10]; SQLINTEGER error;
			SQLSMALLINT i_size; SQLWCHAR message[1000];
			SQLGetDiagRec(SQL_HANDLE_DBC, dbc, 1, (SQLCHAR*) status, &error, (SQLCHAR*) message, 1000, &i_size);
		}
		else
		{
			cout << "Connection succesful\n";
		}
	}
}

// DESCONECTARSE DE MYSQL
CDBManager::~CDBManager()
{
	ret = SQLFreeStmt(stmt, SQL_CLOSE);
	if (stmt != NULL)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, stmt);
	}
}

//QUERIES
SQLHSTMT CDBManager::LaunchQuery(std::string query) {
	if (ret == SQL_SUCCESS)
	{
		// Allocate a statement handle
		ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
		ret = SQLSetConnectAttr(dbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)TRUE, 0);
		wchar_t wcstring[100];
		// conversion from UTF8 to UNICODE
		MultiByteToWideChar(CP_UTF8, 0, query.c_str(), -1, wcstring, 100);
		// query execution
		ret = SQLExecDirect(stmt, (SQLCHAR*) wcstring, SQL_NTS);
	}
}


CFarmacia* CDBManager::GetFarmacia(int id_farmacia)				//Devuelve los datos de una farmacia
{
	SQLHSTMT stmt = LaunchQuery("SELECT POS_X, POS_Y FROM FARMACIA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ");");
	SQLRETURN ret;
	CFarmacia* farmacia;
	CPos* posicion;
	std::list<CMedFarm*> medicamentos_farmacia;
	SQLINTEGER indicator;
	SQLDOUBLE pos_x, pos_y;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 3, SQL_C_DOUBLE, &pos_x, 0, &indicator);
	  ret = SQLGetData(stmt, 4, SQL_C_DOUBLE, &pos_y, 0, &indicator);


	  medicamentos_farmacia = GetMedFarm(id_farmacia);

	  posicion = new CPos(pos_x, pos_y);
	  farmacia = new CFarmacia(id_farmacia, posicion, medicamentos_farmacia);
	}

	return farmacia;
}


std::list<CFarmacia*> CDBManager::GetGrupoFarmacias()				//Devuelve una lista de farmacias con sus datos
{
	SQLHSTMT stmt = LaunchQuery("SELECT ID_FARMACIA, POS_X, POS_Y FROM FARMACIA;");
	SQLRETURN ret;
	std::list<CFarmacia*> grupo_farmacias;
	CPos* posicion;
	std::list<CMedFarm*> medicamentos_farmacia;
	SQLINTEGER indicator, id_farmacia;
	SQLDOUBLE pos_x, pos_y;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		/* see lab 3 and complete this while */
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &id_farmacia, 0, &indicator);
		ret = SQLGetData(stmt, 3, SQL_C_DOUBLE, &pos_x, 0, &indicator);
		ret = SQLGetData(stmt, 4, SQL_C_DOUBLE, &pos_y, 0, &indicator);

		//get lista medicamentos (hacer funcion nueva)
		medicamentos_farmacia = GetMedFarm(id_farmacia);

		posicion = new CPos(pos_x, pos_y);
		grupo_farmacias.push_back(new CFarmacia(id_farmacia, posicion, medicamentos_farmacia));

	}

	return grupo_farmacias;
}


std::list<CMedicamento*> CDBManager::GetListaMedicamentos(int id_farmacia)				//Devuelve la lista de medicamentos de una farmacia
{
	SQLHSTMT stmt = LaunchQuery("SELECT CN FROM MEDICAMENTO_FARMACIA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ");");
	SQLRETURN ret;
	std::list<CMedicamento*> medicamentos;
	SQLINTEGER indicator;
	SQLDOUBLE CN;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 1, SQL_C_DOUBLE, &CN, 0, &indicator);


	  medicamentos.push_back(new CMedicamento(CN));
	}

	return medicamentos;
}


std::list<CMedFarm*> CDBManager::GetMedFarm(int id_farmacia)				//Devuelve cantidad, max y min de cada medicamento en una farmacia
{
	SQLHSTMT stmt = LaunchQuery("SELECT CN, CANTIDAD, CANTIDAD_MIN, CANTIDAD_MAX FROM MEDICAMENTO_FARMACIA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ");");
	SQLRETURN ret;
	std::list<CMedFarm*> medfarm;
	SQLINTEGER indicator;
	SQLDOUBLE CN;
	SQLINTEGER cantidad, cantidad_min, cantidad_max;



	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 1, SQL_C_DOUBLE, &CN, 0, &indicator);
	  ret = SQLGetData(stmt, 2, SQL_C_LONG, &cantidad, 0, &indicator);
	  ret = SQLGetData(stmt, 3, SQL_C_LONG, &cantidad_min, 0, &indicator);
	  ret = SQLGetData(stmt, 3, SQL_C_LONG, &cantidad_max, 0, &indicator);

	  medfarm.push_back(new CMedFarm(cantidad, cantidad_min, cantidad_max, new CMedicamento(CN)));
	}

	return medfarm;
}



void CDBManager::NuevaVenta(CVenta* venta)				//Crea una nueva venta
{
	int cantidad = venta->getCantidad();
	CDateTime* fecha_datetime = venta->getFecha();
	int fecha = fecha_datetime->getTime_t();
	CMedicamento* medicamento = venta->getMedicamento();
	float CN = medicamento->get_cn();
	int id_venta = venta->getIDVenta();
	CFarmacia* farmacia = venta->getFarmacia();
	int id_farmacia = farmacia->get_ID();


	SQLHSTMT stmt = LaunchQuery("INSERT INTO VENTA(ID_FARMACIA, CANTIDAD, FECHA, ID_VENTA, CN)  VALUES (" + std::to_string(id_farmacia) + "," + std::to_string(cantidad) + "," + std::to_string(fecha) + "," + std::to_string(id_venta) + "," + std::to_string(CN) + ");");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
	
	return;
}


void CDBManager::BorrarVenta(int id_venta)				//Borra la venta con identificador id_venta
{
	SQLHSTMT stmt = LaunchQuery("DELETE FROM VENTA WHERE ID_VENTA = " + std::to_string(id_venta) + ";");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}



//void CDBManager::ActualizarVenta(int id_farmacia, int cantidad, CDateTime* fecha, int id_venta, float CN)				//Nos permite editar una venta
//{
//	SQLHSTMT stmt = LaunchQuery("UPDATE VENTA SET CANTIDAD = " + std::to_string(cantidad) + " , FECHA = " + std::to_string(fecha) + " ,ID_FARMACIA = " + std::to_string(id_farmacia) + ",CN = " + std::to_string(CN) + " WHERE ID_VENTA = " + std::to_string(id_venta) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}




//void CDBManager::NuevaCompra(int id_farmacia, int cantidad, CDateTime* fecha, float precio, int id_compra, float CN)				//Nos permite introducir una nueva compra en el sistema
//{
//	SQLHSTMT stmt = LaunchQuery("INSERT INTO COMPRA(ID_FARMACIA, CANTIDAD, FECHA, PRECIO, ID_COMPRA, CN)  VALUES (" + std::to_string(id_farmacia) + "," + std::to_string(cantidad) + "," + std::to_string(fecha) + "," + std::to_string(precio) + "," + std::to_string(id_compra) + "," + std::to_string(CN) + ");");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA COMPRA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}


void CDBManager::BorrarCompra(int id_compra)				//Nos permite borrar una compra del sistema
{
	SQLHSTMT stmt = LaunchQuery("DELETE FROM COMPRA WHERE ID_COMPRA = " + std::to_string(id_compra) + ";");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}


//void CDBManager::ActualizarCompra(int id_farmacia, int cantidad, CDateTime* fecha, float precio, int id_compra, float CN)				//Nos permite editar una compra
//{
//	SQLHSTMT stmt = LaunchQuery("UPDATE COMPRA SET CANTIDAD = " + std::to_string(cantidad) + " , FECHA = " + std::to_string(fecha) + " ,ID_FARMACIA = " + std::to_string(id_farmacia) + " ,CN = " + std::to_string(CN) + " ,PRECIO = " + std::to_string(precio) + " WHERE ID_COMPRA = " + std::to_string(id_compra) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}


void CDBManager::NuevoMedicamento(float CN)				//Nos permite introducir un nuevo medicamento en stock
{
	SQLHSTMT stmt = LaunchQuery("INSERT INTO MEDICAMENTO(CN)  VALUES (" + std::to_string(CN) + ");");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA COMPRA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}


void CDBManager::BorrarMedicamento(float CN)				//Nos permite borrar un medicamento del sistema. Así si no se quiere tener más stock de un medicamento se evita que la inteligencia compre más cuando quede poco
{
	SQLHSTMT stmt = LaunchQuery("DELETE FROM MEDICAMENTO WHERE CN = " + std::to_string(CN) + ";");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}


void CDBManager::NuevoProveedor(float id_proveedor, char* nombre)				//Nos permite introducir un nuevo medicamento en stock
{
	SQLHSTMT stmt = LaunchQuery("INSERT INTO PROVEEDOR(ID_PROVEEDOR, NOMBRE)  VALUES (" + std::to_string(id_proveedor) + "," + std::to_string(*nombre) + ");");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA COMPRA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}



void CDBManager::BorrarProveedor(int id_proveedor)				//Nos permite borrar una compra del sistema
{
	SQLHSTMT stmt = LaunchQuery("DELETE FROM PROVEEDOR WHERE ID_PROVEEDOR = " + std::to_string(id_proveedor) + ";");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}


void CDBManager::ActualizarProveedor(int id_proveedor, char* nombre)				//Nos permite editar una compra
{
	SQLHSTMT stmt = LaunchQuery("UPDATE PROVEEDOR SET ID_PROVEEDOR = " + std::to_string(id_proveedor) + " , NOMBRE = " + std::to_string(*nombre) + ";");

	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?

	return;
}

//void getCurrentDate(void)
//{
//	SQLHSTMT stmt = LaunchQuery("CURRENT_TIMESTAMP()");
//	SQLRETURN ret;
//
//	//faltan cosas
//
//	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
//	{
//		/* see lab 3 and complete this while */
//		ret = SQLGetData(stmt, 1, SQL_C_DATE, &fecha, 0, &indicator);
//
//		//faltan
//	}
//}