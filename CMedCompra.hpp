#pragma once

#include <iostream>
#include <string>
#include <list>

#include "CMedicamento.hpp"
#include "CProvedor.hpp"

class CMedCompra{

  private:
    CMedicamento* m_medicamento;
    CProveedor* m_proveedor;
    float m_f_price;
    int m_i_cantidad;
    
  public:
    CMedCompra(CMedicamento* med,int cantidad){
      m_medicamento=med;
      m_i_cantidad=cantidad;
      m_proveedor=NULL;
      m_f_price=100000;
    };
    CMedicamento* get_med(void){return m_medicamento;};
    float get_price(void){return m_f_price;};
    void update_price(float price){m_f_price=price;};
    void update_proveedor(CProveedor* proveedor){m_proveedor=proveedor;};

};