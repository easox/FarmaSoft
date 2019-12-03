

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
#include "DBManager.h"


using namespace std;

int main(void){

	CDBManager DBManager;

    list<CFarmacia*> farmacias;
    list<CProveedor*> proveedores;
    
    farmacias = DBManager.GetListaFarmacias();
	proveedores = DBManager.GetListaProveedores();	

	//DBManager.BorrarFarmacia(5);

	//MAKE SALES OF THE DAY
    list<CFarmacia*>::iterator it_farm;
	for(it_farm=farmacias.begin();it_farm!=farmacias.end();it_farm++){
		//int id;
  //      char ans;
		//int cantidad;
        cout<<(*it_farm) << endl;
   //     while(1){
   //         cout<<"Quieres hacer una venta?(Y/N)"<<endl;
   //         cin>>ans;
   //         if(ans!='Y'){
   //             break;
   //         }
			//
			//cout << "Escribir ID del medicamento y cantidad vendida:" << endl;
			//cin >> id >> cantidad;
			//CVenta* venta = (*it_farm)->make_venta(id, cantidad);

			//DBManager.NuevaVenta(venta);

			//delete venta;

   //         
   //         //TODO: ADD VENTA TO DATA BASE AND UPDATE MED_FARMACIA
   //     }
	}

	list<CProveedor*>::iterator it_prov;
	for (it_prov = proveedores.begin(); it_prov != proveedores.end(); ++it_prov) {

		cout << (*it_prov);
	}

	//for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){

	//	CCompra* compra=(*it_farm)->determine_compra();
	//	compra->find_proveedor(proveedores);
 //       cout<<compra;

	//	//TODO:UPDATE Farmacia, insert compra (DBManager)

	//	delete compra;  //tambien hace free de farmacia
	//}


	
    
 //   list<CProveedor*>::iterator it_prov;
	//for (it_prov = proveedores.begin(); it_prov != proveedores.end(); ++it_prov) {

	//	cout << (*it_prov);
	//}
    //free proveedores and BORRAR PROVEEDOR IF YOU LOSE CONTACT
	//while(!proveedores.empty()){
 //       char ans;
 //       it_prov=proveedores.begin();
 //       cout<<"Proveedor: "<<(*it_prov)->get_name()<<endl;
 //       cout<<"Has perdido contacto con este proveedor?(Y/N)"<<endl;
 //       cin>>ans;
 //       if(ans!='Y'){
 //           //TODO: Delete proveedor from DB
 //       }
 //       proveedores.pop_front();
 //       delete *it_prov;
	// }

	return 0;
}
