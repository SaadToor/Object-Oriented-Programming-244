#include <cstring>
#include "PickupTruck.h"
namespace sict{
  PickupTruck::PickupTruck()  {
    loadAmount_ = 0;
    loadedMaterial_[0] = char(0);
  }
  bool PickupTruck::isEmpty()const{
    return loadAmount_ == 0;
  }
  void PickupTruck::load(const char* loadedMaterial, int loadAmount){
    std::strcpy(loadedMaterial_, loadedMaterial);
    loadAmount_ = loadAmount;
  }
  void PickupTruck::accelerate(){
    speed(speed() + 20);
  }
  void PickupTruck::brake()
  {
    speed(speed() - 5);
  }
  void PickupTruck::unload(){
    loadAmount_ = 0;
  }
  std::ostream& PickupTruck::display(std::ostream& os) const
  {
    os << "This pickup truck is ";
    if (isEmpty()){
      os << "not carrying any load";
    }
    else{
      os << "carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
    }
    if (speed() > 0){
      os << ", traveling at the speed of " << speed() << " km/h.";
    }
    else{
      os << " and is parked.";
    }
    return os;
  }
}