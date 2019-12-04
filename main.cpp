

#include <iostream>
#include <time.h>
#include <fstream>
#include <list>
#include <string>
#include <ctype.h>
#include <windows.h>

#include "CFarmacia.hpp"
#include "CCompra.hpp"
#include "CProveedor.hpp"
#include "CMedFarm.hpp"
#include "CMedicamento.hpp"
#include "CMedCompra.hpp"
#include "DBManager.h"


void empty_jeringe();
void jeringe1();
void jeringe2();
void jeringe3();
void jeringe4();
void jeringe5();
void jeringe6();
void jeringe7();





void ClearScreen();

using namespace std;

int main(void){

	system("COLOR F1");

	ClearScreen();
	empty_jeringe();
	Sleep(1000);
	ClearScreen();
	jeringe1();
	Sleep(1000);
	ClearScreen();
	jeringe2();
	Sleep(1000);
	ClearScreen();
	jeringe3();
	Sleep(1000);
	ClearScreen();
	jeringe4();
	Sleep(1000);
	ClearScreen();
	jeringe5();
	Sleep(1000);
	ClearScreen();
	jeringe6();
	Sleep(1000);
	ClearScreen();
	jeringe7();



	CDBManager DBManager;
    
    list<CFarmacia*> farmacias;
    list<CFarmacia*>::iterator it_farm;
    list <CProveedor*> proveedores;
    list<CProveedor*>::iterator it_prov;
    
	farmacias = DBManager.GetListaFarmacias();
	proveedores = DBManager.GetListaProveedores();
	    
    char option;
    int exec=1;
    while(1){
		farmacias = DBManager.GetListaFarmacias();
		proveedores = DBManager.GetListaProveedores();
        if(exec){
          
            ClearScreen();
          
            //MENU OPTIONS
			jeringe7();

			cout << "  8888888888     d8888 8888888b.  888b     d888        d8888  .d8888b.   .d88888b.  8888888888 88888888888 " << endl;
			cout << "  888           d88888 888   Y88b 8888b   d8888       d88888 d88P  Y88b d88     Y88 888            888     " << endl;
			cout << "  888          d88P888 888    888 88888b.d88888      d88P888 Y88b.      888     888 888            888     " << endl;
			cout << "  8888888     d88P 888 888   d88P 888Y88888P888     d88P 888   Y888b.   888     888 8888888        888     " << endl;
			cout << "  888        d88P  888 8888888P   888 Y888P 888    d88P  888      Y88b. 888     888 888            888     " << endl;
			cout << "  888       d88P   888 888 T88b   888  Y8P  888   d88P   888        888 888     888 888            888     " << endl;
			cout << "  888      d8888888888 888  T88b  888       888  d8888888888 Y88b  d88P Y88b. .d88P 888            888     " << endl;
			cout << "  888     d88P     888 888   T88b 888       888 d88P     888   Y8888P     Y88888P   888            888     " << endl;


            cout<<"  Introduzca una opci\xa2n"<<endl;
            cout<<endl<<"  Ventas:"<<endl;
            cout<<"       1. Hacer venta"<<endl;
            cout<<"       2. Borrar \xa3ltima venta"<<endl<<endl;
            cout<<"  Compras:"<<endl;
            cout<<"       3. Optimizar compras"<<endl<<endl;
            
            
            cout<<"  Proveedores:"<<endl;
            cout<<"       4. Ver lista de proveedores"<<endl;
            cout<<"       5. Agregar nuevo proveedor"<<endl;
			cout<<"       6. Agregar nuevos medicamentos a un proveedor existente" << endl;
            cout<<"       7. Borrar proveedor"<<endl<<endl;
            
            cout<<endl<<"  Farmacia:"<<endl;
            cout<<"       8. Ver lista de farmacias"<<endl<<endl;
            cout<<endl<<"  Otras:"<<endl;
            cout<<"       Q. Terminar programa"<<endl<<endl;
            
            
            
        }
        cout<<"->";
        cin>>option;
        
        if(option=='1'){
            //Hacer venta
            ClearScreen();
            int idfarm,cantidad;
			float idmed;
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                cout<<(*it_farm);
            }
            cout<<"Escribir ID de la farmacia, ID del medicamento y cantidad vendida: "<<endl;
            cin>>idfarm>>idmed>>cantidad;
            int valid=0;
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                if((*it_farm)->get_ID()==idfarm){
                    CVenta* venta = (*it_farm)->make_venta(idmed, cantidad);
					if (venta != NULL)
					{
						valid = 1;
						DBManager.NuevaVenta(venta);
					}
                    delete venta;
                }
                
            }
            if(!valid){
              cout<<"Venta no v\xa0lida"<<endl;
            }
          
            
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='2'){
			ClearScreen();
          
			DBManager.BorrarUltimaVenta();
          
          
            cout<<"\xe9ltima venta borrada"<<endl;
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='3'){
            //optimizar compras
            ClearScreen();
            
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                
                CCompra* compra=(*it_farm)->determine_compra();
                compra->find_proveedor(proveedores);
                cout<<compra;
                
				DBManager.NuevaCompra(compra);
                
                delete compra;  //No hace free de farmacia, freed later
            }
            
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='4'){
          //ver lista de proveedores
            ClearScreen();
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                //cout<<"Proveedor: "<<(*it_prov)->get_name()<<"con ID:"<<(*it_prov)->get_id()<<endl;
				cout << (*it_prov);
            } 
            
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='5'){
            ClearScreen();
			string temp1,temp2;
			int num_meds;
			string name;
			cout << "Introduzca el nombre del nuevo proveedor: ";
			cin >> name;
			int id_prov = DBManager.NuevoProveedor(name);
			
			while (1) {
				float id, precio;
				cout << "Introduzca el CN del medicamento y a qu\x82 precio lo vende: " << endl;
				cin >> id >> precio;
				

				DBManager.InsertMedProv(id_prov, id, precio);

				
				cout << "\xa8Quiere agregar otro medicamento?(Y/N)" << endl;
				cin >> temp1;

				if (temp1 != "Y" && temp1 != "y") {
					break;
				}
			}
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
			cin >> temp2;
            if(temp2 != "Y" && temp2 != "y"){
                break;
            }
            exec=1;
		}else if (option == '6') {
			ClearScreen();
			string temp1, temp2;
			int num_meds;
			int id_prov;
			cout << "Introduzca el ID del proveedor que desea modificar: ";
			cin >> id_prov;
			
			while (1) {
				float id, precio;
				cout << "Introduzca el CN del medicamento y a qu\x82 precio lo vende: " << endl;
				cin >> id >> precio;


				DBManager.InsertMedProv(id_prov, id, precio);


				cout << "\xa8Quiere agregar otro medicamento?(Y/N)" << endl;
				cin >> temp1;

				if (temp1 != "Y" && temp1 != "y") {
					break;
				}
			}
			cout << "\xa8Quiere realizar otra acci\xa2n?(Y/N)" << endl;

			cin >> temp2;
			if (temp2 != "Y" && temp2 != "y") {
				break;
			}
			exec = 1;
		}else if (option == '7'){
            //borrar proveedor
            ClearScreen();
            int id;
			
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                cout<<"Proveedor: "<<(*it_prov)->get_name()<<" con ID:"<<(*it_prov)->get_id()<<endl;
            }
            
           
                
            cout<<"Escriba ID del proveedor a borrar: "<<endl;
            cin>>id;
            int valid=0;
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                if(id==(*it_prov)->get_id()){
					DBManager.BorrarProveedor(id);

					valid=1;
					proveedores.erase (it_prov);
					break;
                }
            }
          if(!valid){
            cout<<"Proveedor no existe"<<endl;
          }
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='8'){
          //Ver lista de farmacias
            ClearScreen();
            
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                cout<<(*it_farm);
            }
            char temp;
            cout<<"\xa8Quiere realizar otra acci\xa2n?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            
            exec=1;
        
        }else if(toupper(option)=='Q'){
          //terminar programa
            ClearScreen();
            cout<<"Fin de programa"<<endl;
            break;
        }else{
          //opcion no valida
            exec=0;
            
            cout<<"Opci\xa2n no valida, vuelva a elegir una opci\xa2n"<<endl;
        }
		//FREE PROVEEDORES
		while (!proveedores.empty()) {
			it_prov = proveedores.begin();
			delete* it_prov;
			proveedores.pop_front();
		}
		//FREE FARMACIAS
		while (!farmacias.empty()) {
			it_farm = farmacias.begin();
			delete* it_farm;
			farmacias.pop_front();
		}

    }
    

	return 0;
}


