
#include "CDateTime.hpp"

using namespace std;

int CDateTime::getYear(){
  tm* tim=localtime(&(this->time));
  return (tim->tm_year)+1900;

}

time_t CDateTime::getTime_t(){
  return this->time;

}
int CDateTime::getMonth(){
  tm* tim=localtime(&(this->time));
  return (tim->tm_mon)+1;

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

CDateTime::CDateTime(void){
  this->time=0;
  cout<<"Standard Creation"<<endl;
};

CDateTime::CDateTime(const CDateTime& dateTime){
  this->time=dateTime.time;
};

CDateTime::CDateTime(time_t time){
  this->time=time;
};

CDateTime::CDateTime(struct tm time){
  this->time=mktime(&time);
};
CDateTime::CDateTime(int year, int month, int day, int hour, int minutes, int seconds){
  struct tm* timeinfo;
  time_t fech =0; // get the current datetime
  timeinfo = localtime(&fech);
  timeinfo->tm_mon = month; // month: January
  timeinfo->tm_mday = day; // day of the month: 9
  timeinfo->tm_year = year - 1900; // year 2015
  timeinfo->tm_hour = hour; // hour 0
  timeinfo->tm_min = minutes;
  timeinfo->tm_sec = seconds;
  this->time = mktime(timeinfo);
};

CDateTime::~CDateTime(void){};