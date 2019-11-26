#include "CMedProv.hpp"
using namespace std;

CMedProv::CMedProv(void) {
	m_f_precio = 100000; //  Se inicializa a un valor muy alto para evitat que se venda
	m_medicamento = NULL; // Inicializao a NULL ya que no hay ningun medicamento

}
CMedProv::CMedProv(const CMedProv& medprov) {
	m_f_precio = medprov.m_f_precio;
	m_medicamento = medprov.m_medicamento;
}
CMedProv::CMedProv(CMedicamento* medicamento, float precio) {
	m_f_precio = precio;
	m_medicamento = medicamento;
}

ostream& operator<<(std::ostream& os, const CMedProv& medprov) {
	os << "(" << medprov.m_f_precio << "," << *medprov.m_medicamento << ")";
	return os;
}
//istream& operator>>(std::istream& i, CMedProv& medprov) {
	//char mensaje[20];
	//i >> mensaje >> medprov.m_f_precio >> mensaje >> medprov.m_medicamento >> mensaje;
	//return i;
//}

CMedProv::~CMedProv(void) {
	cout << "CMedProv has been deleted with = " << *this << endl;
}

float CMedProv::get_price() {
	float precio = 100000;
	precio = this->m_f_precio;
	return precio;
}
int CMedProv::get_existencia() {
	int existencia = 0;
	if (this->m_medicamento != NULL) {
		existencia = 1;
	}
	return existencia;
}
