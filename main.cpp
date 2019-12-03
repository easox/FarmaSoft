

#include <iostream>
#include <time.h>
#include <fstream>
#include <list>
#include <string>
#include <ctype.h>
#include "CFarmacia.hpp"
#include "CCompra.hpp"
#include "CProveedor.hpp"
#include "CMedFarm.hpp"
#include "CMedicamento.hpp"
#include "CMedCompra.hpp"





void ClearScreen();

using namespace std;

int main(void){
    
    
    list<CFarmacia*> farmacias;
    list<CFarmacia*>::iterator it_farm;
    list <CProveedor*> proveedores;
    list<CProveedor*>::iterator it_prov;
    
    
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
    
    
    
    char option;
    int exec=1;
    while(1){
        if(exec){
          
            ClearScreen();
          
            //MENU OPTIONS
            cout<<"Introduzca una opción"<<endl;
            cout<<endl<<"Ventas:"<<endl;
            cout<<"     1. Hacer venta"<<endl;
            cout<<"     2. Borrar última venta"<<endl<<endl;
            cout<<"Compras:"<<endl;
            cout<<"     3. Optimizar compras"<<endl<<endl;
            
            
            cout<<"Proveedores:"<<endl;
            cout<<"     4. Ver lista de proveedores"<<endl;
            cout<<"     5. Añadir nuevo proveedor"<<endl;
            cout<<"     6. Borrar proveedor"<<endl<<endl;
            
            cout<<endl<<"Farmacia:"<<endl;
            cout<<"     7. Ver lista de farmacias"<<endl<<endl;
            cout<<endl<<"Otras:"<<endl;
            cout<<"     Q. Terminar programa"<<endl<<endl;
            
            
            
        }
        cout<<"->";
        cin>>option;
        
        if(option=='1'){
            //Hacer venta
            ClearScreen();
            int idfarm,idmed,cantidad;
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                cout<<(*it_farm);
            }
            cout<<"Escribir ID de la farmacia, ID del medicamento y cantidad vendida: "<<endl;
            cin>>idfarm>>idmed>>cantidad;
            int valid=0;
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                if((*it_farm)->get_ID()==idfarm){
                    valid=1;
                    CVenta* venta = (*it_farm)->make_venta(idmed, cantidad);
                    //TODO DB: Add venta to DB, Update farmacia
                    delete venta;
                }
                
            }
            if(!valid){
              cout<<"Venta no válida"<<endl;
            }
          
            
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='2'){
            //Borrar última venta
            ClearScreen();
          
            //TODO DB: DB borrar última venta
            //TODO DB: Leer lista farmacias de nuevo
          
          
          
            cout<<"Última venta borrada"<<endl;
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
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
                
                //TODO DB: nueva compra y actualizar farmacia en base de datos
                
                delete compra;  //No hace free de farmacia, freed later
            }
            
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='4'){
          //ver lista de proveedores
            ClearScreen();
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                cout<<"Proveedor: "<<(*it_prov)->get_name()<<"con ID:"<<(*it_prov)->get_id()<<endl;
            } 
            
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='5'){
          //Añadir nuevo proveedor AUN NO HACE NADA!!!
            ClearScreen();
            
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='6'){
            //borrar proveedor
            ClearScreen();
            int id;
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                cout<<"Proveedor: "<<(*it_prov)->get_name()<<" con ID:"<<(*it_prov)->get_id()<<endl;
            }
            
           
                
            cout<<"Escribir ID del proveedor a borrar: "<<endl;
            cin>>id;
            int valid=0;
            for(it_prov=proveedores.begin();it_prov!=proveedores.end();++it_prov){
                if(id==(*it_prov)->get_id()){
                    //TODO DB: Borrar proveedor de la DB
                  valid=1;
                  proveedores.erase (it_prov);
                  break;
                }
            }
          if(!valid){
            cout<<"Proveedor no existe"<<endl;
          }
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
            cin>>temp;
            if(toupper(temp)!='Y'){
                break;
            }
            exec=1;
        }else if(option=='7'){
          //Ver lista de farmacias
            ClearScreen();
            
            for(it_farm=farmacias.begin();it_farm!=farmacias.end();++it_farm){
                cout<<(*it_farm);
            }
            char temp;
            cout<<"Quieres realizar otra acción?(Y/N)"<<endl;
            
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
            
            cout<<"Opción no valida, vuelva a elegir una opción"<<endl;
        }
    }
    
    
    //FREE PROVEEDORES
    while(!proveedores.empty()){
        it_prov=proveedores.begin();
        proveedores.pop_front();
        delete *it_prov;
    }
    //FREE FARMACIAS
    while(!farmacias.empty()){
        it_farm=farmacias.begin();
        farmacias.pop_front();
        delete *it_farm;
    }
    
    
	return 0;
}


void ClearScreen(){
    cout << string( 100, '\n' );
}
