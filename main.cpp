

#include <iostream>
#include <time.h>
#include "cValue.hpp"
#include "CDateTime.hpp"
#include "CDateTime.cpp"

void test_CDateTime(void);
using namespace std;

int main(void){

	test_CDateTime();


	return 0;
}


void test_CDateTime(void){

	CDateTime mytime=CDateTime(2005,10,2,11,12,13);
	CDateTime time=CDateTime(mytime);
	CDateTime time_default;
	CDateTime time_t_time=CDateTime(mytime.getTime_t());

	struct tm* timeinfo;
	time_t fech =0;
	timeinfo = localtime(&fech);
	timeinfo->tm_mon = 10; // month: January
	timeinfo->tm_mday = 2; // day of the month: 9
	timeinfo->tm_year = 2005 - 1900; // year 2015
	timeinfo->tm_hour = 11; // hour 0
	timeinfo->tm_min = 12;
	timeinfo->tm_sec = 13;
	
	CDateTime time_tm=CDateTime(*timeinfo);

	cout<<mytime;
	cout<<time;
	cout<<time_t_time;
	cout<<time_tm;
	cout<<time_default;

}