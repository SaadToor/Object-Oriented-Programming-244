//Saad Toor
//068964139
//02/17/2016

#include <cstring>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict{

  Contact::Contact(){
    setEmpty();
  }
  Contact::Contact(const char* name, int phNum){
    phoneNumber_ = nullptr;
    phoneNumber_ = new PhoneNumber[phNum];

    strncpy(name_, name, 40);
    name_[40] = 0;
    _noPN = phNum;
  }

  void Contact::display()const{
    //display the name and go to new line
    cout << name_ << endl;
    // loop through elements of phoneNumber_ up to _noPN and display them one by one
      int i;
      for (i = 0; i < _noPN; i++){
        phoneNumber_[i].display();
      }
    // draw a 40 char line using '-' and go to new line
     cout << std::setw(40) <<  std::setfill('-') << "-" << endl;
  }

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << _noPN << " phone numbers: " << endl;
    for (int i = 0; i < _noPN; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }



  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }
  void Contact::setEmpty(){
    name_[0] = 0;
    _noPN = 0;
    phoneNumber_ = nullptr;// same as phoneNumber_ = (PhoneNumber*)0;
  }
  
  Contact::~Contact(){
    delete[] phoneNumber_;
  }
}
