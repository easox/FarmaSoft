#pragma once

#include <iostream>
#include <string>
#include <list>
#include "CPos.hpp"
#include "CMedicamento.hpp"
#include "CProvedor.hpp"

class CCompra {
private:
	int m_i_id_compra;
	list<CMedicamento*> m_medicamentos;
	CProveedor* m_proveedor;

public:
	CCompra();
	CCompra(int id_compra, list<CMedicamento> medicamentos, CProveedor proveedor) { m_i_id_compra = id_compra; };
	~CCompra();
	int get_id(void) { return this->m_i_id_compra;}
	CProveedor get_proveedor(void){return *(this->m_proveedor);}
	string get_nombre_proveedor(void) { return *(this->m_proveedor).get_name(); }
	list<CMedicamento*> get_medicamento(void) { return (this->m_medicamentos); }
};

