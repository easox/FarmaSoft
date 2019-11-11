
#include "CDateTime.hpp"
#include <time.h>

int CDateTime::getYear(){
  tm* tim=localtime(&(this->time));
  return tim->tm_year;

}

time_t CDateTime::getTime_t(){
  return this->time;

}
int CDateTime::getMonth(){
  tm* tim=localtime(&(this->time));
  return tim->tm_mon;

}
int CDateTime::getDay(){
  tm* tim=localtime(&(this->time));
  return tim->tm_mday;
}
int CDateTime::getHour(){
  tm* tim=localtime(&(this->time));
  return tim->tm_hour;

}
int CDateTime::getMinutes(){
  tm* tim=localtime(&(this->time));
  return tim->tm_min;

}
int CDateTime::getSeconds(){
  tm* tim=localtime(&(this->time));
  return tim->tm_sec;

}

void CDateTime::operator +(CDateTime dateTime){
  this->time+=dateTime.getTime_t();
}
void operator -(CDateTime dateTime){

}
std::ostream& operator<<(std::ostream& os, const CDateTime& dateTime){
  tm *gmtm = gmtime(&(dateTime.time));
  char * dt = asctime(gmtm);
  os << dt;
  return os;
}