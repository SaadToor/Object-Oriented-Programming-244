#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Subject.h"

namespace sict{
  Subject::Subject():name_(nullptr), mark_(0){
    code_[0] = 0;
    mark_.displayType(DSP_GRADE);
    //name_ = nullptr;
  }
  Subject::Subject(const char*name, const char* theCode
    , int mark, int outOf):mark_(mark, outOf){
    code(theCode);
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    mark_.displayType(DSP_GRADE);
  }
  Subject::Subject(const Subject& S){
    if (!S.isEmpty()){
      code(S.code_);
      name_ = new char[strlen(S.name_) + 1];
      strcpy(name_, S.name_);
      mark_ = S.mark_;
    }
    else{
      code_[0] = 0;
      name_ = nullptr;
    }

  }
  Subject& Subject::operator=(const Subject& S){
    if (this != &S){
      delete[] name_;
      if (!S.isEmpty()){
        code(S.code_);
        name_ = new char[strlen(S.name_) + 1];
        strcpy(name_, S.name_);
        mark_ = S.mark_;
      }
      else{
        code_[0] = 0;
        name_ = nullptr;
        mark_ = 0;
      }
    }
    return *this;
  }
  Subject::~Subject(){
    delete[] name_;
  }
  const char* Subject::name()const{
    return name_;
  }
  void Subject::name(const char* value){
    delete[] name_;
    name_ = new char[strlen(value) + 1];
    strcpy(name_, value);
  }
  void Subject::code(const char* value){
    strncpy(code_, value, 6);
    code_[6] = 0;
  }
  const char* Subject::code()const{
    return code_;
  }
  void Subject::mark(int value, int outOf){
    mark_.totalMark(value);
    mark_.outOf(outOf);
  }
  void Subject::mark(const Mark& value){
    mark_ = value;
  }
  Subject& Subject::operator=(const Mark& value){
    mark(value);
    return *this;
  }
  const Mark& Subject::mark()const{
    return mark_;
  }
  std::ostream& Subject::display(std::ostream& os)const{
    return os << left <<code_ << ": " << right << setfill('.') << setw(65) <<" "<< mark_;
  }
  std::istream& Subject::read(std::istream& is){
    char buf[81];
    cout << "Name: ";
    is.getline(buf, 80, '\n');
    if (is.fail()){
      is.clear();
      is.ignore(1000, '\n');
    }
    name(buf);
    cout << "Code: ";
    is.getline(buf, 80, '\n');
    if (is.fail()){
      is.clear();
      is.ignore(1000, '\n');
    }
    code(buf);
    cout << "Mark: ";
    return is >> mark_;
  }
  Subject::operator int()const{
    return int(mark_);
  }
  Subject::operator double()const{
    return double(mark_);
  }
  Subject::operator const char*()const{
    return name_;
  }
  bool Subject::isEmpty()const{
    return name_ == nullptr;
/*    if (name_ == nullptr){
      return true;
    }
    else{
      return false;
    } */
  }
  std::ostream& operator<<(std::ostream& os, const Subject& S){
    return S.display(os);
  }
  std::istream& operator>>(std::istream& is, Subject& S){
    return S.read(is);
  }

}