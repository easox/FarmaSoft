#pragma once

#include <iostream>
#include <string>
#include <list>
#include "CPos.hpp"
#include "CMedFarm.hpp"
#include "CMedCompra.hpp"

#define BUFFER 100


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
    CCompra* determine_compra(){ //returns what it needs to buy(quantity) but not from whom or at what price.
    
      
      list<CMedCompra*> med_needed;
      list<CMedFarm*>::iterator it_farm;
      list<CMedCompra*>::iterator it_meds;

      for(it_farm=this->m_medicamentos.begin();it_farm != this->m_medicamentos.end();++it_farm){
        if((*it_farm)->get_cantidad()<=(*it_farm)->get_cantidad_min()+BUFFER){
          CMedCompra* temp_med_compra=new CMedCompra((*it_farm)->get_med(),TODO:);// Define quantity asked

        }
      }


      CCompra* compra=new CCompra(this,med_needed);
      return compra;
      
    };
};