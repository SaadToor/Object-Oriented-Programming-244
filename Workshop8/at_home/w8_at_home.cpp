#include <iostream>
#include "String.h";

using namespace std;
using namespace sict;

void display(String& S){
  cout << "->" << S << "<- len: " << S.length() << ", mem: " << S.memSize() << endl;
}

int main(){
  String name("fardad", 10);
  String lastname("soley", 5);
  name += lastname;
  display(name);
  name.resize(7);
  display(name);
  cin >> name;
  display(name);
  return 0;
}