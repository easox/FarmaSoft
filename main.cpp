

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

    list<CFarmacia*> farmacias;
    list <CProveedor*> proveedores;
    
    //TODO:GET LIST OF ALL CFarmacias and CProveedores
	
    
    //comment out later
	CPos* pos1=new CPos(100,200);
	CPos* pos2=new CPos(200,300);

	list<CMedFarm*> meds1;
	list<CMedFarm*> meds2;

	CMedicamento* med_a=new CMedicamento(100);
    CMedicamento* med_a_=new CMedicamento(100);
	CMedicamento* med_b=new CMedicamento(101);
    CMedicamento* med_ap=new CMedicamento(100);
    CMedicamento* med_ap_=new CMedicamento(100);
    CMedicamento* med_bp=new CMedicamento(101);
    
	CMedFarm* med_1a= new CMedFarm(1500,1600,3000,med_a);
	CMedFarm* med_1b= new CMedFarm(100,1900,3100,med_b);
	CMedFarm* med_2a= new CMedFarm(1100,1600,3000,med_a_);

	meds1.push_back(med_1a);
	meds1.push_back(med_1b);

	meds2.push_back(med_2a);

	CFarmacia* farmacia1= new CFarmacia(1,pos1,meds1);
	CFarmacia* farmacia2= new CFarmacia(2,pos2,meds2);
	farmacias.push_back(farmacia1);
	farmacias.push_back(farmacia2);
    
    
    
    
    CMedProv* medprov_1a=new CMedProv(med_ap,23.5);
    CMedProv* medprov_1b=new CMedProv(med_bp,2.55);
    
    CMedProv* medprov_2a=new CMedProv(med_ap_,12.5);
    
    list <CMedProv*> medsprov1;
    list <CMedProv*> medsprov2;
    
    medsprov1.push_back(medprov_1a);
    medsprov1.push_back(medprov_1b);
    medsprov2.push_back(medprov_2a);
    
    CProveedor* proveedor1=new CProveedor(501,"PROV1",medsprov1);
    CProveedor* proveedor2=new CProveedor(502,"PROV2",medsprov2);
    
    proveedores.push_back(proveedor1);
    proveedores.push_back(proveedor2);
    //end of comment out zone
	


	

	//MAKE SALES OF THE DAY
    list<CFarmacia*>::iterator it_farm;
	for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
		int id;
        char ans;
		int cantidad;
        cout<<(*it_farm);
        while(1){
            cout<<"Quieres hacer una venta?(Y/N)"<<endl;
            cin>>ans;
            if(ans!='Y'){
                break;
            }
        
            cout<<"Escribir ID del medicamento y cantidad vendida:"<<endl;
            cin>> id >> cantidad;
            CVenta* venta= (*it_farm)->make_venta(id,cantidad);
            delete venta;
            
            
            //TODO: ADD VENTA TO DATA BASE AND UPDATE MED_FARMACIA
        }
	}



	for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){

		CCompra* compra=(*it_farm)->determine_compra();
		compra->find_proveedor(proveedores);
        cout<<compra;

		//TODO:UPDATE Farmacia, insert compra (DBManager)

		delete compra;  //tambien hace free de farmacia
	}


	
    
    list<CProveedor*>::iterator it_prov;
    
    //free proveedores and BORRAR PROVEEDOR IF YOU LOSE CONTACT
	while(!proveedores.empty()){
        char ans;
        it_prov=proveedores.begin();
        cout<<"Proveedor: "<<(*it_prov)->get_name()<<endl;
        cout<<"Has perdido contacto con este proveedor?(Y/N)"<<endl;
        cin>>ans;
        if(ans!='Y'){
            //TODO: Delete proveedor from DB
        }
        proveedores.pop_front();
        delete *it_prov;
  }

	return 0;
}
