//Saad Toor
//068964139
//02/16/2016

#include <iostream>
#include "Enrollment.h"
#include <cstring>
using namespace std;
using namespace sict;

bool Enrollment::isValid()const{
  return name_ && name_[0];
}

void Enrollment::setEmpty(){
  name_[0] = 0;
  code_[0] = 0;
  year_ = 0;
  semester_ = 0;
  slot_ = 0;
  enrolled_ = false;
}

bool Enrollment::isEnrolled() const{
  return enrolled_;
}

void Enrollment::display(bool nameOnly)const{
  if (isValid()){
    cout << name_;
    if (!nameOnly){
      cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
      cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
    }
  }
  else{
    cout << "Invalid enrollment!" << endl;
  }
}

void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
  if (year >= 2015 && semester > 0 && semester < 4 && time > 0 && time < 6){
    strcpy(name_, name);
    strcpy(code_, code);
    year_ = year;
    semester_ = semester;
    slot_ = time;
    enrolled_ = enrolled;
  }
  else{
    setEmpty();
  }
}

bool Enrollment::hasConflict(const Enrollment &other) const{
  bool conflict = false;

  if ((isValid() == false || other.isValid() == false)){
    conflict = false;
  }
  else if ((year_ == other.year_) && (semester_ == other.semester_) && (slot_ == other.slot_)){
    conflict = true;
  }
  return conflict;
}

Enrollment::Enrollment(){
  setEmpty();
}

Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){
  if (name && name[0] && code && code[0] && (year >= 2015) && (semester > 0 && semester < 4) && (time > 0 && time < 6)){
    strcpy(name_, name);
    strcpy(code_, code);
    year_ = year;
    semester_ = semester;
    slot_ = time;
    enrolled_ = false;
  }
  else{
    setEmpty();
  }
}

void Enrollment::withdraw(){
	enrolled_ = false;
}

int Enrollment::enrol(const Enrollment* enrollments, int size){
  int i;
 
  for (i = 0; i < size; i++){
    if ((slot_ == enrollments[i].slot_)){
      enrolled_ = false;
	  return ++i;
    }
    else{
      enrolled_ = true;
    }
  }

  return 0;
}