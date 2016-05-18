/* Forward_list_test.cpp
 * 
 * Unit test for Forward_list.h
 *
 * Andrew DeOrio <awdeorio@umich.edu>
 */

#include "Forward_list.h"
#include "util.h" //add()
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  Forward_list<int> l1;
  assert(l1.empty());

  l1.push_front(3);
  assert(l1.front() == 3);
  assert(!l1.empty());

  l1.push_front(2);
  assert(l1.front() == 2);
  assert(!l1.empty());

  l1.push_front(1);
  assert(l1.front() == 1);
  assert(!l1.empty());

  Forward_list<int> l2 = l1;
  for (auto i=l1.begin(), j=l2.begin(); i != l1.end(); ++i, ++j) {
    assert(*i == *j);
  }

  l2.pop_front();
  assert(l2.front() == 2);
  assert(l1.front() == 1);

  l2.pop_front();
  assert(l2.front() == 3);
  assert(l1.front() == 1);
  
  l2.pop_front();
  assert(l2.empty());
  assert(l1.front() == 1);

  cout << "Forward_list_test PASSED\n";
}
