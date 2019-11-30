#ifndef CMEDCOMPRA
#define CMEDCOMPRA

#pragma once
#include <iostream>
#include <string>
#include <list>

#include "CMedicamento.hpp"
#include "CProveedor.hpp"

class CMedCompra{

  private:
    CMedicamento* m_medicamento;
    CProveedor* m_proveedor;
    float m_f_price;
    int m_i_cantidad;
    
  public:
    CMedCompra(CMedicamento* med,int cantidad);
    CMedCompra();
    ~CMedCompra();

    CMedicamento* get_med(void);
    float get_price(void);
    void update_price(float price);
    void update_proveedor(CProveedor* proveedor);

};

#endif
