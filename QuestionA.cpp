#include <iostream>
#include <vector>
using namespace std;

void testSolution();

// Q1 Solution 
bool linesOverlap (vector<int> &l1, vector<int> &l2) {
  // only accept valid lines 
  if(l1.size()!= 2 || l2.size() != 2) return false;
  // return true unless (end of l1 doesn't overlap with
  // beginning of l2 or vice versa)
  return !(l1[1] < l2[0] || l2[1] < l1[0]);
}

int main() {
  testSolution();
  return 0;
}

void testSolution () {
  vector<int> l1 {1, 5};
  vector<int> invalidLine{0};
  vector<int> noOverlapL2 {6, 8};
  vector<int> overLapL2 {2, 6};
  bool test0 = !linesOverlap(l1, invalidLine);
  bool test1 = !linesOverlap(l1, noOverlapL2);
  bool test2 = linesOverlap(l1, overLapL2);
  bool test3 = linesOverlap(l1, l1);
  if((test0 && test1) &&(test2 && test3)) cout << "all tests passed" << endl;
  else cout << "one or more tests failed" << endl;
}
