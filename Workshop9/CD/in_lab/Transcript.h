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
    Transcript& operator+=(const Subject& S);
    Subject& operator[](int index);
    std::ostream& display(std::ostream& os)const;
    virtual ~Transcript();
    int noOfSubjects()const;
    void isEmpty();
  };
  std::ostream& operator<<(std::ostream & os, const Transcript & T);
}


#endif