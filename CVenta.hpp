#ifndef CVENTA
#define CVENTA
#pragma once

#include <iostream>
#include <ctime>
#include "CMedicamento.hpp"
#include "CDateTime.hpp"

class CVenta{
  private:
    CMedicamento* m_med_vendido;
    CDateTime* m_fecha;
    int m_cantidad;

  public:

    CVenta();
    CVenta(CMedicamento* med,int cantidad);
    ~CVenta();
};

#endif