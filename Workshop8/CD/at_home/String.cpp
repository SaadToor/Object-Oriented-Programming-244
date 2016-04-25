//Saad Toor
//4/7/2016

#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict {
  void String::deallocate() {
    if (data_) delete[] data_;
    data_ = nullptr;
    memSize_ = 0;
  }
  void String::allocate(int memsize) {
    deallocate();
    data_ = new char[memsize + 1];
    memSize_ = memsize;
  }

  void String::resize(int memsize) {
    char* temp = new char[memsize];
    int i = 0;
    for (i = 0; i < memsize && i < len_; i++) {
      temp[i] = data_[i];
    }
    temp[i] = 0;
    deallocate();
    data_ = temp;
    memSize_ = memsize;
    len_ = i;
  }

  String::String() {
    data_ = nullptr;
    memSize_ = len_ = 0;
  }

  void String::init(const char* str, int memSize) {
    data_ = nullptr;
    if (memSize < (strlen(str) + 1)) {
      memSize = strlen(str) + 1;
    }
    allocate(memSize);
    strcpy(data_, str);
    len_ = strlen(str);
  }

  String::String(const char* str, int memSize) {
    init(str, memSize);
  }

  String::String(const String& S) {
    init(S.data_, S.memSize_);
  }
  String& String::operator=(const String& S) {
    if (this != &S) {
      deallocate();
      init(S.data_, S.memSize_);
    }
    return *this;
  }


  String::~String() {
    deallocate();
  }

  int String::length()const {
    return len_;
  }

  int String::memSize()const {
    return memSize_;
  }

  String::operator const char*()const {
    return data_;
  }

  istream& String::read(istream& istr) {
    char ch;
    ch = istr.get();
    int i;
    for (i = 0; ch != '\n'; i++) {
      if (len_ == memSize_ - 1) {
        len_ = i;
        resize(memSize_ + ExpansionSize);
      }
      data_[i] = ch;
      data_[i] = 0;
      len_ = i;
    }
    return istr;
  }

  String& String::operator+=(const char* str) {
    int slen = strlen(str);
    if ((len_ + slen) + 1 > memSize_) {
      resize((len_ + slen) + 1);
    }
    strcat(data_, str);
    len_ += slen;
    return *this;
  }

  String& String::operator+=(String& s) {
    return operator+=(s.data_);
  }

  String String::operator+(const String & s) const {
    String S(data_);
    S.operator+=(s);
    return S;
  }

  String& String::operator++() {
    String sp(" ");
    sp.operator+=(*this);
    operator=(sp);
    return *this;
  }

  String String::operator++(int) {
    String S(*this);
    operator+=(" ");
    return S;
  }

  char& String::operator[](int index) {
    if (index > memSize_ - 1) {
      resize(index + ExpansionSize);
    }
    return data_[index];
  }
  String::operator int()const {
    return len_;
  }

  std::ostream& operator<<(std::ostream& ostr, const String &s) {
    const char* str = (const char*)s;
    return ostr << (str == nullptr ? "" : str);
  }

  std::istream& operator>>(std::istream& istr, String &s) {
    return s.read(istr);
  }

}