#pragma once

#include <iostream>
#include <string>
#include "CMedicamento.hpp"


using namespace std;

class CMedFarm{
  private:
    int m_cantidad;
    int m_minima;
    CMedicamento* m_medicamento;

  public:
    CMedFarm(int cantida,int minima, CMedicamento* medicamento);
    int get_cantidad(void);//TODO:
    int get_cantidad_min(void);//TODO:
    CMedicamento* get_med(void);//TODO:




}