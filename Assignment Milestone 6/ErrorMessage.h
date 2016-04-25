// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
namespace sict{
  class ErrorMessage{
    char* message_;
  public:
    ErrorMessage();
    ErrorMessage(const char* errorMessage);
    ErrorMessage(const ErrorMessage& em) = delete;
    ErrorMessage& operator=(const ErrorMessage& em) = delete;
    ErrorMessage& operator=(const char* errorMessage);
    virtual ~ErrorMessage();
    void clear();
    bool isClear()const;
    void message(const char* value);
    const char* message()const;
  };
  std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& Err);
}
#endif

