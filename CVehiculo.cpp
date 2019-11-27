#include "CVehiculo.hpp"

CVehiculo::CVehiculo() {
	m_s_matricula = "0000AAA";
	m_i_capacidad = -1;
	m_p_posicion = NULL;
}

CVehiculo::CVehiculo(string matricula, int capacidad, CPos* posicion) {
	m_s_matricula = matricula;
	m_i_capacidad = capacidad;
	m_p_posicion = posicion;
}

ostream& operator<<(std::ostream& os, const CVehiculo& vehiculo) { 
	os << "(" << vehiculo.m_s_matricula << "," << vehiculo.m_i_capacidad << "," << *vehiculo.m_p_posicion << ")";
	return os;
}

CVehiculo::~CVehiculo(){
	cout << "CVehiculo has been deleted with = " << *this << endl;
}

void CVehiculo::move(const CPos&) {
	return;
}

float CVehiculo ::dist_to(const CPos& travel_to) {
	return 0;
}

CPos CVehiculo::get_pos(void) {
	return *this->m_p_posicion; 
};
int CVehiculo::get_capacidad(void) { 
	return this->m_i_capacidad; 
};
string CVehiculo::get_matricula(void) {
	return this->m_s_matricula; 
};
