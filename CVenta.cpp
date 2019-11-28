#include "CVenta.hpp"


CVenta::CVenta(){
  m_med_vendido=NULL;
  m_fecha=new CDateTime(time(0));
  m_cantidad=0;
  

};
CVenta::CVenta(CMedicamento* med,int cantidad){
  m_med_vendido=med;
  m_fecha=new CDateTime(time(0));
  m_cantidad=cantidad;
};

CVenta::~CVenta(){
  delete m_med_vendido;
  delete m_fecha;

};