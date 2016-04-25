// Final Project Milestone 4
// Date	03/22/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#include "Product.h"
#include <cstring>
#include <iostream>
using namespace std;



namespace sict {
  Product::Product() {
    sku_[0] = 0;
    name_ = nullptr;
    price_ = 0;
    taxed_ = 0;
    quantity_ = 0;
    qtyNeeded_ = 0;
  }
  Product::Product(char* sku, char* name, double price, int qtyNeeded, bool tax) {
    strncpy(sku_, sku, MAX_SKU_LEN + 1);
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    quantity_ = 0;
    price_ = price;
    qtyNeeded_ = qtyNeeded;
  }
  Product::Product(const char * sku, const char * name)
  {
    strncpy(sku_, sku, MAX_SKU_LEN + 1);
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    price_ = 0;
    taxed_ = 0;
    quantity_ = 0;
    qtyNeeded_ = 0;
  }
  Product::Product(const Product& P) {
    name_ = new char[strlen(P.name_) + 
		1];
    strncpy(sku_, P.sku_, MAX_SKU_LEN + 1);
    strcpy(name_, P.name_);
    price_ = P.price_;
    taxed_ = P.taxed_;
    quantity_ = P.quantity_;
    qtyNeeded_ = P.qtyNeeded_;
  }
  Product& Product::operator=(const Product& P) {
    delete[] name_;
    name_ = new char[strlen(P.name_) + 1];
    strncpy(sku_, P.sku_, MAX_SKU_LEN + 1);
    strcpy(name_, P.name_);
    price_ = P.price_;
    taxed_ = P.taxed_;
    quantity_ = P.quantity_;
    qtyNeeded_ = P.qtyNeeded_;
    return *this;
  }

  void Product::sku(const char* s) {
    strncpy(sku_, s, MAX_SKU_LEN + 1);
  }
  void Product::name(const char* n) {
    delete[] name_;
    name_ = new char[strlen(n) + 1];
    strncpy(name_, n, strlen(n) + 1);
  }
  void Product::price(double p) {
    price_ = p;
  }
  void Product::quantity(int q) {
    quantity_ = q;
  }
  void Product::qtyNeeded(int qN) {
    qtyNeeded_ = qN;
  }
  void Product::taxed(int t) {
    taxed_ = t;
  }

  const char* Product::sku() const {
    return sku_;
  }
  const char* Product::name() const {
    return name_;
  }
  double Product::price() const {
    return price_;
  }
  int Product::quantity() const {
    return quantity_;
  }
  int Product::qtyNeeded() const {
    return qtyNeeded_;
  }
  bool Product::taxed() const {
    return taxed_;
  }
  double Product::cost() const {
    double num;
    if (taxed_ == false) {
      num = price_;
    }
    else {
      num = price_ + (price_ * TAX);
    }
    return num;
  }
  bool Product::isEmpty() const {
    return (sku_[0] == 0 && name_ == nullptr && price_ == 0 && taxed_ == 0
      && quantity_ == 0 && qtyNeeded_ == 0);
  }
  bool Product::operator==(const char* C) {
    return !strcmp(sku_, C);
  }
  int Product::operator+=(int qty) {
    return quantity_ += qty;
  }
  int Product::operator-=(int qty) {
    return quantity_ -= qty;
  }
  double& operator+=(double& num, const Product& P) {
    num += (P.cost() * P.quantity());
    return num;
  }
  std::ostream& operator<<(std::ostream& ostr, const Product& P) {
    return P.write(ostr, P.isEmpty());
  }
  std::istream& operator>>(std::istream& istr, Product& P) {
    return P.read(istr);
  }
  Product::~Product() {
    delete[] name_;
    name_ = nullptr;
  }
}