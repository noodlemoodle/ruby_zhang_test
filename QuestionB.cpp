#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

bool strtof(string s, float &val);
void testSolution();

// returns : 
//    1 : s1 > s2 
//    0 : s1 == s2 
//   -1 : s1 < s2
int compareStrings(string s1, string s2) {
  float n1, n2;
  int compare;
  if(strtof(s1, n1) && strtof(s2, n2)) {
    compare = n1 < n2 ? -1 : (n1 == n2 ? 0 : 1);
    return compare;
  } else throw "non-numeric strings given";
}

int main() {
  
  testSolution();

  return 0;
}

void testSolution() {
  string s1 = "-000123.5";
  string emptyS2 = "";
  string invalidS2 = "-.";
  string eqS2 = "-123.5";
  string ltS2 = "-1235";
  string gtS2 = "-0.1235";
  bool test1 = false, test2 = false;
  try {compareStrings(s1, emptyS2);}
  catch(char const* e) {test1 = true;}
  try {compareStrings(s1, invalidS2);}
  catch(char const* e) {test2 = true;}
  bool test3 = compareStrings(s1, eqS2) == 0; 
  bool test4 = compareStrings(s1, ltS2) == 1;
  bool test5 = compareStrings(s1, gtS2) == -1;
  if(test1 && test2 && test3 && test4 && test5) cout << "all tests passed" << endl;
}

// helper function for converting string to numeric
// returns true iff s can be converted to a numeric value
// and store the value of s in arg val
bool strtof(string s, float &val) {
  // base cases
  if(s.size() == 0) return false;
  val = 0;
  int sign = 1, decimal = 0, numeric = 0;
  for(auto &c : s) {
    if(c == '-') {
      if(val == 0&&decimal == 0) sign = -1;
      else return false;
    } 
    else if (c == '.') decimal = 1;
    else if (isdigit(c)) {
      numeric = 1;
      if(decimal > 0) val += (pow(0.1, decimal++) * ((float)c-48));
      else val = (val == 0) ? (float) c - 48 : val * 10 + ((float)c - 48);
    } 
    else return false;
  }
  if(val == 0 && !numeric) return false;
  val *= sign;
  return true;
}
