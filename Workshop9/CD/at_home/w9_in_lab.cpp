#include <istream>
#include "Transcript.h"
using namespace std;
using namespace sict;

int main(){
  Transcript T("John Doe", "042942088");
  T += Subject("Introduction to Object Oriented Programming", "OOP244", 40, 60);
  T += Subject("College English", "EAC150", 75, 100);
  T += Subject("iSERIES Business Computing", "IBC233", 80, 100);
  T += Subject("Internet I - Internet Fundamentals", "INT222", 30, 40);
  T += Subject("Introduction to Database Design and SQL", "DBS201",60, 100);
  cout << T << endl;
  Subject min, max;
  max = min = T[0];
  for (int i = 1; i < T.noOfSubjects(); i++){
    if (T[i].mark() < min.mark()) min = T[i];
    if (T[i].mark() > max.mark()) max = T[i];
  }
  cout << "Best mark was in " << (const char*)max << endl << max << endl;
  cout << "Worst mark was in " << (const char*)min << endl << min << endl;


  return 0;
}