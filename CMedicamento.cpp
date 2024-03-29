#include "CMedicamento.hpp"

CMedicamento::CMedicamento(void) {
	this->m_i_cn = 0;

}
CMedicamento::CMedicamento(const CMedicamento& medicamento) {
	this->m_i_cn = medicamento.m_i_cn;

}
CMedicamento::CMedicamento(float m_i_cn) {
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
}


float CMedicamento::get_cn(void) {
	return m_i_cn;
}
