
#include "CValue.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& os, const CValue& my_cval){
  tm *gmtm = gmtime(&(my_cval.m_t_date));
  char * dt = asctime(gmtm);

  os <<"Value: "<<my_cval.m_d_value<<" Date: "<< dt;
  return os;
}

std::istream & operator >> (std::istream &in,  CValue &my_cval){
    in >> my_cval.m_d_value>>my_cval.m_t_date;

    return in;
}
	// void operator+( CValue & my_cval,const CValue & added_cval){
	// 					if(my_cval.getDate()==added_cval.getDate()){
	// 					my_cval.getValue()+=added_cval.getValue();
	// 					}
	// 																						}