void ClearScreen(){
    cout << string( 100, '\n' );
}

void empty_jeringe() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|''''|''''|''''|''''|'**\|__" << endl;
	cout << "|- - -|  cc 6    5    4    3    2    1 *** __]==--------------" << endl;
	cout << "|-----|________________________________**/|" << endl;
	cout << "'     |                                     " << endl;
}


void jeringe1() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|''''|''''|''''|''''|***\|__" << endl;
	cout << "|- - -|  cc 6    5    4    3    2    1**** __]==--------------" << endl;
	cout << "|-----|______________________________****/|" << endl;
	cout << "'     |                                     " << endl;
}

void jeringe2() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|''''|''''|''''|****|***\|__" << endl;
	cout << "|- - -|  cc 6    5    4    3    2****1**** __]==--------------" << endl;
	cout << "|-----|__________________________********/|" << endl;
	cout << "'     |                                     " << endl;
}

void jeringe3() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|''''|''''|****|****|***\|__" << endl;
	cout << "|- - -|  cc 6    5    4    3****2****1**** __]==--------------" << endl;
	cout << "|-----|_____________________*************/|" << endl;
	cout << "'     |                                     " << endl;
}

void jeringe4() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|''''|****|****|****|***\|__" << endl;
	cout << "|- - -|  cc 6    5    4****3****2****1**** __]==--------------" << endl;
	cout << "|-----|________________******************/|" << endl;
	cout << "'     |                                     " << endl;
}

void jeringe5() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|''''|****|****|****|****|***\|__" << endl;
	cout << "|- - -|  cc 6    5****4****3****2****1**** __]==--------------" << endl;
	cout << "|-----|___________***********************/|" << endl;
	cout << "'     |                         " << endl;
}

void jeringe6() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|****|****|****|****|****|***\|__" << endl;
	cout << "|- - -|  cc 6****5****4****3****2****1**** __]==--------------" << endl;
	cout << "|-----|______****************************/|" << endl;
	cout << "'     |                                " << endl;
}
void jeringe7() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|- - -|****|****|****|****|****|***\|__" << endl;
	cout << "|- - -|  cc 6****5****4****3****2****1**** __]==--------------" << endl;
	cout << "|-----|______****************************/|" << endl;
	cout << "'     |                                     " << endl;
}


void jeringe8() {
	cout << ".     |__________________________________" << endl;
	cout << "|-----|****|****|****|****|****|****|***\|__" << endl;
	cout << "|- - -|**cc*6****5****4****3****2****1**** __]==--------------" << endl;
	cout << "|-----|*********************************/|" << endl;
	cout << "'     |                                     " << endl;
}
