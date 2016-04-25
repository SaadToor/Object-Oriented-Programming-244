#include <iostream>
using namespace std;
#include "Subject.h"
using namespace sict;
int main(){
  Subject U("EAC150", "College English", 85);
  Subject T("IPC144", "Intro to porgramming", 70);
  cout << (const char*)T <<endl << T << endl 
    << (const char*)U << endl << U << endl;
  T = U;
  cout << "============================" << endl;
  cout << (const char*)T << endl << T << endl
    << (const char*)U << endl << U << endl;
  return 0;
}