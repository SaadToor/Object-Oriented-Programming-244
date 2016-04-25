#ifndef SICT_MARK_H_
#define SICT_MARK_H_
#include <iostream>
/*#define DSP_GRADE  0
#define DSP_GPA 1
#define DSP_MARK 2*/
const int DSP_GRADE = 0;
const int DSP_GPA = 1;
const int DSP_MARK = 2;
const int DSP_RAW = 3;
namespace sict{
  class Mark{
  private:
    int outOf_;
    int totalMark_;
    int displayType_;   
    int gpaVal()const;
  public:
    Mark();
    Mark(int totalMark);
    Mark(int totalMark, int outOf);
    virtual ~Mark();
    int outOf()const;
    Mark& outOf(int value);  
    int displayType()const;
    void displayType(int value);
    int totalMark()const;
    Mark& totalMark(int value);
    int weightedMark()const;
    char grade()const;
    double gpa()const;
    std::ostream& display(std::ostream& os)const;
    std::istream& read(std::istream& is);
    Mark& operator=(int totalMark);
    operator int()const;
    operator double()const;
    Mark& operator+=(const Mark& M);
    Mark operator+(const Mark& M)const;
    Mark& operator/=(int value);
    Mark operator/(int value)const;
    bool operator>(const Mark& M)const;
    bool operator<(const Mark& M)const;
    bool operator>=(const Mark& M)const;
    bool operator<=(const Mark& M)const;
    bool operator==(const Mark& M)const;
    bool operator!=(const Mark& M)const;
  };
  std::ostream& operator<<(std::ostream& os, const Mark& M);
  std::istream& operator>>(std::istream& is,Mark& M);

}

#endif
