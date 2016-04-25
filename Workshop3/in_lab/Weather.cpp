//Saad Toor
//068964139
//2/2/2016


#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Weather.h"

namespace sict{
  void Weather::set(const char* date, double high, double low){
    strcpy(information_, date);
    highTemperature_ = high;
    lowTemperature_ = low;
  }

  void Weather::display() const{
	  
	  cout << left << setfill('_') << setw(10) << information_;
	  cout << right << setfill('_') << setw(6) << fixed << setprecision(1) << highTemperature_;
	  cout << right << setfill('_') << setw(6) << fixed << setprecision(1) << lowTemperature_ << endl;
  }
}
