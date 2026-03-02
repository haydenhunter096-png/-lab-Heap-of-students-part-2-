#include <iostream>
#include <sstream>
#include "date.h"

Date::Date(){
  month = 1;
  day = 1;
  year = 2000;
} // end default constructor

void Date::init(std::string dateString){
    // dateString is in the format "MM/DD/YYYY"

    // make a stringstream
    std::stringstream converter;
    std:: string sMonth;
    std:: string sDay;
    std:: string sYear;

    // seperate to temp strings
    converter.str(dateString);
    getline(converter, sMonth, '/');
    getline(converter, sDay, '/');
    getline(converter, sYear);

    // convert to ints

    converter.clear();
    converter.str("");

    converter << sMonth << " " << sDay << " " << sYear;
    converter >> month >> day >> year;

} // end init

void Date::printDate(){
  std::string monthString[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };

  std::cout << monthString[month - 1] << " " 
            << day << ", " 
            << year << std::endl;
} // end printDate
