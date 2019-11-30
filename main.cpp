

#include <iostream>
#include <time.h>
#include <fstream>
#include <list>
#include "CFarmacia.hpp"
#include "CCompra.hpp"
#include "CProveedor.hpp"
#include "CMedFarm.hpp"
#include "CMedicamento.hpp"
#include "CMedCompra.hpp"


using namespace std;

int main(void){


	//GET LIST OF ALL CFarmacias and CProveedores
	list<CFarmacia*> farmacias;
	CPos* pos1=new CPos(100,200);
	CPos* pos2=new CPos(200,300);

	list<CMedFarm*> meds1;
	list<CMedFarm*> meds2;

	CMedicamento* med_a=new CMedicamento(100);
	CMedicamento* med_b=new CMedicamento(101);
	CMedFarm* med_1a= new CMedFarm(1500,1600,3000,med_a);
	CMedFarm* med_1b= new CMedFarm(100,1900,3100,med_b);
	
	CMedFarm* med_2a= new CMedFarm(1100,1600,3000,med_a);

	meds1.push_back(med_1a);
	meds1.push_back(med_1b);

	meds2.push_back(med_2a);

	CFarmacia* farmacia1= new CFarmacia(1,pos1,meds1);
	CFarmacia* farmacia2= new CFarmacia(2,pos2,meds2);
	farmacias.push_back(farmacia1);
	farmacias.push_back(farmacia2);

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


	for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){

		CCompra* compra=(*it_farm)->determine_compra();
		compra->find_proveedor(proveedores);

		//TODO:UPDATE Farmacia, insert compra (DBManager)

		delete compra;  //tambien hace free de farmacia
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
