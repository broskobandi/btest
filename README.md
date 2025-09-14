# test
A simple test utility for your C projects.

## Features
- Custom ASSERT macro to test conditions.
- Easily readable colour coded test results.

## Installation
```bash
git clone git@github.com:broskobandi/test.git &&
cd test &&
sudo make install
```

## Uninstallation
```bash
cd test &&
sudo make uninstall
```

## Usage
```c
/*Optional: Add this line before including the header
 * if you want to exit the test on a failed assertion. */
/* TEST_EXIT_ON_FAILURE */

/* Include the header. */
#include <test.h>

/* Initialize global variables. */
TEST_INIT;

/* Example function to test. */
int divide(int dividend, int divisor, float *quotient) {
    if (divisor == 0) return 1;
    *quotient = (float)((float)dividend / (float)divisor);
    return 0;
}

int main(void) {
    /* Normal case. */
    float quotient = 0;
    ASSERT(divide(10, 2, &quotient) == 0);
    ASSERT(quotient == 5.0f);

    /* Edge case. */
    quotient = 0;
    ASSERT(divide(10, 0, &quotient) == 1);
    ASSERT(quotient == 0.0f);

    /* Print the results. */
    test_print_results();
    return 0;
}
```
