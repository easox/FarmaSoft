



#include <time.h>


class CValue
{
	private:
		double m_d_value; 
		time_t m_t_date; 
	public:
		// constructor and destructor
		CValue();
		CValue(double value, time_t date);
		~CValue();
		// functions for member access
		double getValue();
		char* getDate();
};


