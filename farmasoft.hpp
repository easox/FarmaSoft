#pragma once
#include <time.h>
#include <iostream>
#include "CDateTime.hpp"
using namespace std;

class CVehiculo{

  private:
    string m_s_matricula;
    int m_i_capacidad;
    CPos* m_p_posicion;
  public:
    //move position
    void move(const CPos &);
    //Function that calculates distance from where you are to travel to

    float dist_to(const CPos& travel_to);
    CPos get_pos(void){return *(this->m_p_posicion);};
    int get_capacidad(void){return this->m_i_capacidad;};
    string get_matricula(void){return this->m_s_matricula;};

    CVehiculo();
    CVehiculo(string matricula,int capacidad, CPos posicion);
    ~CVehiculo(){};

};


class CPos{
  private:
    float m_f_x;
    float m_f_y;
 
  public:
    CPos();
    CPos(float m_f_x,float m_f_y);
    ~CPos();
    float get_x();
    float get_y();
};

class CTransport{

    private:
      int m_i_id_transporte;
      CDateTime m_f_fecha;
      float m_f_distancia;
    public:

      


};





<<<<<<< HEAD

class CTest {

private:
	int m_prueba;


=======
class CTest{
  private:
  int hello;
>>>>>>> 2471cfc8703da46ea2d01fd569e2223530c56c29
};