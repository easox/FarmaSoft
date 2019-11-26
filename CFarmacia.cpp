#include "CFarmacia.hpp"

CFarmacia::CFarmacia(){
      m_i_id_farmacia=0;
      m_pos=NULL;
      m_medicamentos.clear();
    };

CFarmacia::CFarmacia(int id, CPos* pos,list<CMedFarm*> medicamentos){
      m_i_id_farmacia=id;
      m_pos=pos;
      m_medicamentos=medicamentos;
    };
CFarmacia::~CFarmacia(){
  free(m_pos);

  list<CMedFarm*>::iterator it;
  while(!m_medicamentos.empty()){
    it=m_medicamentos.begin();
    m_medicamentos.pop_front();
    delete *it;
  }
  
}

CCompra* CFarmacia::determine_compra(){ 
    
      
      list<CMedCompra*> med_needed;
      list<CMedFarm*>::iterator it_farm;
      list<CMedCompra*>::iterator it_meds;

      for(it_farm=this->m_medicamentos.begin();it_farm != this->m_medicamentos.end();++it_farm){
        if((*it_farm)->get_cantidad()<=(*it_farm)->get_cantidad_min()+BUFFER){

          CMedCompra* temp_med_compra=new CMedCompra((*it_farm)->get_med(),(*it_farm)->get_cantidad_max()-(*it_farm)->get_cantidad());

        }
      }


      CCompra* compra=new CCompra(this,med_needed);
      return compra;
      
};

CVenta* CFarmacia::make_venta(int id_med,int cantidad_venta){
  list<CMedFarm*>::iterator it_meds;

  for(it_meds=m_medicamentos.begin();it_meds != m_medicamentos.end();++it_meds){
    if(id_med==(*it_meds)->get_med()->get_cn()){
      CVenta* venta=new CVenta((*it_meds)->get_med(),cantidad_venta);

      (*it_meds)->add_cantidad(-cantidad_venta);

      return venta;
    }
  }
};
