#include "DBManager.h"

#include <Windows.h>
#include <stdio.h>
#include <sqlext.h>
#include <string>
#include <iostream>
#include <ctime>
#include <list>

using namespace std;

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
		SQLWCHAR status[10]; SQLINTEGER error;
		SQLSMALLINT i_size; SQLWCHAR message[1000];
		if (ret != SQL_SUCCESS) {
			// you can get the error in the message string.
			cout << "Connection failed\n";

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

		// Allocate a statement handle
		ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
		ret = SQLSetConnectAttr(dbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)TRUE, 0);
		// query execution
		ret = SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS);
		return stmt;
}


CFarmacia* CDBManager::GetFarmacia(int id_farmacia)				//Devuelve los datos de una farmacia
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT POSICION_X, POSICION_Y FROM FARMACIA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
	
	CFarmacia* farmacia=NULL;
	CPos* posicion;
	std::list<CMedFarm*> medicamentos_farmacia;
	SQLINTEGER indicator;
	SQLREAL pos_x, pos_y;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 1, SQL_C_FLOAT, &pos_x, 0, &indicator);
	  ret = SQLGetData(stmt, 2, SQL_C_FLOAT, &pos_y, 0, &indicator);


	  medicamentos_farmacia = GetMedFarm(id_farmacia);

	  posicion = new CPos(pos_x, pos_y);
	  farmacia = new CFarmacia(id_farmacia, posicion, medicamentos_farmacia);
	}

	stmt = stmt1;

	return farmacia;
}


std::list<CFarmacia*> CDBManager::GetListaFarmacias()				//Devuelve una lista de farmacias con sus datos
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT ID_FARMACIA, POSICION_X, POSICION_Y FROM FARMACIA;");
	
	std::list<CFarmacia*> grupo_farmacias;
	CPos* posicion;
	std::list<CMedFarm*> medicamentos_farmacia;
	SQLINTEGER indicator, id_farmacia;
	SQLREAL pos_x, pos_y;

	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &id_farmacia, 0, &indicator);
		ret = SQLGetData(stmt, 2, SQL_C_FLOAT, &pos_x, 0, &indicator);
		ret = SQLGetData(stmt, 3, SQL_C_FLOAT, &pos_y, 0, &indicator);

		medicamentos_farmacia = GetMedFarm(id_farmacia);

		posicion = new CPos(pos_x, pos_y);
		grupo_farmacias.push_back(new CFarmacia(id_farmacia, posicion, medicamentos_farmacia));

	}

	stmt = stmt1;

	return grupo_farmacias;
}


std::list<CMedicamento*> CDBManager::GetListaMedicamentos(int id_farmacia)				//Devuelve la lista de medicamentos de una farmacia
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT CN FROM MEDFARM WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
	
	std::list<CMedicamento*> medicamentos;
	SQLINTEGER indicator;
	SQLREAL CN;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 1, SQL_C_FLOAT, &CN, 0, &indicator);


	  medicamentos.push_back(new CMedicamento(CN));
	}

	stmt = stmt1;

	return medicamentos;
}


std::list<CMedFarm*> CDBManager::GetMedFarm(int id_farmacia)				//Devuelve cantidad, max y min de cada medicamento en una farmacia
{
	SQLHSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT CN, CANTIDAD, CANTIDAD_MIN, CANTIDAD_MAX FROM MEDFARM WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
	
	std::list<CMedFarm*> medfarm;
	SQLINTEGER indicator;
	SQLREAL CN;
	SQLINTEGER cantidad, cantidad_min, cantidad_max;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
	  /* see lab 3 and complete this while */
	  ret = SQLGetData(stmt, 1, SQL_C_FLOAT, &CN, 0, &indicator);
	  ret = SQLGetData(stmt, 2, SQL_C_LONG, &cantidad, 0, &indicator);
	  ret = SQLGetData(stmt, 3, SQL_C_LONG, &cantidad_min, 0, &indicator);
	  ret = SQLGetData(stmt, 4, SQL_C_LONG, &cantidad_max, 0, &indicator);

	  medfarm.push_back(new CMedFarm(cantidad, cantidad_min, cantidad_max, new CMedicamento(CN)));
	}

	stmt = stmt1;

	return medfarm;
}

std::list<CProveedor*> CDBManager::GetListaProveedores()				//Devuelve una lista de farmacias con sus datos
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT ID_PROVEEDOR, NOMBRE FROM PROVEEDOR;");
	
	std::list<CProveedor*> lista_proveedores;
	std::list<CMedProv*> medicamentos_proveedor;
	SQLCHAR nombre[20];
	SQLINTEGER indicator, id_proveedor;

	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &id_proveedor, 0, &indicator);
		ret = SQLGetData(stmt, 2, SQL_C_CHAR, &nombre, 20, &indicator);

		//get lista proveedores
		medicamentos_proveedor = GetMedProv(id_proveedor);

		std::string snombre = (string)(char*)nombre;

		lista_proveedores.push_back(new CProveedor(id_proveedor, snombre, medicamentos_proveedor));

	}

	stmt = stmt1;

	return lista_proveedores;
}

std::list<CMedProv*> CDBManager::GetMedProv(int id_proveedor)				//Devuelve lista de medicamentos y precios de un proveedor
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT CN, PRECIO FROM MEDPROV WHERE ID_PROVEEDOR = " + std::to_string(id_proveedor) + ";");
	
	std::list<CMedProv*> medprov;
	SQLINTEGER indicator;
	SQLREAL CN, precio;



	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_FLOAT, &CN, 0, &indicator);
		ret = SQLGetData(stmt, 2, SQL_C_FLOAT, &precio, 0, &indicator);

		medprov.push_back(new CMedProv(new CMedicamento(CN), precio));
	}

	stmt = stmt1;

	return medprov;
}


void CDBManager::NuevaVenta(CVenta* venta)				//Crea una nueva venta
{
	HSTMT stmt1 = stmt;

	int cantidad_vendida = venta->getCantidad();
	CDateTime* fecha_datetime = venta->getFecha();
	int year = fecha_datetime->getYear();
	int month = fecha_datetime->getMonth();
	int day = fecha_datetime->getDay();
	CMedicamento* medicamento = venta->getMedicamento();
	float CN = medicamento->get_cn();
	CFarmacia* farmacia = venta->getFarmacia();
	int id_farmacia = farmacia->get_ID();

	int cantidad_antigua;
	int cantidad;


	stmt = LaunchQuery("INSERT INTO VENTA(ID_FARMACIA, CANTIDAD, FECHA, CN)  VALUES (" + std::to_string(id_farmacia) + "," + std::to_string(cantidad_vendida) + ", '" + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + "' ,"  + std::to_string(CN) + ");");

	cantidad_antigua = GetCantidadMedFarm(id_farmacia, CN);

	cantidad = cantidad_antigua - cantidad_vendida;

	ActualizarMedFarmVenta(id_farmacia, CN, cantidad);

	stmt = stmt1;

	return;
}

int CDBManager::GetCantidadMedFarm(int id_farmacia, float CN)			//Devuelve una lista de farmacias con sus datos
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT CANTIDAD FROM MEDFARM WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ", CN = " + std::to_string(CN) + ";");
	
	SQLINTEGER indicator, cantidad;

	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &cantidad, 0, &indicator);
	}

	stmt = stmt1;

	return cantidad;
}

void CDBManager::ActualizarMedFarmVenta(int id_farmacia, float CN, int cantidad)
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("UPDATE MEDFARM SET CANTIDAD = " + std::to_string(cantidad) + "WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ", CN = " + std::to_string(CN) + ";");

	stmt = stmt1;

	return;
}

void CDBManager::BorrarUltimaVenta()				//Borra la venta con identificador id_venta
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("SELECT ID_VENTA, ID_FARMACIA, CANTIDAD, CN FROM VENTA ORDER BY ID_VENTA DESC LIMIT 1;");

	SQLINTEGER indicator, id_venta, id_farmacia, cantidad_vendida;
	SQLREAL CN;


	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &id_venta, 0, &indicator);
		ret = SQLGetData(stmt, 2, SQL_C_LONG, &id_farmacia, 0, &indicator);
		ret = SQLGetData(stmt, 3, SQL_C_LONG, &cantidad_vendida, 0, &indicator);
		ret = SQLGetData(stmt, 4, SQL_C_FLOAT, &CN, 0, &indicator);
	}

	int cantidad_actual = GetCantidadMedFarm(id_farmacia, CN);

	int cantidad = cantidad_actual + cantidad_vendida;

	ActualizarMedFarmVenta(id_farmacia, CN, cantidad);

	stmt = LaunchQuery("DELETE FROM VENTA WHERE ID_VENTA = " + std::to_string(id_venta) + ";");

	stmt = stmt1;

	return;
}



void CDBManager::BorrarProveedor(int id_proveedor)				//Nos permite borrar una compra del sistema
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("DELETE FROM MEDPROV WHERE ID_PROVEEDOR = " + std::to_string(id_proveedor) + ";");
	stmt = LaunchQuery("DELETE FROM MEDCOMPRA WHERE ID_PROVEEDOR = " + std::to_string(id_proveedor) + ";");
	stmt = LaunchQuery("DELETE FROM PROVEEDOR WHERE ID_PROVEEDOR = " + std::to_string(id_proveedor) + ";");

	stmt = stmt1;

	return;
}

//void CDBManager::BorrarFarmacia(int id_farmacia)				//Nos permite borrar una compra del sistema
//{
//	HSTMT stmt1 = stmt;
//
//	stmt = LaunchQuery("DELETE FROM VENTA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
//	stmt = LaunchQuery("DELETE FROM MEDFARM WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
//	stmt = LaunchQuery("DELETE FROM TRANSPORTE WHERE ID_FARMACIA_DESDE = " + std::to_string(id_farmacia) + ";");
//	stmt = LaunchQuery("DELETE FROM TRANSPORTE WHERE ID_FARMACIA_HACIA = " + std::to_string(id_farmacia) + ";");
//	stmt = LaunchQuery("DELETE FROM COMPRA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
//	stmt = LaunchQuery("DELETE FROM FARMACIA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + ";");
//
//	stmt = stmt1;
//
//	return;
//}

void CDBManager::NuevaCompra(CCompra* compra)				//Nos permite introducir una nueva compra en el sistema
{//compra: idfarmacia, fecha,idcompra**
 //medcompra: idcompra**,cn,cantidad,idproveedor,precio
 //ccompra:fecha,cfarmacia(idfarmacia),cmedcompra(cmedicamento(cn),cantidad,precio,cproveedor(id,nombre*,meds*))
	HSTMT stmt1 = stmt;

	// Coger datos de CCompra
	CDateTime* fecha_datetime = compra->getFecha();
	int year = fecha_datetime->getYear();
	int month = fecha_datetime->getMonth();
	int day = fecha_datetime->getDay();
	CFarmacia* farmacia = compra->getFarmacia();
	int id_farmacia = farmacia->get_ID();
	list<CMedCompra*> medcompras = compra->getMedCompra();

	int cantidad_antigua=NULL;
	int cantidad;

	stmt = LaunchQuery("INSERT INTO COMPRA(ID_FARMACIA, FECHA)  VALUES (" + std::to_string(id_farmacia) + ", '" + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + "');");

	stmt = LaunchQuery("SELECT ID_COMPRA FROM COMPRA WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + "AND FECHA = '" + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + "';");

	SQLINTEGER indicator, id_compra;

	while ((ret = SQLFetch(stmt)) == SQL_SUCCESS)
	{
		ret = SQLGetData(stmt, 1, SQL_C_LONG, &id_compra, 0, &indicator);
	}


	list<CMedCompra*>::iterator it_medcompras;
	for (it_medcompras = medcompras.begin(); it_medcompras != medcompras.end(); ++it_medcompras)
	{
		cantidad_antigua = NULL;

		CMedicamento* med = (*it_medcompras)->get_med();
		float CN = med->get_cn();
		int cantidad_comprada = (*it_medcompras)->get_cantidad();
		float precio = (*it_medcompras)->get_price();
		CProveedor* prov = (*it_medcompras)->get_proveedor();
		int id_proveedor = prov->get_id_proveedor();

		// Actualizar MedFarm con nueva cantidad de medicamentos
		cantidad_antigua = GetCantidadMedFarm(id_farmacia, CN);

		if (cantidad_antigua == NULL)
		{
			//Hacer nueva fila en MedCompra
			NuevaMedFarmCompra(id_farmacia, CN, cantidad, id_proveedor, precio);
		}
		else
		{
			//Actualizar cantidad de ese medicamento en MedCompra
			cantidad = cantidad_antigua + cantidad_comprada;
			ActualizarMedFarmCompra(id_farmacia, CN, cantidad, id_proveedor, precio);
		}
		
	}	

	stmt = stmt1;

	return;
}

void CDBManager::ActualizarMedFarmCompra(int id_farmacia, float CN, int cantidad, int id_proveedor, float precio)
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("UPDATE MEDCOMPRA SET CANTIDAD = " + std::to_string(cantidad) + "WHERE ID_FARMACIA = " + std::to_string(id_farmacia) + " AND CN = " + std::to_string(CN) + " AND ID_PROVEEDOR = " + std::to_string(id_proveedor) + " AND PRECIO = " + std::to_string(precio) + ";");

	stmt = stmt1;

	return;
}

