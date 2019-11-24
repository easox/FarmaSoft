#pragma once

#include <iostream>
#include <string>
#include <list>

#include "CMedicamento.hpp"

class CMed{

  private:
    int m_i_id;
    CMedicamento* m_medicamento;
    float m_f_price;
    int m_i_cantidad;
    
  public:



    CMedicamento* get_med(void){return m_medicamento;};
    float get_price(void){return m_f_price;};
    void update_price(float price){m_f_price=price;};

};