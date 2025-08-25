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
//// Optional: Add this line before including the header 
//// if you want to exit the test on a failed assertion.
// TEST_EXIT_ON_FAILURE

// Include the header
#include <test.h>

// Initialize global variables
TEST_INIT;

int main(void) {


    return 0;
}
```
