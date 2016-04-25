// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#include "AmaPerishable.h"
using namespace std;
namespace sict{
	AmaPerishable::AmaPerishable(char P):AmaProduct(P){
	}
	const Date& AmaPerishable::expiry() const{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date & value){
		expiry_ = value;
	}
	fstream& AmaPerishable::store(fstream & file, bool addNewLine) const{
		AmaProduct::store(file , false);
		file << ',' << expiry_ << (addNewLine == true ? "\n" : "");
    return file;
	}
	fstream& AmaPerishable::load(fstream & file){
    AmaProduct::load(file);
    expiry_.read(file);
    return file;
	}
	ostream& AmaPerishable::write(ostream & ostr, bool linear) const{
    AmaProduct::write(ostr,linear);
    if (err_.isClear() && Product::isEmpty() != true) {
      if (linear == true) {
        ostr << expiry_;
      }
      else {
        ostr << endl << "Expiry date : " << expiry_;
      }
    }
    return ostr;
	}
	istream& AmaPerishable::read(istream & istr){
    AmaProduct::read(istr);
    Date temp;
    if (err_.isClear()) {
      cout << "Expiry date (YYYY/MM/DD): ";
      istr >> temp;
      if (temp.errCode() == CIN_FAILED) {
        err_.message("Invalid Date Entry");
        istr.setstate(ios::failbit);
      }
      else if (temp.errCode() == YEAR_ERROR) {
        err_.message("Invalid Year in Date Entry");
        istr.setstate(ios::failbit);
      }
      else if (temp.errCode() == MON_ERROR) {
        err_.message("Invalid Month in Date Entry");
        istr.setstate(ios::failbit);
      }
      else if (temp.errCode() == DAY_ERROR) {
        err_.message("Invalid Day in Date Entry");
        istr.setstate(ios::failbit);
      }
    }
    
    expiry_ = temp;
    return istr;
	}
}
