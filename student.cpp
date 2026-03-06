#include <iostream> 
#include <sstream>  

#include "student.h"    
#include "address.h"
#include "date.h"   

Student::Student(){
    firstName = "";
    lastName = "";
    address = new Address();
    birthDate = new Date();
    gradDate = new Date();
    creditHours = 0;

} // end constructor

Student::~Student(){
    delete address;
    delete birthDate;
    delete gradDate;

} // end destructor

void Student::init(std::string studentString){
    std::stringstream converter:
    // create temp strings as needed
    std:: string street;
    std:: string city;
    std:: string state;
    std:: string sBirthDate;
    std:: string sGradDate;
    std:: string sCreditHours;

    // load up string stream with input
    converter.clear();
    converter.str(studentString);

    // pull date from stringStrream CSV
    // names go straight into attributes

    getline(converter, firstName, ',');
    getline(converter, lastName, ',');

    // now pull data that is needed for address
    getline(converter, street, ',');
    getline(converter, city, ',');
    getline(converter, state, ',');
    getline(converter, zip, ',');

    // initialize address with this data
    address->init(street, city, state, zip);

    // get the dates
    getline(converter, sBirthDate, ',');
    getline(converter, sGradDate, ',');

    // use dates for initialize date classes
    birthDate->init(sBirthDate);
    gradDate->init(sGradDate);

    // grad credit hours
    getline(converter, sCreditHours, ',');

    // convert the credit hours as int
    convert.clear();
    convert.str("");
    converter << sCreditHours;
    converter >> creditHours;



} // end init

void Student::printStudent(){
    std::cout << lastName << ", " << firstName << std::endl;
    adress->printAddress();
    std::cout << "Birth date: ";
    birthDate->printDate();
    std::cout << "Grad date: ";
    gradDate->printDate();
    std::cout << "Credit Hours: " << creditHours << std::endl
    std::cout << std::endl;
}   // end printStudent

std::string Student::getLastFirst(){
    std::stringstream converter;
    converter.str("");
    converter << lastName << ", " firstName;
    return converter.str();
} // end getLastFirst

std::string Student::getFistName(){
    return lastName;
} // end getLastName

std::string Student::getFirstNamr(){
    return firstName;
} // end getFirstName

int Student::getCreditHours(){
    return creditHours;
} // end getCreditHours