#ifndef CFARMACIA
#define CFARMACIA
#pragma once

#include <iostream>
#include <string>
#include <list>
#include "CPos.hpp"
#include "CMedFarm.hpp"
#include "CMedCompra.hpp"
#include "CCompra.hpp"
#include "CVenta.hpp"

#define BUFFER 100


using namespace std;

class CFarmacia{
  private:
    int m_i_id_farmacia;
    CPos* m_pos;
    list<CMedFarm*> m_medicamentos;

  public:
    CFarmacia();
    CFarmacia(int id, CPos* pos,list<CMedFarm*> medicamentos);
    ~CFarmacia();
    CCompra* determine_compra();//returns what it needs to buy(quantity) but not from whom or at what price.
    CVenta* make_venta(int id_med,int cantidad_venta);
};
#endif