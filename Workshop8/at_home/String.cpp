#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict {
  void String::deallocate() {
    delete[] data_;
    data_ = nullptr;
    memSize_ = 0;
  }
  void String::allocate(int memsize) {
    deallocate();
    data_ = new char[memSize_ = memsize];
  }

  void String::resize(int memsize) {
    char* temp = new char[memsize];
    int i = 0;
    for (i = 0; data_ && i < memsize - 1 && i < len_; temp[i] = data_[i++]);
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
    len_ = strlen(str);
    allocate(len_ + 1 > memSize ? len_ + 1 : memSize);
    strcpy(data_, str);
  }

  String::String(const char* str, int memSize) {
    init(str, memSize);
  }

  String::String(const String& S) {
    init(S.data_, S.memSize_);
  }
  String& String::operator=(const String& S) {
    deallocate();
    init(S.data_, S.memSize_);
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

  String::operator const char *()const {
    return data_;
  }

  istream& String::read(istream& istr) {                                     
    char ch;
    int i;
    for (i = 0; (ch = istr.get()) != '\n'; i++) {
      if (i == memSize_ - 1) {
        len_ = i;
        resize(memSize_ + ExpansionSize);
      }
      data_[i] = ch;
    }
    data_[len_ = i] = 0;
    return istr;
  }

  String& String::operator+=(const char* str) {
    int slen = strlen(str);
    if (len_ + slen > memSize_) {
      resize(len_ + slen + 1);
    }
    strcat(data_, str);
    len_ += slen;
    return *this;
  }

  String& String::operator+=(String& s) {
    return operator+=(s.data_);
  }

  String& String::operator++() {
    String sp(" ");
    sp.operator+=(*this);
    operator=(sp);
    return *this;
  }

  String& String::operator++(int) {
    operator+=(" ");
    return *this;
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
    return ostr << ((const char*)s);
  }
  std::istream& operator>>(std::istream& ostr, String &s) {
    return s.read(ostr);
  }
}
