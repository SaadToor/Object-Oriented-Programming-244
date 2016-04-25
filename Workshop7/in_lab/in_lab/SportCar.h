#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include "Car.h"
namespace sict{
  class SportCar : public Car{
	  int noOfPassengers_;
  public:
	  SportCar();
    SportCar(int passengers, int speed);
    // implementations of Vehicle's pure virtual methods
	  virtual void accelerate() = 0;
	  virtual void brake()=0;
	  virtual std::ostream& display(std::ostream& ostr) const=0;
  };
}
#endif