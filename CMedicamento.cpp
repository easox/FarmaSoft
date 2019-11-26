#include "CMedicamento.h"

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
	o << "(" << medicamento.m_i_cn << ")";
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
