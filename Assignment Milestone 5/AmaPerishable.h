// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////
#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include "AmaProduct.h"
#include "Date.h"
namespace sict{
  class AmaPerishable:public AmaProduct{
  private:
    Date expiry_;
  public:
    AmaPerishable(char P = 'P');
    const Date& expiry()const;
    void expiry(const Date &value);
    std::fstream& store(std::fstream& file, bool addNewLine = true)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& istr);
  };
}
#endif
