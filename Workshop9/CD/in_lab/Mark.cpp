#include <iostream>
#include <iomanip>
using namespace std;
#include "Mark.h"
namespace sict{
  Mark::Mark():displayType_(DSP_RAW){
    outOf(100);
    totalMark(0);
  }
  Mark::Mark(int value) : displayType_(DSP_RAW){
    outOf(100);
    totalMark(value);
  }
  Mark::Mark(int value, int outOfValue) : displayType_(DSP_RAW){
    outOf(outOfValue);
    totalMark(value);
  }
  Mark::~Mark(){
  // un-comment to see the execution of the destructor
  /*  cout <<"{{{"<< totalMark_ << "/" << outOf_ 
      << " is going to die!}}}"<< endl;*/
  }          
  int Mark::gpaVal()const{
    int ret = 0;
    int val = weightedMark();
    if (val >= 80) ret = 4;
    else if (val >= 70) ret = 3;
    else if (val >= 60) ret = 2;
    else if (val >= 50) ret = 1;
    return ret;
  }
  int Mark::outOf()const{
    return outOf_;
  }
  Mark& Mark::outOf(int value){
    outOf_ = value;
    return *this;
  }
  int Mark::displayType()const{
    return displayType_;
  }
  void Mark::displayType(int value){
    displayType_ = value;
  }

  int Mark::totalMark()const{
    return totalMark_;
  }
  Mark& Mark::totalMark(int value){
    totalMark_ = value;
    return *this;
  }

 
  int Mark::weightedMark()const{
    return int(totalMark() / double(outOf()) * 100);
  }
  //starts here
  char Mark::grade()const{
    char ret = 'F';
    int wm = weightedMark();
    if (wm >= 80){
      ret = 'A';
    }
    else if (wm >= 70){
      ret = 'B';
    }
    else if (wm >= 60){
      ret = 'C';
    }
    else if (wm >= 50){
      ret = 'D';
    }
    return ret;
  }
  double Mark::gpa()const{
    return 4.0 * totalMark() / outOf();
  }
  ostream& Mark::display(ostream& os)const{
    if (displayType_ == DSP_GRADE){
      os << grade();
    }
    else if (displayType_ == DSP_GPA){
      os << setprecision(1) << fixed << gpa();
    }
    else if (displayType_ == DSP_MARK){
      os << weightedMark();
    }
    else if (displayType_ == DSP_RAW){
      os << totalMark() << "/" << outOf();
    }
    else{
      os << "Bad display type for a mark";
    }
    return os;
  }
  istream& Mark::read(istream& is){
    return is >> totalMark_;
  }
  Mark& Mark::operator=(int value){
    totalMark(value);
    return *this;
  }
  Mark::operator int()const{
    return totalMark();
  }
  Mark::operator double()const{
    return totalMark()/double(outOf());
  }
  Mark& Mark::operator+=(const Mark& M){
    if (displayType_ == DSP_GPA){
      totalMark_ = weightedMark() / 25;
      outOf_ = 4;
      totalMark_ += M.gpaVal();
    }
    else{
      double sum = double(totalMark_) / double(outOf_) +
        double(M.totalMark_) / double(M.outOf_);
      sum *= 100;
      totalMark_ = int(sum);
      outOf_ = 100;
   }
    return *this;
  }
  Mark Mark::operator+(const Mark& M)const{
    Mark res = *this;
    return res += M;
  }
  Mark& Mark::operator/=(int value){
    totalMark_ = double(totalMark_) / outOf_ / value * 100;
    outOf_ = 100;
    return *this;
  }
  Mark Mark::operator/(int value)const{
    Mark res = *this;
    return res /= value;
  }
  bool Mark::operator>(const Mark& M)const{
    return weightedMark() > M.weightedMark();
  }
  bool Mark::operator<(const Mark& M)const{
    return weightedMark() < M.weightedMark();
  }
  bool Mark::operator<=(const Mark& M)const{
    return weightedMark() <= M.weightedMark();
  }
  bool Mark::operator>=(const Mark& M)const{
    return weightedMark() >= M.weightedMark();
  }
  bool Mark::operator==(const Mark& M)const{
    return weightedMark() == M.weightedMark();
  }
  bool Mark::operator!=(const Mark& M)const{
    return weightedMark() != M.weightedMark();
  }

  std::ostream& operator<<(std::ostream& os, const Mark& M){
    return M.display(os);
  }
  std::istream& operator>>(std::istream& is, Mark& M){
    return M.read(is);
  }

}

