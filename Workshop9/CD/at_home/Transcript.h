#ifndef SICT_TRANSCRIPT_H_
#define SICT_TRANSCRIPT_H_
#include "Subject.h"
namespace sict {
  class Transcript {
    char stName_[81];
    char stNo_[10];
    int noOfSubs_;
    Subject* subs_;
  public:
    Transcript(const char* stname, const char* stno);
    Transcript(const Transcript& T);
    Transcript& operator=(const Transcript& T);
    Transcript& operator+=(const Subject& S);
    Subject& operator[](int index);
    std::ostream& display(std::ostream& os)const;
    std::istream& read(std::istream& istr, Transcript& T);
    virtual ~Transcript();
    int noOfSubjects()const;
    void isEmpty();
  };
  std::ostream& operator<<(std::ostream & os, const Transcript & T);
  std::istream& operator>>(std::istream & istr, Transcript & T);
}


#endif