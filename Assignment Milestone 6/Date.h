// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////


#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
namespace sict{

  class Date{
  private:
    int year_;
    int mon_;
    int day_;
    int readErrorCode_;
    void errCode(int errorCode);
    int value()const;
  public:
    Date();
    Date(int year, int mon, int day);

    bool operator==(const Date& D)const; 
    bool operator!=(const Date& D)const; 
    bool operator<(const Date& D)const; 
    bool operator>(const Date& D)const; 
    bool operator<=(const Date& D)const; 
    bool operator>=(const Date& D)const;

    int mdays()const;

    int errCode()const;
    bool bad()const;

    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr)const;
  };

  std::ostream& operator<<(std::ostream& o, const Date& D);
  std::istream& operator>>(std::istream& i, Date& D);
}
#endif