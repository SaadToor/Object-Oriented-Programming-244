// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date	
// Author	
// Description
///////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Weather.h"
using namespace std;
using namespace sict;

double findLow(const char* date, const Weather *data, int dataSize){
  int i;
  double ret;
  ret = 0.0;
  i = 0;

  while (i < dataSize){
    if (strcmp(date, data[i].date()) == 0){
      ret = data[i].low();
    }
    i++;
  }
  return ret;
}

int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  Weather* weather;// create the weather pointer here

  cout << "Weather Data\n";
  cout << "=====================" << endl;
  cout << "Days of Weather: ";
  cin >> n;
  // allocate dynamic memory here
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

  char query[7];
  cout << endl << "Enter the date you are looking for: ";

  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.
  cin.ignore();
  cin.getline(query, 7, '\n');

  double low = findLow(query, weather, n);
  cout << "Low temperature: " << low << endl;
  // deallocate dynamic memory here
  delete[] weather;

  return 0;

}
