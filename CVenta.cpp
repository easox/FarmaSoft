#include "CVenta.hpp"
#include "CFarmacia.hpp"


CVenta::CVenta(){
  m_med_vendido=NULL;
  m_fecha=new CDateTime(time(0));
  m_cantidad=0;
  

};
CVenta::CVenta(CMedicamento* med,int cantidad,CFarmacia* farmacia){
  m_med_vendido=med;
  m_fecha=new CDateTime(time(0));
  m_cantidad=cantidad;
  m_farmacia=farmacia;
};

CVenta::~CVenta(){
  delete m_fecha;

};
