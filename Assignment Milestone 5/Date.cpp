// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////


#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{
  int Date::value()const{
    return year_ * 372 + mon_ * 31 + day_;
  }
  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
    mon--;
    return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }
  Date::Date(){
    year_ = 0;
    mon_ = 0;
    day_ = 0;
    readErrorCode_ = 0;
  }
  Date::Date(int year, int mon, int day){
	  year_ = year;
	  mon_ = mon;
	  day_ = day;
	  readErrorCode_ = 0;
  }
  void Date::errCode(int errorCode){
    readErrorCode_ = errorCode;
  }
  bool Date::operator==(const Date& D)const{
	  return (value() == D.value());
  }
  bool Date::operator!=(const Date& D)const{
	  return (value() != D.value());
  }
  bool Date::operator<(const Date& D)const{
	  return (value() < D.value());
  }
  bool Date::operator>(const Date& D)const{
    return (value() > D.value());
  }
  bool Date::operator<=(const Date& D)const{
	  return (value() <= D.value());
  }
  bool Date::operator>=(const Date& D)const{
	  return (value() >= D.value());
  }
  int Date::errCode()const{
    return readErrorCode_;
  }
  bool Date::bad()const{
    return (!(readErrorCode_ == 0));
  }
  std::istream& Date::read(std::istream& istr){
    istr >> year_;
    istr.ignore(100,'/');
    istr >> mon_;
    istr.ignore(100,'/');
	  istr >> day_;
	  if (istr.fail()){
      readErrorCode_ = CIN_FAILED;
     }
    else if (!((year_ >= MIN_YEAR) && (year_ <= MAX_YEAR))){
       readErrorCode_ = YEAR_ERROR;
     }
	  else if (!((mon_ >= 1) && (mon_ <= 12))){
       readErrorCode_ = MON_ERROR;
     }
	  else if (!((day_ > 0) && (day_ < 31))){
       readErrorCode_ = DAY_ERROR;
     }
    return istr;
  }
  std::ostream& Date::write(std::ostream& ostr)const{
    return ostr << year_ << "/" << (mon_ < 10 ? "0" : "") << mon_ << "/" << (day_ < 10 ? "0" : "") << day_;
  }
  std::ostream& operator<<(std::ostream& o, const Date& D){
	  return D.write(o);
  }
  std::istream& operator>>(std::istream& i, Date& D){
	  return D.read(i);
  }
}