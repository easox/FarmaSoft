#pragma once
#include <iostream>
#include <string>
#include "CMedicamento.h"

class CMedProv
{
private:
	float m_f_precio;
	CMedicamento* m_medicamento;
public:
	CMedProv(void);
	CMedProv(const CMedProv& medprov);
	CMedProv(CMedicamento* medicamento, float precio);

	friend std::ostream& operator<<(std::ostream& os, const CMedProv& medprov);
	//friend std::istream& operator>>(std::istream& i, CMedProv& medprov);

	float get_price();
	int get_existencia();
	~CMedProv(void);

	
};
