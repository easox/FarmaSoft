

#include <iostream>
#include <time.h>
#include <fstream>
#include "header.hpp"


using namespace std;

int main(void){

	int id= 10;
	CDateTime* my_time = new CDateTime();
	float distance;
	list<CMedicamento*> my_list;
	CMedicamento* p_med=new CMedicamento();
	CMedicamento* p_med2=new CMedicamento();
	CVehiculo* veh=new CVehiculo();
	CFarmacia* dest= new CFarmacia();
	CFarmacia* origen= new CFarmacia();
	my_list.push_back(p_med);
	my_list.push_back(p_med2);

	CTransport* pTrans= new CTransport(id,my_time,10,veh,my_list,origen,dest);
	
	delete pTrans;


	return 0;
}
