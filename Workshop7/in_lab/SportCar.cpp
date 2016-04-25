#include "SportCar.h"

namespace sict{
  SportCar::SportCar(){
    noOfPassengers_ = 1;
  }
  SportCar::SportCar(int Snum, int Pnum){
    speed(Snum);
    noOfPassengers_ = Pnum;
  }
  void SportCar::accelerate(){
    int acc = speed() + 40;
    speed(acc);
  }
  void SportCar::brake(){
    int br = speed() - 10;
    speed(br);
  }
  std::ostream& SportCar::display(std::ostream& ostr) const{
    if (speed() > 0){
      ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << this->speed() << " km/h";
    }
    if (speed() == 0) {
      ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
    }
    return ostr;
  }
}