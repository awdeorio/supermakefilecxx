/* util_test.cpp
 * 
 * Unit test for util.h
 *
 * Andrew DeOrio <awdeorio@umich.edu>
 */

#include "util.h"
#include "Forward_list.h"
#include <iostream>
#include <cassert>
using namespace std;


int main() {
  Forward_list<int> l;
  l.push_front(1);
  l.push_front(2);
  l.push_front(3);
  int result = sum(l);
  assert(result == 6);
  cout << "util_test PASSED\n";
  return 0;
}
