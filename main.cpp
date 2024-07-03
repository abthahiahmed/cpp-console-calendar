/* 
 * Simple C++ Calendar By Abthahi Ahmed Rifat
 * From Abthahi & Programming 
 * @IAmAbthahi
*/
#include <iostream>
#include <ctime>
using namespace std;

int getDaysInMonth(int month, int year){
	int leapFeb = 28;
	if (year % 4 == 0 || year % 400 == 0) 
		leapFeb = 29;
	const int daysInMonth[12] = {
		31, leapFeb, 31, 30, 31, 30, 
		31, 31, 30, 31, 30, 31
	};
	return daysInMonth[month];
}

int getStartDayOfMonth(int month, int year){
	struct tm date;
	date.tm_mon = month;
	date.tm_year = year - 1900;
	date.tm_mday = 1;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	date.tm_isdst = -1;
	mktime(&date);
	return date.tm_wday;
}

int main(int argc, char **argv)
{
	const char *daysInWeek[7] = {
		"Sun", "Mon", "Tue", 
		"Wed", "Thu", "Fri", 
		"Sat"
	};
	const char *monthsInYear[12] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August", 
		"September", "October", "November", "December"
	};
	
	time_t _time = time(NULL);
	struct tm date 	= *localtime(&_time);
	
	int currentDate = date.tm_mday;
	int currentYear = 1900 + date.tm_year;
	int currentMonth = date.tm_mon;
	int currentDay = date.tm_wday;
	int daysInMonth = getDaysInMonth(currentMonth, currentYear);
	int startDay = getStartDayOfMonth(currentMonth, currentYear);
	
	cout<<"\t\t";
	cout<<daysInWeek[currentDate];
	cout<<", "<<currentDate;
	cout<<" "<<monthsInYear[currentMonth];
	cout<<" "<<currentYear<<endl<<endl;
	
	for (int i = 0; i < 7; i++){
		cout<<daysInWeek[i]<<"\t";
	}
	cout<<endl<<endl;
	for (int i = 1; i <= daysInMonth + startDay; i++){
		const char *mark = ((i - startDay) == currentDate) 
			? "|" : 
			"";
		
		if (i < (startDay + 1)) cout<<""<<"\t";
		else cout<<mark<<(i - startDay)<<mark<<"\t";
		
		if (i % 7 == 0) cout<<endl<<endl;
	}
	cout<<endl<<endl;
	return 0;
}
