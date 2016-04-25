//Saad Toor
//068964139
//2/2/2016
#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

namespace sict{
 class Weather{
   double highTemperature_;
   double lowTemperature_;
   char information_[8];
 
  public:
    void set(const char* date, double high, double low);
    void display() const;
   
  };
 }

#endif

