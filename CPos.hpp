#ifndef CPOS
#define CPOS

#pragma once
#include <time.h>
#include <iostream>
#include "CPos.hpp"
#include <string>
using namespace std;
using namespace std;

class CPos {
private:
	float m_f_x;
	float m_f_y;

public:
	CPos();
	CPos(float x, float y);
	~CPos();
	float get_x();
	float get_y();
	friend std::ostream& operator<<(std::ostream& os, const CPos& pos);
};
#endif