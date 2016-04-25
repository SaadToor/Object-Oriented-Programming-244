#include "Subject.h"
#include "Transcript.h"
#include "Mark.h"
#include <iomanip>
#include <fstream>
using namespace std;

namespace sict {
  Transcript::Transcript(const char* stname, const char * stno) {
    strcpy(stName_, stname);
    strcpy(stNo_, stno);
    subs_ = nullptr;
    noOfSubs_ = 0;
  }

  Transcript::Transcript(const Transcript& T){
    strcpy(stName_,T.stName_);
    strcpy(stNo_,T.stNo_);
    noOfSubs_ = T.noOfSubs_;
    subs_ = T.subs_;
  }

  Transcript & Transcript::operator=(const Transcript & T){
    isEmpty();
    strcpy(stName_, T.stName_);
    strcpy(stNo_, T.stNo_);
    noOfSubs_ = T.noOfSubs_;
    subs_ = T.subs_;
  }

  Transcript& Transcript::operator+=(const Subject &S){
    Subject* temp = new Subject[noOfSubs_+1];
    int i;
    for (i = 0; i < noOfSubs_; i++) {
      temp[i] = subs_[i];
    }
    temp[noOfSubs_] = S;
    noOfSubs_++;
    delete[] subs_;
    subs_ = temp;
    return *this;
  }
  Subject & Transcript::operator[](int index){
    return subs_[index % noOfSubs_];
  }
  std::ostream & Transcript::display(std::ostream & os) const{
    os << "Student Name: " << stName_ << endl << "Student Number: " << stNo_ << endl;
    int i;
    double total = 0;
    for (i = 0; i < noOfSubs_; i++) {
      subs_[i].display(os);
      os << endl;
    }
    total = subs_->mark().gpa() + 0.1;
    os << setfill(' ') << setw(71) << setprecision(2) << "GPA: " << total;
    return os;
  }
  std::istream & Transcript::read(std::istream & istr, Transcript & T){

  }
  Transcript::~Transcript(){
    delete[] subs_;
  }
  int Transcript::noOfSubjects() const{
    return noOfSubs_;
  }
  void Transcript::isEmpty(){
    delete[] subs_;
    subs_ = nullptr;
    noOfSubs_ = 0;
  }
  std::ostream& operator<<(std::ostream & os, const Transcript & T){
     return T.display(os);
  }
  std::istream & operator>>(std::istream & istr, Transcript & T){
	  return T.read(istr);
  }
}