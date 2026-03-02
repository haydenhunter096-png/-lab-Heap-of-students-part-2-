#include "address.h"
#include <iostream>

Address::Address(){
    street = "";
    city = "";
    state = "";
    zip = "";
} // end default

Address::Address(std::string street,
                 std::string city,
                 std::string state,
                 std::string zip){
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
} // end

void Address::init(std::string street,
                   std::string city,
                   std::string state,
                   std::string zip){
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
} // init end

void Address::printAddress(){
    std::cout << street << std::endl
              << city << ", " << state << " " << zip << std::endl;
} // end print

std::string Address::getAddressString(){
    return street + "\n" + city + ", " + state + " " + zip;
} // end String