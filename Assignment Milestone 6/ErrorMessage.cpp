// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#include "ErrorMessage.h"
#include <cstring>
namespace sict{
  ErrorMessage::ErrorMessage(){
    message_ = nullptr;
  }
  ErrorMessage::ErrorMessage(const char* errorMessage){
    message_ = nullptr;
    message(errorMessage);
  }
  ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
    clear();
    message(errorMessage);
    return *this;
  }
  ErrorMessage::~ErrorMessage(){
	  clear();
  }
  void ErrorMessage::clear(){
    delete[] message_;
    message_ = nullptr;
  }
  bool ErrorMessage::isClear()const{

    return (message_ == nullptr);
  }
  void ErrorMessage::message(const char* value){
    clear();
    message_ = new char[strlen(value) + 1];
    strcpy(message_, value);
  }
  const char* ErrorMessage::message()const{
    return message_;
  }
  std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& Err){
    return ostr << (Err.isClear() == true ? "" : Err.message());
  }
}