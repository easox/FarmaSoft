#pragma once

#include <iostream>
#include <string>
#include "CMedicamento.hpp"


using namespace std;

class CMedFarm {
private:
	int m_i_cantidad;
	int m_i_cantidad_min;
	int m_i_cantidad_max;
	CMedicamento* m_medicamento;

public:
	CMedFarm(int cantidad, int cantidad_min, int cantidad_max, CMedicamento* medicamento);
	CMedFarm(void);
	int get_cantidad(void);
	int get_cantidad_min(void);
	int get_cantidad_max(void);
	CMedicamento* get_med(void);

	friend std::ostream& operator<<(std::ostream& os, const CMedFarm& medfarm);


	~CMedFarm(void);



};
