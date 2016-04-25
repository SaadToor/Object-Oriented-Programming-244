#include "Car.h"
namespace sict{
  Car::Car(int maxSpeed){
    if (maxSpeed != 0 || !(maxSpeed < 0)){
      maxSpeed_ = maxSpeed;
    }
    else{
      maxSpeed_ = 100;
    }
    speed_ = 0;
  }
  void Car::speed(int value){
    if (value > maxSpeed_ || value < 0){
      speed_ = 0;
    }
    else{
      speed_ = value;
    }
  }
  int Car::maxSpeed()const{
    return maxSpeed_;
  }
  int Car::speed() const{
    return speed_;
  }
}