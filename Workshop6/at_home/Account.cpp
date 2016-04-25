#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Account.h"
#include <cstring>
using namespace std;
namespace sict{
	Account::Account(){
		name_[0] = 0;
		balance_ = 0;
	}
	Account::Account(double balance){
		name_[0] = 0;
		balance_ = balance;
	}
	Account::Account(const char name[], double balance){
		strncpy(name_, name, 40);
		name_[40] = 0;
		balance_ = balance;
	}

	void Account::display(bool gotoNewline)const{
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}
	double Account::getBalance()const{
    return balance_;
	}
	Account& Account::operator+=(const Account& acc){
		balance_ += acc.balance_;
		return *this;
	}
	Account& Account::operator=(const char* s){
		strcpy(name_, s);
		return *this;
	}
	Account& operator+(const Account& b, const Account& c){
		double balance = b.getBalance() + c.getBalance();
		Account A(balance);
		return A;
	}
  double operator+=(double& b, const Account& A){
		b += A;
    return b;
	}
	ostream& operator<<(ostream& o, const Account& b){
		b.display(false);
		return o;
	}
}