#include <Windows.h>
#include <stdio.h>
#include <sqlext.h>
#include <string>
#include <iostream>
#include <ctime>
#include <list>

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

class CDBManager {
public:
	CDBManager();
	~CDBManager();
	CFarmacia* GetFarmacia(int id_farmacia);
	std::list<CMedicamento*> GetListaMedicamentos(int id_farmacia);
	std::list<CFarmacia*> GetListaFarmacias();
	std::list<CMedFarm*> GetMedFarm(int id_farmacia);
	std::list<CProveedor*> GetListaProveedores();
	std::list<CMedProv*> GetMedProv(int id_proveedor);
	void NuevaVenta(CVenta* venta);
	int  GetCantidadMedFarm(int id_farmacia, float CN);
	void ActualizarMedFarmVenta(int id_farmacia, float CN, int cantidad_vendida); //Si no existe ese medicamento en la farmacia o no quedan suficientes, imprimir por pantalla y pedir otra venta
	void BorrarUltimaVenta();
	void BorrarProveedor(int id_proveedor);
	int NuevoProveedor(string nombre);
	void InsertMedProv(int id_proveedor, float CN, int precio);
	void NuevaCompra(CCompra* compra);
	void ActualizarMedFarmCompra(int id_farmacia, int id_compra, float CN, int cantidad, int id_proveedor, float precio);
	void NuevaMedFarmCompra(int id_farmacia, int id_compra, float CN, int cantidad, int id_proveedor, float precio);

	//void BorrarFarmacia(int id_farmacia);
	/*void BorrarCompra(int id_compra);
	void ActualizarCompra(int id_farmacia, int cantidad, CDateTime* fecha, float precio, int id_compra, float CN);
	void NuevoMedicamento(float CN);
	void BorrarMedicamento(float CN);
	void ActualizarProveedor(int id_proveedor, char* nombre);*/
private:
	SQLHSTMT LaunchQuery(std::string query);
	SQLHENV env;
	SQLRETURN ret;
	SQLHSTMT stmt;
	SQLHDBC dbc;
};