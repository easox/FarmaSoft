#pragma once

#include <iostream>
#include <string>
using namespace std;

class CMedicamento
{
private:
	int m_i_cn;
public:
	CMedicamento(void);
	CMedicamento(const CMedicamento& medicamento);
	CMedicamento(int m_i_cn);

	friend std::ostream& operator<<(std::ostream& os, const CMedicamento& medicamento);
	friend std::istream& operator>>(std::istream& i, CMedicamento& medicamento);

	~CMedicamento(void);

};

