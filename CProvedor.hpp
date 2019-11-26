#pragma once

#include <iostream>
#include <string>
#include "CMedicamento.h"
#include "CMedProv.h"
#include <list>

using namespace std;

class CProveedor
{
private:
	int m_i_id_proveedor;
	std::string m_s_nombre;
	list <CMedProv*> listamedicamentos;
public:
	CProveedor(void);
	CProveedor(const CProveedor& proveedor);
	CProveedor(int m_i_id_proveedor, std::string m_s_nombre);

	friend std::ostream& operator<<(std::ostream& os, const CProveedor& proveedor);
	friend std::istream& operator>>(std::istream& i, CProveedor& proveedor);

	~CProveedor(void);

	float get_precio(CMedProv* med); //indica el precio de un medicamento en su inventario, devuelve 99999 si no lo tiene
	int med_available(CMedProv* med); // indica si tiene ese medicamento en su inventario. Devuelve 1 si hya y 0 si no
};
