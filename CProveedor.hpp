#ifndef CPROVEEDOR
#define CPROVEEDOR
#pragma once

#include <iostream>
#include <string>
#include "CMedicamento.hpp"
#include "CMedProv.hpp"
#include <list>

using namespace std;

class CProveedor
{
private:
	int m_i_id_proveedor;
	std::string m_s_nombre;
	list <CMedProv*> m_listmed;
public:
	CProveedor(void);
	CProveedor(const CProveedor& proveedor);
	CProveedor(int m_i_id_proveedor, std::string m_s_nombre, list <CMedProv*> l_medprov);
    
	friend std::ostream& operator<<(std::ostream& os, CProveedor* proveedor);
	friend std::istream& operator>>(std::istream& i, CProveedor* proveedor);

	~CProveedor();
    
    string get_name();
	int get_id();
	int get_id_proveedor(void) { return m_i_id_proveedor; };
	float get_price(CMedicamento* med); //indica el precio de un medicamento en su inventario, devuelve 99999 si no lo tiene
	int med_available(CMedicamento* med); // indica si tiene ese medicamento en su inventario. Devuelve 1 si hay y 0 si no
	
};

#endif