void CDBManager::NuevaMedFarmCompra(int id_farmacia, float CN, int cantidad, int id_proveedor, float precio)
{
	HSTMT stmt1 = stmt;

	stmt = LaunchQuery("INSERT INTO MEDCOMPRA(ID_FARMACIA,CN,CANTIDAD,ID_PROVEEDOR,PRECIO) VALUES(" + std::to_string(id_farmacia) + ", " + std::to_string(CN) + ", " + std::to_string(cantidad) + ",  " + std::to_string(id_proveedor) + ", " + std::to_string(precio) + ");");

	stmt = stmt1;

	return;
}








//void CDBManager::BorrarCompra(int id_compra)				//Nos permite borrar una compra del sistema
//{
//	SQLHSTMT stmt = LaunchQuery("DELETE FROM COMPRA WHERE ID_COMPRA = " + std::to_string(id_compra) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}


//void CDBManager::ActualizarCompra(int id_farmacia, int cantidad, CDateTime* fecha, float precio, int id_compra, float CN)				//Nos permite editar una compra
//{
//	SQLHSTMT stmt = LaunchQuery("UPDATE COMPRA SET CANTIDAD = " + std::to_string(cantidad) + " , FECHA = " + std::to_string(fecha) + " ,ID_FARMACIA = " + std::to_string(id_farmacia) + " ,CN = " + std::to_string(CN) + " ,PRECIO = " + std::to_string(precio) + " WHERE ID_COMPRA = " + std::to_string(id_compra) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}


//void CDBManager::NuevoMedicamento(float CN)				//Nos permite introducir un nuevo medicamento en stock
//{
//	SQLHSTMT stmt = LaunchQuery("INSERT INTO MEDICAMENTO(CN)  VALUES (" + std::to_string(CN) + ");");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA COMPRA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}
//
//
//void CDBManager::BorrarMedicamento(float CN)				//Nos permite borrar un medicamento del sistema. Así si no se quiere tener más stock de un medicamento se evita que la inteligencia compre más cuando quede poco
//{
//	SQLHSTMT stmt = LaunchQuery("DELETE FROM MEDICAMENTO WHERE CN = " + std::to_string(CN) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}
//
//
//void CDBManager::NuevoProveedor(float id_proveedor, char* nombre)				//Nos permite introducir un nuevo medicamento en stock
//{
//	SQLHSTMT stmt = LaunchQuery("INSERT INTO PROVEEDOR(ID_PROVEEDOR, NOMBRE)  VALUES (" + std::to_string(id_proveedor) + "," + std::to_string(*nombre) + ");");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA COMPRA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}
//
//
//

//
//
//void CDBManager::ActualizarProveedor(int id_proveedor, char* nombre)				//Nos permite editar una compra
//{
//	SQLHSTMT stmt = LaunchQuery("UPDATE PROVEEDOR SET ID_PROVEEDOR = " + std::to_string(id_proveedor) + " , NOMBRE = " + std::to_string(*nombre) + ";");
//
//	//IGUAL PODEMOS LEER LOS DATOS DE ESA VENTA E IMPRIMIRLOS POR PANTALLA PARA QUE EL USUARIO COMPRUEBE QUE HA METIDO BIEN LOS DATOS?
//
//	return;
//}

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