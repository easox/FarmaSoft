#pragma once
#include <iostream>
#include <time.h>

using namespace std;
class CDateTime
{
private:
	time_t time; 
public:
	CDateTime(void);
	CDateTime(const CDateTime& dateTime);
	CDateTime(time_t time);
	CDateTime(struct tm time);
	CDateTime(int year, int month, int day, int hour, int minutes, int seconds);
	~CDateTime();
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
	// void operator=(CDateTime dateTime){this->time=dateTime.time;
	// 																		cout<<"operator="<<endl;};
	
	friend std::ostream& operator<<(std::ostream& os, const CDateTime& dateTime);
};
