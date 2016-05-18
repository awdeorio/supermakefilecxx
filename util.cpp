/* util.h
 *
 * Example of a support file that may be needed by both the main application
 * and unit tests.
 *
 * Andrew DeOrio <awdeorio@umich.ed>
 */

#include "util.h"

int sum(Forward_list<int> l) {
  int result = 0;
  for (auto i:l) result += i;
  return result;
}
