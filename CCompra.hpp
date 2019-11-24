#pragma once

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "CDateTime.hpp"
#include "CPos.hpp"
#include "CMedicamento.hpp"
#include "CProvedor.hpp"
#include "CMed.hpp"
#include "CFarmacia.hpp"
class CCompra {
	private:
		int m_i_id_compra;
		CDateTime* m_fecha;
		list<CMed*> m_meds;
		list<CProveedor*> proveedores;
		CFarmacia* m_farmacia;

	public:
		CCompra(){};
		CCompra(int id_compra, CFarmacia* to_farmacia,list<CMed*>) {
			
			m_i_id_compra=id_compra;
			m_farmacia=to_farmacia;
			m_meds.clear(); //limpiar la lista de meds comprados
			m_fecha=new CDateTime(time(0)); //set fecha to now



		 };
		~CCompra(){
			free(m_fecha);
			free(m_farmacia);
		}

		void find_proveedor(list<CProveedor*> global_proveedores){
			list<CMed*>::iterator it_meds;
			list<CProveedor*>::iterator it_prov;
			
			for(it_meds=m_meds.begin();it_meds != m_meds.end();++it_meds){
				for(it_prov=global_proveedores.begin();it_prov != global_proveedores.end();++it_prov){
					if((*it_prov)->med_available((*it_meds)->get_med())){
						if((*it_meds)->get_price()>(*it_prov)->get_price((*it_meds)->get_med())){

							(*it_meds)->update_price((*it_prov)->get_price((*it_meds)->get_med())); //update price
							proveedores.push_back(*it_prov); //add provedoor to list

						}else{ //SI nadie vende el medicamento
							proveedores.push_back(NULL);	
						}
						
					}


				}

			}


		int get_id(void) { return this->m_i_id_compra;}

};

