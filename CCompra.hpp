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
		CDateTime* m_fecha;
		list<CMedCompra*> m_meds;
		CFarmacia* m_farmacia;

	public:
		CCompra(){};
		CCompra(CFarmacia* to_farmacia,list<CMedCompra*>);
		CCompra(CFarmacia* to_farmacia,list<CMedCompra*> med_needed);
		~CCompra();

		void find_proveedor(list<CProveedor*> global_proveedores);
<<<<<<< HEAD
		int get_id(void);
    friend ostream& operator<<(std::ostream& o, CCompra* compra);
=======
        friend ostream& operator<<(std::ostream& o, CCompra* compra);
>>>>>>> b1db800fe190d0ef1ec0e0e99dc21235c5ac5d19

		list<CMedCompra*> getMedCompra(void) { return m_meds; };
		CDateTime* getFecha(void) { return m_fecha; };
		CFarmacia* getFarmacia(void) { return m_farmacia; };
};

#endif
