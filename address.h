#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string>

class Address{
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
public:
    Address();
    Address(std::string street,
            std::string city,
            std::string state,
            std::string zip);
    void init(std::string street,
              std::string city,
              std::string state,
              std::string zip);
    void printAddress();
    std::string getAddressString();
}; // end class Address

#endif