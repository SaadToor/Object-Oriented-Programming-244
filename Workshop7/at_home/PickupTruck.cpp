#include <cstring>
#include<iostream>
#include "PickupTruck.h"
#include "Car.h"

namespace sict{

	PickupTruck::PickupTruck(){
		loadAmount_ = 0;
	
	}
	void PickupTruck::load(const char* loadedMaterial, int loadAmount){
		strcpy(loadedMaterial_, loadedMaterial);
		loadAmount_ = loadAmount;

	}
	void PickupTruck::unload(){
		loadAmount_ = 0;
	}
	bool PickupTruck::isEmpty()const{
		if (loadAmount_ == 0){
			return true;
		}
		return false;
	}
	void PickupTruck::accelerate() {
		int d = speed() + 20;
		speed(d);
	}
	void PickupTruck::brake() {
		int f = speed() - 5;
		speed(f);
	}
	std::ostream& PickupTruck::display(std::ostream& ostr) const {
		if (isEmpty()){
			ostr << "This pickup truck is not carrying any load";
		}
		else{
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
		}

		if (speed() > 0){
			ostr << ", traveling at the speed of " << speed() << " km/h.";
		}
		
		if (speed() == 0){
			ostr << " and is parked.";
		}
		return ostr;
	}


}