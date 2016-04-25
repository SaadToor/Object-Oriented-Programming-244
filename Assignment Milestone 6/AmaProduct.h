// Final Project Milestone 5
// Student error handling tester program
// Version 1.0
// Date	4/1/2016
// Author	Saad Toor
/////////////////////////////////////////////////////////////////

#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include <fstream>
#include "Streamable.h"
#include "ErrorMessage.h"
#include "Product.h"
namespace sict{
  class AmaProduct : public Product{
  private:
    char fileTag_;
    char unit_[11];
  protected:
    ErrorMessage err_;
  public:
    AmaProduct(char fTag = 'N');
    const char* unit()const;
    void unit(const char* value);
    std::fstream& store(std::fstream& file, bool addNewLine = true)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& istr);
  };

}
#endif


