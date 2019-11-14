#pragma once
#include <time.h>
#include <iostream>
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
    CVehiculo(string matriculas,int capacidad, CPos posicion);
    ~CVehiculo(){};

};


class CPos{
  private:
    float x;
    float y;
 
  public:
    CPos();
    CPos(float x,float y);
    ~CPos();

    


};

class CTransport