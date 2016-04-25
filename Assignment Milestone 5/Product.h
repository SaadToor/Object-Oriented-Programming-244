// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include <iostream>
#include "general.h"
#include "Streamable.h"
namespace sict {
	class Product :public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Product();
		Product(char* sku, char* name, double price, int quantity, bool tax = true);
		Product(const char* sku, const char* name);
		Product(const Product& P);
		Product& operator=(const Product& P);

		void sku(const char* s);
		void name(const char* n);
		void price(double p);
		void quantity(int q);
		void qtyNeeded(int qN);
		void taxed(bool t);

		const char* sku() const;
		const char* name() const;
		double price() const;
		int quantity() const;
		int qtyNeeded() const;
		bool taxed() const;
		double cost() const;
		bool isEmpty() const;

		bool operator==(const char* C);
		int operator+=(int qty);
		int operator-=(int qty);

		virtual ~Product();
	};
	double& operator+=(double& num, const Product& P);
	std::ostream& operator<<(std::ostream& ostr, const Product& P);
	std::istream& operator>>(std::istream& istr, Product& P);
}
#endif