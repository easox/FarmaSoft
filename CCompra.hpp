#ifndef CCOMPRA
#define CCOMPRA
#pragma once

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "CDateTime.hpp"
#include "CPos.hpp"
#include "CMedicamento.hpp"
#include "CProveedor.hpp"
#include "CMedFarm.hpp"
#include "CMedCompra.hpp"


class CFarmacia;
class CCompra {
	private:
		int m_i_id_compra;
		CDateTime* m_fecha;
		list<CMedCompra*> m_meds;
		CFarmacia* m_farmacia;

	public:
		CCompra(){};
		CCompra(int id_compra, CFarmacia* to_farmacia,list<CMedCompra*>);
		CCompra(CFarmacia* to_farmacia,list<CMedCompra*> med_needed);
		~CCompra();

		void find_proveedor(list<CProveedor*> global_proveedores);
		int get_id(void);
    friend ostream& operator<<(std::ostream& o, CCompra* compra);

};

#endif
