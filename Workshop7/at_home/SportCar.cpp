
#include <iostream>
#include "SportCar.h"
#include "Car.h"

namespace sict{
	SportCar::SportCar(){
		noOfPassengers_ = 1;
	}
	SportCar::SportCar(int maxSpeed, int Pnum ):Car(maxSpeed) {
		
		noOfPassengers_ = Pnum;
	}
	void SportCar::accelerate() {
		int a = speed() + 40;
		speed(a);
	}
	void SportCar::brake() {
		int b = speed() - 10;
		speed(b);
	}
	std::ostream& SportCar::display(std::ostream& ostr) const {

		if (speed() > 0){
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << this->speed() << " km/h.";
		}

		if (speed() == 0){
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
		}
		return ostr;
	}

}