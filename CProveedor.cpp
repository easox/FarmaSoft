#include "CProveedor.hpp"
using namespace std;

//Clase CProveedor.cpp

CProveedor::CProveedor(const CProveedor& proveedor) {
	this->m_i_id_proveedor = proveedor.m_i_id_proveedor;
	this->m_s_nombre = proveedor.m_s_nombre;
	this->m_listmed.clear();
}
CProveedor::CProveedor(int m_i_id_proveedor, string m_s_nombre, list <CMedProv*> l_medprov) {
	this->m_i_id_proveedor = m_i_id_proveedor;
	this->m_s_nombre = m_s_nombre;
	this->m_listmed = l_medprov;
}


ostream& operator<<(std::ostream& o, CProveedor* proveedor) {
    o << "Proveedor: "<<proveedor->get_name();
	return o;
}


istream& operator>>(istream& i, CProveedor& proveedor) {
	char mensaje[20];
	i >> mensaje >> proveedor.m_i_id_proveedor >> mensaje >> proveedor.m_s_nombre >> mensaje;
	return i;
}

CProveedor::~CProveedor() {
	list<CMedProv*>::iterator it;
	
  while(!m_listmed.empty()){
    it=m_listmed.begin();
    m_listmed.pop_front();
    delete *it;
  }

};

float CProveedor::get_price(CMedicamento* med) {
	list<CMedProv*> ::iterator i;
	float price = 100000;
	for (i = m_listmed.begin() ; i != m_listmed.end(); ++i){
	if ((*i)->get_medicamento()->get_cn() == med->get_cn()) {
		price = (*i)->get_price();
		break;
	}
}
	return price;
}
int CProveedor::med_available(CMedicamento* med) {
	
	list<CMedProv*> ::iterator i;
	int available = 0;
	for (i = m_listmed.begin(); i != m_listmed.end(); ++i) {
		if ((*i)->get_medicamento()->get_cn() == med->get_cn()) {
			available = 1;
			break;
		}
	}
	return available;
}

string CProveedor::get_name(){
    
    return this->m_s_nombre;
}

int CProveedor::get_id(){
    return this->m_i_id_proveedor;
}
