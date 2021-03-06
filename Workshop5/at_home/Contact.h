//Saad Toor
//068964139
//02/17/2016

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include "PhoneNumber.h"
namespace sict{
	class Contact{
		char name_[41];
		PhoneNumber* phoneNumber_;
		int _noPN;
		void setEmpty();
	public:

		void read();
		void display()const;
		bool isEmpty()const;

    Contact& operator=(const Contact& c);

		Contact();
		Contact(const char* name, int phNum);
    Contact(const Contact& c);
		~Contact();


	};
}

#endif
