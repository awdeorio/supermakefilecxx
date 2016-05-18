/* main.cpp
 *
 * Output is the sum of inputs
 *
 * Andrew DeOrio <awdeorio@umich.ed>
 *
 * Example:
 * ./main
 * 1
 * 2
 * 3
 * <Control-D>
 * 6
 */

#include "Forward_list.h"
#include "util.h" //sum()
#include <iostream>
using namespace std;

int main() {

  // Read inputs into a list.  It is unecessary, but the point is to
  // demonstrate an application that uses libraries and inputs.
  int n;
  Forward_list<int> inputs;
  while (cin >> n) {
    inputs.push_front(n);
  }

  // Compute sum using function from util.h
  int result = sum(inputs);
  cout << result << "\n";

  return 0;
}
