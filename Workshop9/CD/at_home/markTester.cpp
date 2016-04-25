#include <iostream>
using namespace std;
#include "Mark.h"
using namespace sict;
const double pi = 3.14159265;
#define PI 3.14159265
void displayMark(Mark& rM){
  int dt = rM.displayType();
  cout << rM << " is ";
  rM.displayType(DSP_MARK);
  cout << rM << "% that is ";
  rM.displayType(DSP_GRADE);
  cout << rM << endl;
  rM.displayType(DSP_GPA);
  cout << "In gpa format it is " << rM << endl;
  rM.displayType(dt);
}
int main(){
  Mark M;
  Mark M2(4, 100);
  Mark M3(1, 2);
  int mark;
  double dmark;
  M.outOf(60);
  M = 40;
  mark = M;
  dmark = M;
  cout << M << endl;
  cout << "the mark is " << mark << " or " << dmark << endl;
  displayMark(M);
  M += M2;
  cout << M << endl;
  M3 /= 2;
  cout << M3 << endl;
  return 0;
}