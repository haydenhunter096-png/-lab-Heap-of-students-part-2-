#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "date.h"
#include "address.h"
#include <string>

class Student {
  private:
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* birthDate;
    Date* gradDate;
    int creditHours;


  public:
    Student();
    ~Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
    std::string getLastName();
    std::string getFirstName();
    int getCreditHours();


}; // end class Student

#endif
