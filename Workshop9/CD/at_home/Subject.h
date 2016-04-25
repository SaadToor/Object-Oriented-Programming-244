#ifndef SICT_SUBJECT_H_
#define SICT_SUBJECT_H_
#include <iostream>
#include "Mark.h"
namespace sict{
  class Subject{
  private:
    char code_[7];
    char* name_;
    Mark mark_;

  public:
    Subject();
    Subject(const char* name, const char* code
            , int mark=0, int outOf = 100);
    Subject(const Subject& S);
    Subject& operator=(const Subject& S);


    ~Subject();
    bool isEmpty()const;
    void name(const char* value);
    const char* name()const;
    void code(const char* value);
    const char* code()const;
    void mark(int value, int outOf = 100);
    void mark(const Mark& value);
    Subject& operator=(const Mark& value);
    const Mark& mark()const;
    std::ostream& display(std::ostream& os)const;
    std::istream& read(std::istream& is);
    operator int()const;
    operator double()const;
    operator const char*()const;
  };

  std::ostream& operator<<(std::ostream& os, const Subject& S);
  std::istream& operator>>(std::istream& is, Subject& S);


}

#endif
