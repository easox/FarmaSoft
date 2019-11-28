#include "CMedCompra.hpp"

CMedCompra::CMedCompra(CMedicamento* med,int cantidad){
  m_medicamento=med;
  m_i_cantidad=cantidad;
  m_proveedor=NULL;
  m_f_price=100000;
};

CMedCompra::CMedCompra(){
  m_medicamento=NULL;
  m_i_cantidad=0;
  m_proveedor=NULL;
  m_f_price=100000;
};
CMedCompra::~CMedCompra(){
  //DOES NOT FREE PROVEEDOR, might need it later.
  //does not free medicamento, it belongs to each farmacia
};

CMedicamento* CMedCompra::get_med(void){
  return m_medicamento;
};

float CMedCompra::get_price(void){
  return m_f_price;
};
void CMedCompra::update_price(float price){
  m_f_price=price;
};
void CMedCompra::update_proveedor(CProveedor* proveedor){
  m_proveedor=proveedor;
};

