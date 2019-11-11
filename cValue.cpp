#include "CValue.hpp"
#include <iostream>

using namespace std;

// ---------- constructors
CValue::CValue() {
	this->m_d_value = 0; this->m_t_date = 0;
	cout << "Default creation" << endl;
}
CValue::CValue(double value, time_t date) {
	m_d_value = value;
	m_t_date = date;
	cout << "I have been created with value = " << m_d_value
		<< " and date = " << m_t_date << endl;
}

double CValue::getValue() {
	return m_d_value;
}
char* CValue::getDate() {
	return ctime(&m_t_date);
}

CValue::~CValue() {
  cout << "Erase" << endl;
	
}