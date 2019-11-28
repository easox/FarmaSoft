#ifndef CTRANSPORT
#define CTRANSPORT
#pragma once

#include <iostream>
#include <list>
#include "CDateTime.hpp"
#include "CMedicamento.hpp"
#include "CVehiculo.hpp"
#include <string>
#include "CFarmacia.hpp"
using namespace std;

class CTransport {

private:
	int m_i_idtransporte;
	CDateTime* m_fecha;
	float m_f_distancia;
	CVehiculo* m_vehiculo;
	list<CMedicamento*> m_medicamentos;
	CFarmacia* m_farmacia_origen;
	CFarmacia* m_farmacia_destino;
	int executed;

public:
	CTransport();
	CTransport(int id, CDateTime* fecha, float dist, CVehiculo* veh, list<CMedicamento*> meds, CFarmacia* origen, CFarmacia* destino);
	~CTransport(void);
	
};
#endif