#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
using namespace std;
namespace sict{
  class Account{
    char name_[41];
    double balance_;
  public:
    Account();
    Account(double balance);
    Account(const char name[], double balance = 0.0);
    void display(bool gotoNewline = true)const;

    void display(std::ostream& os = std::cout) const;


    Account& operator+=(const Account& acc);
    Account& operator=(const char* s);
    friend Account& operator+(const Account& b, const Account& c);
  };

  std::ostream& operator<<(std::ostream& o,const Account& b);
};

#endif
