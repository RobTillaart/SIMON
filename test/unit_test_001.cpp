//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2022-05-26
// PURPOSE: unit tests for SIMON
//          https://github.com/RobTillaart/SIMON
//


// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "simon.h"


unittest_setup()
{
  fprintf(stderr, "SIMON_LIB_VERSION: %s\n", (char *) SIMON_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  SIMON simon();

  assertEqual(0, simon.count());
  assertEqual(0, simon.size());
  assertTrue(simon.verify());
}


unittest(test_setSequence)
{
  uint8_t seq[7] = { 0, 1, 2, 3, 4, 5, 6 };

  SIMON simon();
  assertEqual(0, simon.size());
  for (int i = 0; i < 8; i++)
  {
    assertTrue(simon.setSequence(seq, i));
    assertEqual(i, simon.size());
  }

  assertFalse(simon.setSequence(seq, 12));
  assertFalse(simon.setSequence(NULL, 5));
}


unittest(test_add_OK)
{
  uint8_t seq[7] = { 0, 1, 2, 3, 4, 5, 6 };

  SIMON simon();

  assertTrue(simon.setSequence(seq, 7));
  for (int i = 0; i < 7; i++)
  {
    simon.add(1);
    assertEqual(i, simon.count());
  }
  assertTrue(simon.verify());
}


unittest(test_add_FAIL)
{
  uint8_t seq[7] = { 0, 1, 2, 3, 4, 5, 6 };

  SIMON simon();

  assertTrue(simon.setSequence(seq, 7));
  for (int i = 0; i < 7; i++)
  {
    simon.add(1);
    assertEqual(i, simon.count());
    assertFalse(simon.verify());
  }
  assertTrue(simon.verify());
}




unittest_main()

// --------
