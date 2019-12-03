#include "CCompra.hpp"
#include "CFarmacia.hpp"
CCompra::CCompra(CFarmacia* to_farmacia) {
  m_farmacia=to_farmacia;
  m_meds.clear(); //limpiar la lista de meds comprados
  m_fecha=new CDateTime(time(0)); //set fecha to now

};

CCompra::CCompra(CFarmacia* to_farmacia,list<CMedCompra*> med_needed){
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
}


ostream& operator<<(std::ostream& o, CCompra* compra){
    
    o<<"Farmacia con ID:"<< compra->m_farmacia->get_ID()<<endl;
    
    list<CMedCompra*>::iterator it_meds;
    compra->m_meds.begin();
    
    for(it_meds=compra->m_meds.begin();it_meds != compra->m_meds.end();++it_meds){
        o<<"       Compra MED con ID:"<<(*it_meds)->get_med()->get_cn()<<endl<<
        "          Cantidad comprada:"<<(*it_meds)->get_cantidad()<<endl<<
        "          Precio: "<<(*it_meds)->get_price()<<endl;
    }
    return o;
}
