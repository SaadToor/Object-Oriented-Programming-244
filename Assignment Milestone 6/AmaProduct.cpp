// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////
#include "AmaProduct.h"
#include "Streamable.h"
#include "ErrorMessage.h"
#include "Product.h"
#include "general.h"
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sict {
  AmaProduct::AmaProduct(char fTag) {
    fileTag_ = fTag;
    unit_[0] = '\0';
  }
  const char* AmaProduct::unit() const {
    return unit_;
  }
  void AmaProduct::unit(const char * value) {
    strncpy(unit_, value, 10);
    unit_[10] = '\0';
  }
  std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine) const {
    file << fileTag_ << ',' << sku() << ',' << name() << ',' << price()
      << "," << taxed() << ',' << quantity() << ',' << unit() << ','
      << qtyNeeded() << (addNewLine == true ? "\n" : "");
    return file;
  }

  fstream & AmaProduct::load(fstream& file) {
    int tempInt = 0;
    char tempT = '\0';
    double tempDouble = 0;
    char tempString[1000];
    char tmpSku[MAX_SKU_LEN + 1];
    file.getline(tmpSku, MAX_SKU_LEN + 1, ',');
    sku(tmpSku);
    file.getline(tempString, 1000, ',');
    name(tempString);

    file >> tempDouble;
    file.ignore();
    price(tempDouble);

    file.get(tempT);
    file.ignore();
    if(tempT == '1'){
      taxed(true); 
    }
    else{
      taxed(false);
    }

    file >> tempInt;
    file.ignore();
    quantity(tempInt);

    file.getline(tempString, 11, ',');
    unit(tempString);

    file >> tempInt;
    file.ignore();
    qtyNeeded(tempInt);
    return file;
  }

  ostream & AmaProduct::write(ostream & os, bool linear) const {
    if (!err_.isClear()) {
      os << err_;
    }
    if(!err_.message()){
      if (linear == true) {
        os << left << setw(MAX_SKU_LEN) << sku() << '|'
          << left << setw(20) << name() << '|' << right
          << setw(7) << fixed << setprecision(2) << cost() << '|' << right << setw(4) << quantity()
          << '|' << left << setw(10) << unit() << '|' << right << setw(4) << qtyNeeded() << '|';
      }
      if (linear == false) {
        os << "Sku: " << sku() << endl << "Name: " << name() << endl
          << "Price: " << fixed << setprecision(2) << price() << endl << "Price after tax: ";
        if (taxed() == true) {
          os << cost() << endl;
        }
        else {
          os << "N/A" << endl;
        }
        os << "Quantity On Hand: " << fixed << setprecision(2) << quantity() << " " << 
          unit_ << endl << "Quantity Needed: " << qtyNeeded();
      }
    }
    return os;
  }

  istream& AmaProduct::read(istream & istr) {
    err_.clear();
    int tempI;
    double tempD;
    char tempC[100];
    char temp;
    if (!istr.fail()) {
      cout << "Sku: ";
      istr >> tempC;
      sku(tempC);
      cout << "Name: ";
      istr >> tempC;
      name(tempC);
      cout << "Unit: ";
      istr >> unit_;
      cout << "Taxed? (y/n): ";
      istr >> temp;
      if (temp == 'y' || temp == 'Y') {
        taxed(true);
        cin.ignore(1000,'\n');
      }
      else if (temp == 'n' || temp == 'N') {
        taxed(false);
        cin.ignore(1000, '\n');
      }
      else {
        err_.message("Only (Y)es or (N)o are acceptable");
        istr.setstate(ios::failbit);
      }
      if (err_.isClear()) {
        cout << "Price: ";
        istr >> tempD;
        if (istr.fail()) {
          err_.message("Invalid Price Entry");
        }
        else {
          price(tempD);
        }
      }

      if (err_.isClear()) {
        cout << "Quantity On hand: ";
        istr >> tempI;
        if (istr.fail()) {
          err_.message("Invalid Quantity Entry");
        }
        else {
          quantity(tempI);
        }
      }

      if (err_.isClear()) {
        quantity(tempI);
        cout << "Quantity Needed: ";
        istr >> tempI;
        if (istr.fail()) {
          err_.message("Invalid Quantity Needed Entry");
        }
        else {
          qtyNeeded(tempI);
        }
      }
    }
    return istr;
  }
}
