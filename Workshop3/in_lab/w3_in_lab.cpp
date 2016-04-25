// OOP244 Workshop 3: Dynamic Memory
// File	w3_in_lab.cpp
// Version 1.0
// Date	???
// Author   ???
// Description
// This file is used to demonstrate dynamic memory in 
// C++ and to process an array of objects of compound 
// type where the user specifies the number of 
// elements in the array at run-time.
/////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"
using namespace std;
using namespace sict;
int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  Weather* weather;


  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  weather = new Weather[n];


  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;

    cout << "Enter date: ";
    cin >> date_description;
    cout << "Enter high: ";
    cin >> high;
    cout << "Enter low : ";
    cin >> low;

    weather[i].set(date_description, high, low);

  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++){
    weather[i].display();
  }

  delete weather;

  return 0;
}
