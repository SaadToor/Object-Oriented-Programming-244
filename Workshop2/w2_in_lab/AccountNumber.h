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

#ifndef SICT_ACCOUNTNUMBER_H_
#define SICT_ACCOUNTNUMBER_H_

namespace sict{

	#define MAX_NAME_LENGTH 40
	#define MIN_BANKCODE 100
	#define MAX_BANKCODE 999
	#define MIN_BRANCHCODE 1
	#define MAX_BRANCHCODE 220
	#define MIN_ACCNO  10000
	#define MAX_ACCNO  99999

  class AccountNumber{

  private:
    char _name[MAX_NAME_LENGTH + 1];
    int _bankCode;
    int _branchCode;
    int _accountNumber;
    bool _validAccNumber;

  public:
    void name(const char name[]);
    void accountNumber(int bankCode, int branchCode, int accountNumber);
    void display() const;
    bool isValid() const;
  };

}

#endif

