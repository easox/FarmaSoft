#pragma once
#include <time.h>
#include <iostream>


class CValue
{
	private:
		double m_d_value; 
		time_t m_t_date; 
	public:
		// constructor and destructor
		CValue(){this->m_d_value=0;this->m_t_date=0; cout << "Default creation" << endl;};
		CValue(double value, time_t date){this->m_d_value=value;
																				this->m_t_date=date;
																				cout << "I have been created with value = " << m_d_value
																					<< " and date = " << m_t_date << endl;};
		CValue(const CValue & my_cval){
			*this=my_cval;
		}
		~CValue(){  cout << "Erase" << endl;};
		// functions for member access
		double getValue(){return this->m_d_value;};
		time_t getDate(){return this->m_t_date;};
		void operator=(const CValue & my_cval){this->m_d_value=my_cval.m_d_value;
																				this->m_t_date=my_cval.m_t_date;}


		void operator+=(const CValue & added_cval){ return *this+added_cval; }
		void operator+( const CValue & added_cval){
						if(this->m_t_date==added_cval.m_t_date){
							this->m_d_value+=added_cval.m_d_value;
						}
																							}

		//friend 	void operator+(CValue& my_cval, const CValue & added_cval);

		friend std::ostream& operator<<(std::ostream& os, const CValue& my_cval);
		friend std::istream & operator >> (std::istream &in,  CValue &my_cval);
		

};


