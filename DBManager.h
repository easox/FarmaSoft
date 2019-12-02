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
	std::list<CFarmacia*> GetGrupoFarmacias();
	std::list<CMedicamento*> GetListaMedicamentos(int id_farmacia);
	std::list<CMedFarm*> GetMedFarm(int id_farmacia);
	void NuevaVenta(CVenta* venta);
	void BorrarVenta(int id_venta);
	void ActualizarVenta(int id_farmacia, int cantidad, CDateTime* fecha, int id_venta, float CN);
	void NuevaCompra(int id_farmacia, int cantidad, int year, int month, int day, int hour, int minutes, int seconds, float precio, int id_compra, float CN);
	void BorrarCompra(int id_compra);
	void ActualizarCompra(int id_farmacia, int cantidad, CDateTime* fecha, float precio, int id_compra, float CN);
	void NuevoMedicamento(float CN);
	void BorrarMedicamento(float CN);
	void NuevoProveedor(float id_proveedor, char* nombre);
	void ActualizarProveedor(int id_proveedor, char* nombre);
	void BorrarProveedor(int id_proveedor);
private:
	SQLHSTMT LaunchQuery(std::string query);
	SQLHENV env;
	SQLRETURN ret;
	SQLHSTMT stmt;
	SQLHDBC dbc;
};