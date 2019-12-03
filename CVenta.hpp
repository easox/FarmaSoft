#ifndef CVENTA
#define CVENTA
#pragma once

#include <iostream>
#include <ctime>
#include "CMedicamento.hpp"
#include "CDateTime.hpp"

class CFarmacia;
class CVenta{
  private:
    CMedicamento* m_med_vendido;
    CDateTime* m_fecha;
    CFarmacia* m_farmacia;
    int m_cantidad;

  public:

    CVenta();
    CVenta(CMedicamento* med,int cantidad,CFarmacia* farmacia);
    ~CVenta();

	CMedicamento* getMedicamento(void) { return m_med_vendido; };
	CDateTime* getFecha(void) { return m_fecha; };
	CFarmacia* getFarmacia(void) { return m_farmacia; };
	int getCantidad(void) { return m_cantidad; };
};

#endif



