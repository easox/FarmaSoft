#pragma once

#include <iostream>
#include <string>
#include <list>
#include "CPos.hpp"
#include "CMedFarm.hpp"


using namespace std;

class CFarmacia{
  private:
    int m_i_id_farmacia;
    int m_i_capacidad_max;
    CPos* m_pos;
    list<CMedFarm*> m_medicamentos;

  public:
    CFarmacia(){
      m_i_id_farmacia=0;
      m_i_capacidad_max=0;
      m_pos=NULL;
      m_medicamentos.clear();
    };
    CFarmacia(int id, int capacidad, CPos* pos,list<CMedFarm*> medicamentos){
      m_i_id_farmacia=id;
      m_i_capacidad_max=capacidad;
      m_pos=pos;
      m_medicamentos=medicamentos;
    };

    ~CFarmacia(){};
    

};