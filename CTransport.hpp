
#pragma once
#include <iostream>
#include <list>
#include "CDateTime.hpp"
#include "CMedicamento.hpp"
#include <string>
#include "CFarmacia.hpp"
using namespace std;

class CTransport{

    private:
      int m_i_idtransporte;
      CDateTime m_fecha;
      float m_f_distancia;
      CVehiculo * m_vehiculo;
      list<CMedicamento*> m_medicamentos;
      CFarmacia* m_farmacia_origen;
      CFarmacia* m_farmacia_destino;
      int executed;

    public:
      CTransport(){
                m_i_idtransporte=0;
                m_fecha=0;
                m_f_distancia=0;
                m_medicamentos.clear();
                m_farmacia_origen=NULL;
                m_farmacia_destino=NULL;
                executed=0;
      };
      CTransport(int id,CDateTime fecha, float dist, CVehiculo* veh,list<CMedicamento*> meds,CFarmacia* origen,CFarmacia* destino){
                m_i_idtransporte=id;
                m_fecha=fecha;
                m_f_distancia=dist;
                m_vehiculo=veh;
                m_medicamentos=meds;
                m_farmacia_origen=origen;
                m_farmacia_destino=destino;
                executed=0;
      };
      ~CTransport(){};
      int exec_transport(void);
            
};