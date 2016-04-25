//04/23/2016
#include <iostream>
#include "AidApp.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Product.h"
#include "Streamable.h"
#include "Date.h"
#include "general.h"
#include <iomanip>
#include <cstring>
using namespace std;
namespace sict {
	AidApp::AidApp(const char* filename) {
		strcpy(filename_, filename);
		int i;
		for (i = 0; i < MAX_NO_RECS; i++) {
			product_[i] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}
	void AidApp::pause() const {
		cout << "Press Enter to continue..." << endl;
		cin.ignore(2000, '\n');
	}
	int AidApp::menu() {
		int choice;
		cout << "Disaster Aid Supply Management Program" << endl
			<< "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "0- Exit program" << endl 
			<< "> ";
		cin >> choice;
		if (choice < 0 || choice > 5) {
			choice = -1;
		}
		cin.clear();
		cout << endl;
		cin.ignore(2000, '\n');
		return choice;
	}
	void AidApp::loadRecs() {

		int readIndex;
		readIndex = 0;
		char id;
		id = '\0';


		datafile_.open(filename_, ios::in);

		if (datafile_.fail() == true) {
			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, ios::out);
			datafile_.close();
		}
		else if (datafile_.fail() == false) {
			while (!datafile_.fail()) {
				if (!product_[readIndex]) {
					delete[] product_[readIndex];
					product_[readIndex] = nullptr;
				}
				id = datafile_.get();

				if (id == 'P') {
					product_[readIndex] = new AmaPerishable;
				}
				else if (id == 'N') {
					product_[readIndex] = new AmaProduct;
				}
				if (id == 'P' || id == 'N' || product_[readIndex] != nullptr) {
					datafile_.ignore(2000, ',');
					product_[readIndex]->load(datafile_);
					readIndex++;
				}
			}
			noOfProducts_ = readIndex;
		}
		datafile_.close();

	}

	void AidApp::saveRecs() {
		int i;
		datafile_.open(filename_, ios::out);
		for (i = 0; i <= noOfProducts_; i++) {
			product_[i]->store(datafile_);
		}
		datafile_.close();
	}
	void AidApp::listProducts() const {
		int i;
		int rows;
		rows = 1;
		double total;
		total = 0;
		cout << left << " Row |" << " SKU    |" << " Product Name       |" << " Cost  |" << " QTY|" << " Unit     |" << "Need|" << " Expiry   " << endl
			<< setw(5) << setfill('-') << "" << "|" << setw(8) << setfill('-') << "" << "|" << setw(20) << setfill('-') << "" << "|"
			<< setw(7) << setfill('-') << "" << "|" << setw(4) << setfill('-') << "" << "|" << setw(10) << setfill('-') << "" << "|"
			<< setw(4) << setfill('-') << "" << "|" << setw(10) << setfill('-') << "" << endl;
		for (i = 0; i < noOfProducts_; i++) {
			cout << right << setfill(' ') << setw(4) << rows++ << " | " << *product_[i] << endl;
			if (i == 9) {
				pause();
			}
			total += product_[i]->cost() * product_[i]->quantity();
		}
		cout << setw(75) << setfill('-') << "" << endl
			<< fixed << setprecision(2) << "Total cost of support: $" << total << endl << endl;
	}
	int AidApp::SearchProducts(const char * sku) const {
		int i;
		int index;
		index = -1;
		for (i = 0; i < noOfProducts_; i++) {
			if (product_[i]->operator==(sku)) {
				index = i;
				break;
			}
		}
		return index;
	}
	void AidApp::addQty(const char * sku) {
		int qty;
		int index;
		index = SearchProducts(sku);
		int need;
		if (index != -1) {
			product_[SearchProducts(sku)]->write(cout, false);
			cout << endl << endl << "Please enter the number of purchased items: ";
			cin >> qty;
			if (cin.fail()) {
				cout << "Invalid quantity value" << endl;
			}
			else {
				need = product_[SearchProducts(sku)]->qtyNeeded() - product_[SearchProducts(sku)]->quantity();
				if (qty <= need) {
					product_[SearchProducts(sku)]->quantity(qty + product_[SearchProducts(sku)]->quantity());
					cout << endl << "Updated!" << endl << endl;
				}
				else {
					cout << "Too many items; only " << need << " is needed, please return the extra " << qty - need << " items." << endl;
					cout << endl << "Updated!" << endl << endl;
				}
			}
		}
		else {
			cout << "Not found!" << endl;
		}
	}
	void AidApp::addProduct(bool isPerishable) {
		if (isPerishable) {
			product_[noOfProducts_] = new AmaPerishable();
		}
		else {
			product_[noOfProducts_] = new AmaProduct();
		}
		product_[noOfProducts_]->read(std::cin);
		if (std::cin.fail() == false) {
			saveRecs();
			noOfProducts_++;
		}
		else {
			product_[noOfProducts_]->write(std::cout, true);
		}
		cout << endl << "Product added" << endl << endl;
	}

	int AidApp::run() {
		int choice;
		char sku[MAX_SKU_LEN + 1];
		int index;

		while ((choice = menu()) != 0) {
			switch (choice) {
			case -1:
				cout << "===Invalid choice, try again.===" << endl;
				pause();
				break;
			case 0:
				cout << "Goodbye!!" << endl;
				break;
			case 1:
				listProducts();
				pause();
				break;
			case 2:
				cout << "Please enter the SKU: ";
				cin >> sku;
				cout << endl;
				index = SearchProducts(sku);

				if (index == -1) {
					cout << "Not found!" << endl;
				}
				else {
					product_[index]->write(cout, false);
					cout << endl << endl;
				}
				cin.ignore(1000, '\n');
				pause();
				break;
			case 3:
				addProduct(false);
				loadRecs();
				break;
			case 4:
				addProduct(true);
				loadRecs();
				break;
			case 5:
				cout << "Please enter the SKU: ";
				cin >> sku;
				cout << endl;
				addQty(sku);
				break;
			}
		}
		cout << "Goodbye!!" << endl;
		return 0;
	}
}
