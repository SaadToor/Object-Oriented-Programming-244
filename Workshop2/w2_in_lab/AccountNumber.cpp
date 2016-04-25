// OOP244 Workshop 2: Compound types and privacy
// File	Workshop_2_in_lab
// Version 1.0
// Date	1/19/2016
// Author	Saad_Toor
// Description
// Workshop_2_in_lab
//
//
// Revision History
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
  
  void AccountNumber::name(const char name[]){
	 strcpy(_name, name);
	//strncpy(_name, name, 45);
	//_name[45] = 0;
  }

  void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
    if(bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE && accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO){
      _bankCode = bankCode;
      _branchCode = branchCode;
      _accountNumber = accountNumber;
      _validAccNumber = true;
    }
    else{
      _validAccNumber = false;
    }
  }

  bool AccountNumber::isValid() const{
    return _validAccNumber;
  }

  void AccountNumber::display() const{
    if (_validAccNumber == true){
      cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
    }
    else
    {
      cout << _name << " does not have a valid account number." << endl;
    }
  }
}
