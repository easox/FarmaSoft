#pragma once

#include <iostream>
#include <string>

using namespace std;

class CProveedor
{
private:
	int m_i_id_proveedor;
	std::string m_s_nombre;
public:
	CProveedor(void);
	CProveedor(const CProveedor& proveedor);
	CProveedor(int m_i_id_proveedor,std::string m_s_nombre);
	
	friend std::ostream& operator<<(std::ostream& os, const CProveedor& proveedor);
	friend std::istream& operator>>(std::istream& i, CProveedor& proveedor);

	~CProveedor(void);
};
