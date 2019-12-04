#ifndef CMEDICAMENTO
#define CMEDICAMENTO
#pragma once

#include <iostream>
#include <string>
	using namespace std;

	class CMedicamento{
	private:
		float m_i_cn;
	public:
		CMedicamento(void);
		CMedicamento(const CMedicamento& medicamento);
		CMedicamento(float m_i_cn);
		~CMedicamento();

		float get_cn(void);

		friend std::ostream& operator<<(std::ostream& os, const CMedicamento& medicamento);
		friend std::istream& operator>>(std::istream& i, CMedicamento& medicamento);
	};

#endif