#include <string>


#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date{
private:
    int month;
    int day;
    int year;

  public:
    Date();
    Date(std::string dateString);
    void init(std::string dateString);
    void printDate();
    std::string getDateString();
}; // end class Date




#endif