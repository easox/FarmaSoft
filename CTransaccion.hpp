#pragma once

#include <iostream>
#include <string>
#include <list>

#include "CMedicamento.hpp"
#include "CDateTime.hpp"

using namespace std;


class CTransaccion{
  protected:
    int m_i_id;
    list<CMed*> m_medicamentos;
    CDateTime* fecha;

  public:
    void add_medicamento(CMedicamento* nuevo_med);
    virtual void make_transac(void)=0;
    CTransaccion(){m_i_id=NULL; m_medicamentos.clear();};
    CTransaccion(int id, list<CMed*> medicamento){m_i_id=id;m_medicamentos=medicamento;};
    ~CTransaccion(){
      list<CMed*>::iterator it;
 
      while(!m_medicamentos.empty()){
          it=m_medicamentos.begin();
          delete *it;
      }
    };

    
};


class CMed{

  private:
    int m_i_id;
    CMedicamento* m_medicamento;
    float m_f_price;
    int m_i_cantidad;
    
    
  public:

};

class CVenta: public CTransaccion{

  public:
    using CTransaccion::CTransaccion;
    void make_transac(void);
    



};

class CCompra: public CTransaccion{
  public:
    using CTransaccion::CTransaccion;
    void make_transac(void);

}