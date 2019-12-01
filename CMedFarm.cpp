#include "CMedFarm.hpp"

CMedFarm::CMedFarm(void) {
	m_i_cantidad = -1;
	m_i_cantidad_min = -1;
	m_i_cantidad_max = -1;
	m_medicamento = NULL;
}
CMedFarm::CMedFarm(int cantidad, int cantidad_min, int cantidad_max, CMedicamento* medicamento) {
	m_i_cantidad = cantidad;
	m_i_cantidad_min = cantidad_min;
	m_i_cantidad_max = cantidad_max;
	m_medicamento = medicamento;
}
int CMedFarm::get_cantidad(void) {
	int cantidad = -1;
	cantidad = this->m_i_cantidad;
	return cantidad;
}
int CMedFarm::get_cantidad_min(void) {
	int cantidad_min = -1;
	cantidad_min = this->m_i_cantidad_min;
	return cantidad_min;
}
int CMedFarm::get_cantidad_max(void) {
	int cantidad_max = -1;
	cantidad_max = this->m_i_cantidad_max;
	return cantidad_max;
}

CMedicamento* CMedFarm::CMedFarm::get_med(void) {
	return this->m_medicamento;
}

ostream& operator<<(std::ostream& os, const CMedFarm& medfarm) {
	os << "(" << medfarm.m_i_cantidad << "," << medfarm.m_i_cantidad_min << "," << medfarm.m_i_cantidad_max<<"," << *medfarm.m_medicamento<< ")";
	return os;
}

CMedFarm::~CMedFarm() {
    delete m_medicamento;
}


void CMedFarm::add_cantidad(int cantidad){
	m_i_cantidad+=cantidad;
}
