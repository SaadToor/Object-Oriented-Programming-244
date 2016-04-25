//Saad Toor
//068964139
//02/16/2016

#ifndef SICT_ENROLLMENT_H_
#define SICT_ENROLLMENT_H_

namespace sict{
  class Enrollment{
  private:
    char name_[31];
    char code_[11];
    int year_;
    int semester_;
    int slot_;
    bool enrolled_;
  public:

    void display(bool nameOnly = false)const;
    bool isValid()const;
    void setEmpty();
    bool isEnrolled() const;

    void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
    bool hasConflict(const Enrollment &other) const;

    void withdraw();
    int enrol(const Enrollment* enrollments, int size);

    Enrollment();
    Enrollment(const char* name, const char* code, int year, int semester, int time);
  };
}
#endif