// final project milestone 5
// amaproduct tester program
// version 1.0
// date 2016-03-23
// author fardad soleimanloo
//
// revision history
// -----------------------------------------------------------
// name               date                 reason
//
/////////////////////////////////////////////////////////////
#include "amaproduct.h"
using namespace sict;
using namespace std;
void piv(const char* sku, const char* name, const char* unit = "", char tx = '\0',
	const char* price = "", const char* qty = "", const char* qtynd = "",
	const char* date = "") {
	cout
		<< "enter the following: " << endl
		<< "sku: " << sku << endl
		<< "name: " << name << endl
		<< "unit: " << unit << endl;
	if (tx) cout << "taxed: " << tx << endl;
	if (price[0]) cout << "price: " << price << endl;
	if (qty[0]) cout << "quantity on hand: " << qty << endl;
	if (qtynd[0]) cout << "quantity needed: " << qtynd << endl;
	if (date[0]) cout << "expiry date: " << date << endl;
	cout << endl;
}
void dumpfile(const char* fname) {
	ifstream f(fname);
	char ch;
	while (!f.get(ch).fail()) {
		cout.put(ch);
	}
	f.clear();
	f.close();
}
void _pause() {
	cout << "****press enter to continue...";
	cin.ignore(1000, '\n');
}

int main() {
	fstream prdfile("amaprd.txt", ios::out);
  AmaProduct amaprd;
	bool ok = true;
	int i;
	cout << "--amaproduct test:" << endl;
	cout << "----taxed validation test:" << endl;
	piv("abc", "abc", "abc", 'a');
	cin >> amaprd;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(2000, '\n');
		cout << "passed!" << endl
			<< "message shoule be:  only (y)es or (n)o are acceptable" << endl
			<< "your error message: " << amaprd << endl;
	}
	else {
		ok = false;
		cout << "taxed validation failed" << endl;
	}
	_pause();
	if (ok) {
		cout << "----price validation test:" << endl;
		piv("abc", "abc", "abc", 'y', "abc");
		cin >> amaprd;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "passed!" << endl
				<< "message shoule be:  invalid price entry" << endl
				<< "your error message: " << amaprd << endl;
		}
		else {
			ok = false;
			cout << "price validation failed" << endl;
		}
		_pause();
	}
	if (ok) {
		cout << "----quantity validation test:" << endl;
		piv("abc", "abc", "abc", 'y', "10", "abc");
		cin >> amaprd;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "passed!" << endl
				<< "message shoule be:  invalid quantity entry" << endl
				<< "your error message: " << amaprd << endl;
		}
		else {
			ok = false;
			cout << "quantity validaton failed" << endl;
		}
	}
	_pause();
	if (ok) {
		cout << "----quantity needed validation test:" << endl;
		piv("abc", "abc", "abc", 'y', "10", "10", "abc");
		cin >> amaprd;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "passed!" << endl
				<< "message shoule be:  invalid quantity needed entry" << endl
				<< "your error message: " << amaprd << endl;
		}
		else {
			ok = false;
			cout << "quantity needed validaton failed" << endl;
		}
	}
	_pause();
	if (ok) {
		cout << "----display test, the output of the program and yours must match:" << endl;
		piv("1234", "box", "kg", 'y', "123.45", "1", "5");
		cin >> amaprd;
		cin.ignore(1000, '\n');
		cout << "--linear------------" << endl;
		cout << "program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
		cout << "  yours: " << amaprd << endl;
		cout << "--form display------" << endl;
		cout << "--program: " << endl;
		cout << "sku: 1234" << endl;
		cout << "name : box" << endl;
		cout << "price : 123.45" << endl;
		cout << "price after tax : 139.50" << endl;
		cout << "quantity on hand : 1 kgs" << endl;
		cout << "quantity needed : 5" << endl;
		cout << "--yours: " << endl;
		amaprd.write(cout, false) << endl;
	}
	_pause();
	
	if (ok) {
		cout << "----storage and loading test, the output of the program and yours must match:" << endl;
		AmaProduct tprd;
		amaprd.store(prdfile);
		amaprd.store(prdfile);
		prdfile.close();
		cout << "--store amaproduct, program: " << endl
			<< "n,1234,box,123.45,1,1,kg,5" << endl
			<< "n,1234,box,123.45,1,1,kg,5" << endl;
		cout << "--store amaproduct, yours: " << endl;
		dumpfile("amaprd.txt");
		cout << "--load amaproduct: " << endl;
		prdfile.open("amaprd.txt", ios::in);
		prdfile.ignore(2);
		tprd.load(prdfile);
		cout << "program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
		cout << "  yours: " << tprd << endl;
		prdfile.clear();
		prdfile.close();
	}
	return 0;
}