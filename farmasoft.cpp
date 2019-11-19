#include "farmasoft.hpp"
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



//Clase CMedicamento.cpp

CMedicamento::CMedicamento(void) {
	this->m_i_cn = 0;

}
CMedicamento::CMedicamento(const CMedicamento& medicamento) {
	this->m_i_cn = medicamento.m_i_cn;
	
}
CMedicamento::CMedicamento(int m_i_cn) {
	this->m_i_cn = m_i_cn;
}

ostream& operator<<(std::ostream& o, const CMedicamento& medicamento) {
	o << "(" << medicamento.m_i_cn <<")";
	return o;
}


istream& operator>>(istream& i, CMedicamento& medicamento) {
	char mensaje[20];
	i >> mensaje >> medicamento.m_i_cn >> mensaje;
	return i;
}

CMedicamento::~CMedicamento(void) {
	cout << "CMedicamento has been deleted with = " << *this << endl;
}

