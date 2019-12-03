#include "CFarmacia.hpp"
#include "CCompra.hpp"

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
  delete m_pos;

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
            med_needed.push_back(temp_med_compra);

        }
      }


      CCompra* compra=new CCompra(this,med_needed);
      return compra;
      
};

CVenta* CFarmacia::make_venta(int id_med,int cantidad_venta){
  list<CMedFarm*>::iterator it_meds;

  for(it_meds=m_medicamentos.begin();it_meds != m_medicamentos.end();++it_meds){
    if(id_med==(*it_meds)->get_med()->get_cn()){
      CVenta* venta=new CVenta((*it_meds)->get_med(),cantidad_venta,this);

      (*it_meds)->add_cantidad(-cantidad_venta);

      return venta;
    }
  }
    return 0;
};

ostream& operator<<(std::ostream& os, CFarmacia* farmacia){
    
    os<<"ID FARMACIA:"<<farmacia->m_i_id_farmacia<<endl;
    list<CMedFarm*>::iterator it_meds;
    
    for(it_meds=farmacia->m_medicamentos.begin();it_meds != farmacia->m_medicamentos.end();++it_meds){
        os<<"       MED:"<<(*it_meds)->get_med()->get_cn()<<"  cantidad:"<<(*it_meds)->get_cantidad()<<endl;
    }
    
    return os;
}
