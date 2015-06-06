// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate( void ){
	m_year = m_month = m_day = 0;
}

CDate::CDate( int year, int month, int day ){
	setDate( year, month, day );        
}

CDate::CDate( int year, std::string month, int day ){
    int month_int = monthStr2Num(month);
    setDate( year, month_int, day);
}

bool CDate::isValidDate( int year, int month, int day ){
    if (year < 0) {
        return false;
    }
    else if ((month < 1) || (month > 12)) {
        return false;
    }
    else if (isValidDay(year,month,day)) {
        return true;
    } else {
        return false;
    }
}

bool CDate::isValidDate( int year, std::string month, int day){
    int month_int = monthStr2Num(month);
    
    if (year < 0) {
        return false;
    }
    if ((month_int < 1) || (month_int > 12)) {
        return false;
    }
    if (isValidDay(year,month_int,day)) {
        return true;
    } else {
        return false;
    }
}

int CDate::monthStr2Num(std::string month){
    std::string jan ("January");
    std::string feb ("February");
    std::string mar ("March");
    std::string apr ("April");
    std::string may ("May");
    std::string jun ("June");
    std::string jul ("July");
    std::string aug ("August");
    std::string sep ("September");
    std::string oct ("October");
    std::string nov ("November");
    std::string dec ("December");
    
    if (month.compare(jan) == 0){
        return 1;
    }
    else if (month.compare(feb) == 0){
        return 2;
    }
    else if (month.compare(mar) == 0){
        return 3;
    }
    else if (month.compare(apr) == 0){
        return 4;
    }
    else if (month.compare(may) == 0){
        return 5;
    }
    else if (month.compare(jun) == 0){
        return 6;
    }
    else if (month.compare(jul) == 0){
        return 7;
    }
    else if (month.compare(aug) == 0){
        return 8;
    }
    else if (month.compare(sep) == 0){
        return 9;
    }
    else if (month.compare(oct) == 0){
        return 10;
    }
    else if (month.compare(nov) == 0){
        return 11;
    }
    else if (month.compare(dec) == 0){
        return 12;
    }
    else {return 0;}
}


bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
            		valid = true;
            		break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
            		if (day == 31){
                	valid = false;
            		} else {
                	valid = true;
           		 }
            		break;
		default:
            		valid = false;
			break; 
	}
	return valid;
}

void CDate::setDate( int year, int month, int day ){
	if( isValidDate( year, month, day ) ){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate( int year, std::string month, int day ){
    int month_int = monthStr2Num(month);
	if( isValidDate( year, month, day ) ){    
		m_year = year;
		m_month = month_int;
		m_day = day;
	}
	else {
		m_year = month_int = m_day = 0;
	}
}

void CDate::print( void ){
	std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
}

