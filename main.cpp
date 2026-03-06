#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();

int main(){

  std::cout << "Hello!" << std::endl;

  testAddress();
  testDate();
  testStudent();

  std::vector<Student*> students;

  loadStudents(students);

  std::string choice;

  do{

    choice = menu();

    if(choice == "1")
      showStudentNames(students);

    else if(choice == "2")
      printStudents(students);

    else if(choice == "3")
      findStudent(students);

  }while(choice != "0");

  delStudents(students);

  return 0;

} // end main


std::string menu(){

  std::string choice;

  std::cout << std::endl;
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;
  std::cout << std::endl;

  std::cout << "please choose 0-3: ";
  std::cin >> choice;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline

  return choice;

} // end menu


void loadStudents(std::vector<Student*>& students){

  std::ifstream inFile("students.csv");
  if(!inFile){
      std::cerr << "Error: Could not open students.csv\n";
      return;
  }

  std::string currentLine;
  while(getline(inFile, currentLine)){
    if(currentLine.empty()) continue; // skip empty lines
    Student* s = new Student();
    s->init(currentLine);
    students.push_back(s);
  }

} // end loadStudents



void showStudentNames(std::vector<Student*>& students){

  for(Student* student : students){
    std::cout << student->getLastFirst() << std::endl;
  }

} // end showStudentNames



void printStudents(std::vector<Student*>& students){

  for(Student* student : students){
    student->printStudent();
  }

} // end printStudents



void findStudent(std::vector<Student*>& students){

    std::string searchName;

    std::cout << "last name of student: ";
    getline(std::cin, searchName);

    for (Student* student : students){

        std::string lastName = student->getLastName();

        if (lastName.find(searchName) != std::string::npos){
            student->printStudent();
        }

    }

} // end findStudent



void delStudents(std::vector<Student*>& students){

  for(Student* student : students){
    delete student;
  }

  students.clear();

} // end delStudents



std::string menu(){

  std::string choice;

  std::cout << std::endl;
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;
  std::cout << std::endl;

  std::cout << "please choose 0-3: ";
  std::cin >> choice;

  return choice;

} // end menu



void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress



void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate



void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent