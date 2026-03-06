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
}

Student::~Student(){
    delete address;
    delete birthDate;
    delete gradDate;
}

void Student::init(std::string studentString){
    std::stringstream converter;

    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string sBirthDate;
    std::string sGradDate;
    std::string sCreditHours;

    converter.clear();
    converter.str(studentString);

    getline(converter, firstName, ',');
    getline(converter, lastName, ',');

    getline(converter, street, ',');
    getline(converter, city, ',');
    getline(converter, state, ',');
    getline(converter, zip, ',');

    address->init(street, city, state, zip);

    getline(converter, sBirthDate, ',');
    getline(converter, sGradDate, ',');

    birthDate->init(sBirthDate);
    gradDate->init(sGradDate);

    getline(converter, sCreditHours, ',');

    std::stringstream convert;
    convert << sCreditHours;
    convert >> creditHours;
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();

    std::cout << "DOB: ";
    birthDate->printDate();

    std::cout << "Grad: ";
    gradDate->printDate();

    std::cout << "Credits: " << creditHours << std::endl;
    std::cout << "____________________________________" << std::endl;
}

std::string Student::getLastFirst(){
    std::stringstream converter;
    converter << lastName << ", " << firstName;
    return converter.str();
}

std::string Student::getLastName(){
    return lastName;
}

std::string Student::getFirstName(){
    return firstName;
}

int Student::getCreditHours(){
    return creditHours;
}