//04/23/2016
#ifndef SICT_AID_APP_H
#define SICT_AID_APP_H
#include "general.h"
#include "Product.h"
namespace sict {
  class AidApp {
    char filename_[256];
    Product* product_[MAX_NO_RECS];
    std::fstream datafile_;
    int noOfProducts_;

    void pause()const;
    void loadRecs();
    void saveRecs();
    void listProducts()const;
    int SearchProducts(const char* sku)const;
    void addQty(const char* sku);
    void addProduct(bool isPerishable);
	int menu();
  public:
    AidApp(const char* filename);
    int run();
  };
}
#endif
