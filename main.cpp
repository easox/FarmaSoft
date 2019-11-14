

#include <iostream>
#include <time.h>
#include <fstream>
#include "CDateTime.hpp"
#include "CDateTime.cpp"
#include "CValue.cpp"
#include "CValue.hpp"

void test_CDateTime(void);
void test_CValue(void);
void test_CValue2(void);


using namespace std;

int main(void){

	//test_CValue2();
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

void test_CValue1(void){

	time_t fech = time(0); // get the current datetime
	struct tm * timeinfo; // structure to manage dates
	timeinfo = localtime(&fech);
	timeinfo->tm_mon = 0; // month: January
	timeinfo->tm_mday = 9; // day of the month: 9
	timeinfo->tm_year = 2015 - 1900; // year 2015
	timeinfo->tm_hour = 0; // hour 0
	timeinfo->tm_min = 0;
	timeinfo->tm_sec = 0;
	fech = mktime(timeinfo); // get the new date
	CValue *value =new CValue(15.5,fech);
	
	cout << "value=" << value->getValue()<< std::endl;
	delete value;
}
void test_CValue2(void){

	CValue val1;
	CDateTime mytime=CDateTime(2005,10,2,11,12,13);
	CValue val2(10,mytime.getTime_t());
	CValue val3;
	val1=val2;
	cout<<val2<<val1;
	cout<<val1;

	ofstream myfile("value.txt");
	ifstream inputFile("value.txt");

	//myfile << "value=" << val1.getValue()<< std::endl;
	myfile <<val1.getValue()<< " "<<val1.getDate();
	inputFile >> val3;
	
	cout<<val3;
	

	//modify_val2(CValue& val2);
	myfile.close();
	inputFile.close();

}

