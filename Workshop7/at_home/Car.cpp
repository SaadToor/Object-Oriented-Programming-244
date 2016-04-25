#include "Car.h"
namespace sict{

	Car::Car(int maxSpeed){
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}
	void Car::speed(int value){
		speed_ = value;
		if (value > maxSpeed_ && value < 0){
			value = maxSpeed_;
			value = 0;
		}
	}
	int Car::maxSpeed()const{
		return maxSpeed_;
	}
	int Car::speed() const{
		return speed_;
	}
  std::ostream & operator<<(std::ostream& ostr, const Car& C){
    return C.display(ostr);
  }
}