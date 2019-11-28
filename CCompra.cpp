#include "CCompra.hpp"
CCompra::CCompra(int id_compra, CFarmacia* to_farmacia,list<CMedCompra*>) {
			
  m_i_id_compra=id_compra;
  m_farmacia=to_farmacia;
  m_meds.clear(); //limpiar la lista de meds comprados
  m_fecha=new CDateTime(time(0)); //set fecha to now

};

CCompra::CCompra(CFarmacia* to_farmacia,list<CMedCompra*> med_needed){
  m_i_id_compra=0;
  m_farmacia=to_farmacia;
  m_meds=med_needed;
  m_fecha=new CDateTime(time(0)); //set fecha to now
}

CCompra::~CCompra(){
  delete m_fecha;
  delete m_farmacia;

  list<CMedCompra*>::iterator it;
  while(!m_meds.empty()){
    it=m_meds.begin();
    m_meds.pop_front();
    delete *it;
  }
}

void CCompra::find_proveedor(list<CProveedor*> global_proveedores){
  list<CMedCompra*>::iterator it_meds;
  list<CProveedor*>::iterator it_prov;
  
  for(it_meds=m_meds.begin();it_meds != m_meds.end();++it_meds){
    for(it_prov=global_proveedores.begin();it_prov != global_proveedores.end();++it_prov){
      if((*it_prov)->med_available((*it_meds)->get_med())){
        if((*it_meds)->get_price()>(*it_prov)->get_price((*it_meds)->get_med())){

          (*it_meds)->update_price((*it_prov)->get_price((*it_meds)->get_med())); //update price
          (*it_meds)->update_proveedor(*it_prov);//update proveedor
          
        }else{
          //TODO: If no one has it
        }
        
      }
    }
  }
  //TODO: update farmacy
}

int CCompra::get_id(void) { 
  return this->m_i_id_compra;
}