

#include <iostream>
#include <time.h>
#include <fstream>
#include <list>
#include "CFarmacia.hpp"
#include "CCompra.hpp"
#include "CProveedor.hpp"

using namespace std;

int main(void){


	//GET LIST OF ALL CFarmacias and CProveedores
	list<CFarmacia*> farmacias;
	list <CProveedor*> proveedores;


	list<CFarmacia*>::iterator it_farm;

	//MAKE SALES OF THE DAY

	for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
		int id;
		int cantidad;
		cout<<"Escribir ID del medicamento y cantidad vendida:"<<endl;
		cin>>id>>cantidad;
		if(id==0){
			break;
		}
		(*it_farm)->make_venta(id,cantidad);
	}

	//FOR EVERY FARMACIA,SEE WHAT MEDS IT NEEDS, 
	//MAKE COMPRA TO PROVEEDORES , UPDATE DATA BASE AND FREE Compra
	list<CFarmacia*>::iterator it_farm;

	for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){

		CCompra* compra=(*it_farm)->determine_compra();
		compra->find_proveedor(proveedores);

		//TODO:UPDATE Farmacia, insert compra (DBManager)

		free(compra);  //tambien hace free de farmacia
	}


	//BORRAR PROVEEDOR IF YOU LOSE CONTACT

	//FREE PROVEEDORES
	list<CProveedor*>::iterator it_prov;
	while(!proveedores.empty()){
    it_prov=proveedores.begin();
    proveedores.pop_front();
    delete *it_prov;
  }
	
	return 0;
}
