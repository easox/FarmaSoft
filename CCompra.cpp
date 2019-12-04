#include "CCompra.hpp"
#include "CFarmacia.hpp"
#include <iomanip>

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
  
  list<CMedCompra*>::iterator it;
  while(!m_meds.empty()){
    it=m_meds.begin();
    delete *it;
	m_meds.pop_front();
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
		if ((*it_meds)->get_price() != 100000.0)
		{
			o << "       Compra MED con ID:" << std::fixed << setprecision(1) << (*it_meds)->get_med()->get_cn() << endl <<
				"          Cantidad comprada:" << std::fixed << setprecision(1) << (*it_meds)->get_cantidad() << endl <<
				"          Precio: " << (*it_meds)->get_price() << endl;
		}
    }
    return o;
}
