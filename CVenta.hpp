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
    int m_i_id_venta; 

  public:

    CVenta();
    CVenta(int id_venta, CMedicamento* med,int cantidad,CFarmacia* farmacia);
    ~CVenta();
};

#endif



