#pragma once
#include <time.h>
#include <iostream>
#include "CDateTime.hpp"
#include <string>
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
      int m_i_idtransporte;
      CDateTime m_dt_fecha;
      float m_f_distancia;

    public:
      CTransport(){
                m_i_idtransporte=0;
                m_dt_fecha=0;
                m_f_distancia=0;
      };
      CTransport(int id,CDateTime fecha, float dist){
                m_i_idtransporte=id;
                m_dt_fecha=fecha;
                m_f_distancia=dist;
      };
      ~CTransport(){};
            


};





//Clase CProveedor
//CProveedor.h



class CProveedor
{
private:
	int m_i_id_proveedor;
	std::string m_s_nombre;
public:
	CProveedor(void);
	CProveedor(const CProveedor& proveedor);
	CProveedor(int m_i_id_proveedor,std::string m_s_nombre);
	
	friend std::ostream& operator<<(std::ostream& os, const CProveedor& dateTime);
	friend std::istream& operator>>(std::istream& i, CProveedor& proveedor);

	~CProveedor(void);
};


