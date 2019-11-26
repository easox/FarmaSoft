#include "CProveedor.hpp"
using namespace std;

//Clase CProveedor.cpp

CProveedor::CProveedor(void) {
	this->m_i_id_proveedor = 0;
	this->m_s_nombre = "Miguel";


}
CProveedor::CProveedor(const CProveedor& proveedor) {
	this->m_i_id_proveedor = proveedor.m_i_id_proveedor;
	this->m_s_nombre = proveedor.m_s_nombre;
}
CProveedor::CProveedor(int m_i_id_proveedor, string m_s_nombre) {
	this->m_i_id_proveedor = m_i_id_proveedor;
	this->m_s_nombre = m_s_nombre;
}

ostream& operator<<(std::ostream& o, const CProveedor& proveedor) {
	o << "(" << proveedor.m_i_id_proveedor << "," << proveedor.m_s_nombre << ")";
	return o;
}


istream& operator>>(istream& i, CProveedor& proveedor) {
	char mensaje[20];
	i >> mensaje >> proveedor.m_i_id_proveedor >> mensaje >> proveedor.m_s_nombre >> mensaje;
	return i;
}

CProveedor::~CProveedor(void) {
	cout << "CProveedor has been deleted with = " << *this << endl;
}

float CProveedor::get_price(CMedicamento* med) {
	list<CMedProv*> ::iterator i;
	float price = 100000;
	for (i = m_listmed.begin() ; i != m_listmed.end(); ++i){
	if ((*i)->get_medicamento()->get_cn() == med->get_cn) {
		price = (*i)->get_price;
		break;
	}
}
	return price;
}
int CProveedor::med_available(CMedicamento* med) {
	
	list<CMedProv*> ::iterator i;
	int available = 0;
	for (i = m_listmed.begin(); i != m_listmed.end(); ++i) {
		if ((*i)->get_medicamento()->get_cn() == med->get_cn) {
			available = 1;
			break;
		}
	}
	return available;
}
