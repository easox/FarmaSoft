#pragma once
#include <iostream>
#include <time.h>

using namespace std;
class CDateTime
{
private:
	time_t time; 
public:
	CDateTime(void){this->time=0;
            cout<<"Standard Creation"<<endl;};
	CDateTime(const CDateTime& dateTime){this->time=dateTime.time;};
	CDateTime(time_t time){this->time=time;};
	CDateTime(struct tm time){this->time=mktime(&time);};
	CDateTime(int year, int month, int day, int hour, int minutes, int seconds){
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
	//constructor con timestamp??
  time_t getTime_t();
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinutes();
	int getSeconds();

	void operator +(CDateTime dateTime);
	void operator -(CDateTime dateTime);
	void operator=(CDateTime dateTime){this->time=dateTime.time;
																			cout<<"operator="<<endl;};
	friend std::ostream& operator<<(std::ostream& os, const CDateTime& dateTime);

	~CDateTime(void){cout<<"Time destroyed"<<endl;};
};
