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
    CPos(float x,float y);
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

class CCompra {
private:
	int m_i_id_compra;
	list<CMedicamento*> m_medicamentos;
	CProveedor* m_proveedor;

public:
	CCompra();
	CCompra(int id_compra,list<CMedicamentos> medicamentos,CProveedor proveedor);
	~CCompra();
	int get_id(void) { return this->m_i_ID_Compra;}
	CProveedor get_proveedor(void){return *(this->m_proveedor) }
	string get_nombre_proveedor(void) { return *(this->m_proveedores).get_name();) }
	CMedicamento get_medicamento(void) { return *(this->m_medicamentos;) }
};



<<<<<<< HEAD

class CTest {

private:
	int m_prueba;


<<<<<<< HEAD
=======
class CTest{
  private:
  int hello;
>>>>>>> 2471cfc8703da46ea2d01fd569e2223530c56c29
};
=======
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


>>>>>>> 5c4d0b3016aa6353f94cb8a7669215b4b3df441f
