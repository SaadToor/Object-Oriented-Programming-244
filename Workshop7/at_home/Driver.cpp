#include <iostream>
#include <cstring>
#include "Driver.h"
using namespace std;
namespace sict{

  Driver::Driver(const char* name, Car& cRef)
    :car_(cRef){
    strncpy(name_,name,strlen(name)+1);
  }

  void Driver::drive(){
    car_.accelerate();
    car_.brake();
    showStatus();
  }

  void Driver::stop(){
    while (car_.speed() != 0) {
      car_.brake();
    }
    showStatus();
  }

  void Driver::showStatus(){
    cout << name_ << " is driving this car." << endl;
    car_.display(std::cout);
    cout << endl;
  }

}